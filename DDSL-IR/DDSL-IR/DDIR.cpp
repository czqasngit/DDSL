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
#include <DDSL-Compiler/DDSL-Compiler.h>

using namespace DynamicDSL;
using namespace IR;

void DDIR::Setup() {
    auto rootElement = this->doc.RootElement();
    if(!rootElement) return;
    if(rootElement->Name() != string("View")) return;
    
}
/// 循环遍历节点
void DDIR::XMLElementIRConvertEntry(XMLElement *element) {
    auto siblingElement = element;
    /// 遍历完子节点再遍历兄弟节点
    while (siblingElement) {
        /// 有子节点,首先展开遍历子节点
        if(!siblingElement->NoChildren()) {
            XMLElementIRConvertEntry(element->FirstChildElement());
        }
        XMLElementExprToIR(element);
        siblingElement = siblingElement->NextSiblingElement();
    }
}
/// 将节点属性中的表达式转化成IR
void DDIR::XMLElementExprToIR(XMLElement *element) {
    auto attribute = element->FirstAttribute();
    while (attribute) {
        string value = attribute->Value();
        string key = attribute->Name();
        attribute = attribute->Next();

        /// 提取{{}}的正则表达式
        regex reg("\\{\\{.+?\\}\\}");
        std::vector<string> news;
        for(auto i = std::sregex_iterator(value.begin(), value.end(), reg); i != std::sregex_iterator(); ++i) {
            std::smatch m = *i;
            string match_s = m.str();
            if(match_s.length() > 0) {
                string expr_s = Script::DDExprHelper::ExtractExpr(match_s);
//                string expr_r = runExpr(expr_s, tmpVari);
//                news.push_back(expr_r);
                auto cp = Complier(expr_s);
                auto irs = cp.GetIRs();
                
            }
        }
        
        
        element->SetAttribute(key.c_str(), value.c_str());
    }
}

string DDIR::GetIRXMLContent() {
    return "";
}
