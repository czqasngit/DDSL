//
//  DDIR.cpp
//  DDSL-IR
//
//  Created by youxiaobin on 2020/7/21.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#include "DDIR.h"
#include <regex>
#include <DDSL-Script/DDSL-Script.h>
#include "IRCompiler.h"
#include <DDSL-Libs/DDSL-Libs.h>

using namespace DDSL;
using namespace std;

void DDIR::Setup() {
    auto rootElement = this->doc.RootElement();
    if(!rootElement) return;
    if(rootElement->Name() != string("View")) return;
    XMLElementIRConvertEntry(rootElement);
    cout << "DDIR 完成编译" << endl;
}
/// 循环遍历节点
void DDIR::XMLElementIRConvertEntry(XMLElement *element) {
    auto siblingElement = element;
    /// 遍历完子节点再遍历兄弟节点
    while (siblingElement) {
        /// 有子节点,首先展开遍历子节点
        if(!siblingElement->NoChildren()) {
            XMLElementIRConvertEntry(siblingElement->FirstChildElement());
        }
        XMLElementExprToIR(siblingElement);
        siblingElement = siblingElement->NextSiblingElement();
    }
}
/// 将节点属性中的表达式转化成IR
void DDIR::XMLElementExprToIR(XMLElement *element) {
    cout << element->Name() << endl;
    auto attribute = element->FirstAttribute();
    while (attribute) {
        string value = attribute->Value();
        string key = attribute->Name();
        /// 提取{{}}的正则表达式
        if(key == string("for")) {
            if(Script::DDExprHelper::IsExprValid(value)) {
                auto code = Script::DDExprHelper::ExtractExpr(value);
                auto cp = IRComplier(code);
                auto ir = cp.ObtainFORStmtIR();
                auto o = Json(ir);
                auto ir_result = o.dump();
                if(ir_result.length() > 0) {
                    auto base_s = base64_encode(ir_result);
                    string ir_expr = "{{" + base_s + "}}";
                    element->SetAttribute(key.c_str(), ir_expr.c_str());
                }
            }
        } else {
            regex reg("\\{\\{.+?\\}\\}");
            std::vector<string> news;
            std::vector<string> replaces;
            for(auto i = std::sregex_iterator(value.begin(), value.end(), reg); i != std::sregex_iterator(); ++i) {
                std::smatch m = *i;
                string match_s = m.str();
                if(Script::DDExprHelper::IsExprValid(match_s)) {
                    auto code = Script::DDExprHelper::ExtractExpr(match_s);
                    auto cp = IRComplier(code);
                    auto irs = cp.ObtainXMLIR();
                    auto o = Json(irs);
                    auto ir_result = o.dump();
                    replaces.push_back(match_s);
                    news.push_back("{{" + base64_encode(ir_result) + "}}");
                }
            }
            for(int i = 0; i < replaces.size(); i ++) {
                string m = replaces.at(i);
                string n = news.at(i);
                size_t pos = value.find(m);
                if(pos != string::npos && n.length() > 0/*获取到对应的才替换*/) {
                    value.replace(pos, m.length(), n);
                }
            }
            element->SetAttribute(key.c_str(), value.c_str());
        }
        attribute = attribute->Next();
    }
}

string DDIR::ObtainXMLIR() {
    if(!xmlFilePath) return "";
    tinyxml2::XMLDocument doc;
    auto xml_error = doc.LoadFile(xmlFilePath);
    if(xml_error != tinyxml2::XMLError::XML_SUCCESS) {
        printf("XML解析失败: %d", xml_error);
        return "";
    }
    doc.DeepCopy(&(this->doc));
    this->run();
    XMLPrinter printer(0, false);
    this->doc.Print(&printer);
    return printer.CStr();
}
