//
//  DDXMLBinding.cpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/2.
//  Copyright © 2020 坏人. All rights reserved.
//

#include "DDXMLBinding.h"
#include <regex>
#include <DDSL-Runtime/DDSL-Runtime.h>
#include <DDSL-Script/DDSL-Script.h>
#include "Compiler.h"
#include "DDIR.h"

using namespace tinyxml2;
using namespace std;
using namespace antlr4;


/// 执行基础表达式,得到结果
string DDSL::DDXMLBinding::callExpr(string code, map<string, shared_ptr<DDSL::SemaASTNodeObject>> vari) {
    auto tmpVari = vari.size() > 0 ? vari : variable;
    string err;
    auto irs = Json::parse(code, err);
    auto complier = DDSL::Complier(irs, jsonObject, tmpVari );
    auto frame = complier.compile();
    if(frame.valid()) {
        frame.run();
        auto obj = frame.getResult();
        return obj->getText();
    } else {
        cout << "[Error] " << frame.getErrorMsg() << endl;
        return "";
    }
}

/// 将匹配到的表达式全部计算并替换成最终结果
void DDSL::DDXMLBinding::replaceXMLAttribute(string &source, map<string, shared_ptr<DDSL::SemaASTNodeObject>> vari) {
    auto tmpVari = vari.size() > 0 ? vari : variable;
    regex reg("\\{\\{.+?\\}\\}");
    std::vector<string> replaces;
    std::vector<string> news;
    for(auto i = std::sregex_iterator(source.begin(), source.end(), reg); i != std::sregex_iterator(); ++i) {
        std::smatch m = *i;
        auto match_s = m.str();
        auto expr_s = match_s;
        if(expr_s.length() > 0) {
            expr_s = Script::DDExprHelper::ExtractExpr(expr_s);
            string expr_r = callExpr(base64_decode(expr_s), tmpVari);
            replaces.push_back(match_s);
            news.push_back(expr_r);
        }
    }
    for(int i = 0; i < replaces.size(); i ++) {
        string m = replaces.at(i);
        string n = news.at(i);
        size_t pos = source.find(m);
        if(pos != string::npos && n.length() > 0/*获取到对应的才替换*/) {
            source.replace(pos, m.length(), n);
        }
    }
}
void DDSL::DDXMLBinding::handleFORStmt(tinyxml2::XMLElement *rootElement) {
    auto siblingElement = rootElement;
    while(siblingElement) {
        cout << siblingElement->Name() << endl;
        auto currentElement = siblingElement;
        /// 指向下一个兄弟节点
        siblingElement = siblingElement->NextSiblingElement();
        /// 遍历子节点
        if(!(currentElement->NoChildren())) {
           handleFORStmt(currentElement->FirstChildElement());
        }
        vector<shared_ptr<SemaASTNodeObject>> items;
        string itemKey;
        auto attribute = currentElement->FirstAttribute();
        while(attribute) {
            if(attribute->Name() == string("for")) {
                /// 获取到For语句字符串值
                auto forExpr = attribute->Value();
                if(Script::DDExprHelper::IsExprValid(forExpr)) {
                    auto code = Script::DDExprHelper::ExtractExpr(forExpr);
                    string err;
                    code = base64_decode(code);
                    auto o = Json::parse(code, err);
                    auto cp = Complier(o, jsonObject, variable);
                    auto result = cp.compileForStmt();
                    result.run();
                    items = result.getResult();
                    itemKey = result.getItemKey();
                }
                /// 只需要解析到一个for就跳出这个循环,不再遍历接下来的属性了
                break;
            }
            attribute = attribute->Next();
        }
        if(items.size() > 0) {
            /// 删除当前节点,再通过items生成一组节点插入到当前位置
            auto parent = currentElement->Parent();
            if(parent) {
                for(auto item : items) {
                    XMLElement *tmpElement = (XMLElement *)currentElement->DeepClone(this->result.get());
                    tmpElement->DeleteAttribute("for");
                    parent->InsertAfterChild(currentElement, tmpElement);
                    map<string, shared_ptr<DDSL::SemaASTNodeObject>> tmpVari;
//                    tmpVari.insert(variable.begin(), variable.end());
                    tmpVari[itemKey] = item;
                    /// 动态绑定当前创建节点的数据,这里只注入了for生成的临时变量,这意味着这里的替换只消解与for有关的信息
                    replaceAllElement(tmpElement, tmpVari);
                }
                parent->DeleteChild(currentElement);
            }
        }
    }
}
void DDSL::DDXMLBinding::handleIFStmt(tinyxml2::XMLElement *rootElement) {
    auto siblingElement = rootElement;
    while(siblingElement) {
        cout << siblingElement->Name() << endl;
        auto currentElement = siblingElement;
        /// 指向下一个兄弟节点
        siblingElement = siblingElement->NextSiblingElement();
        /// 遍历子节点
        if(!(currentElement->NoChildren())) {
           handleIFStmt(currentElement->FirstChildElement());
        }
        bool visiable = true;
        auto attribute = currentElement->FirstAttribute();
        while(attribute) {
            if(attribute->Name() == string("if")) {
                /// 获取到For语句字符串值
                auto ifExpr = attribute->Value();
                if(Script::DDExprHelper::IsExprValid(ifExpr)) {
                    string err;
                    auto code = Script::DDExprHelper::ExtractExpr(ifExpr);
                    code = base64_decode(code);
                    auto o = Json::parse(code, err);
                    auto cp = Complier(o, jsonObject, variable);
                    auto frame = cp.compile();
                    frame.run();
                    auto result = frame.getResult();
                    if(result->getType() == DDSL::Bool) {
                        visiable = getBool(result);
                    } else {
                        /// 如果表达式的结果不是一个bool,则删除该节点
                        visiable = false;
                    }
                } else if(ifExpr == string("true")) {
                    /// for 消解的时候可能已经将if表达式的信息处理了
                    visiable = true;
                } else if(ifExpr == string("false")) {
                    visiable = false;
                } else {
                    visiable = false;
                }
                /// 只需要解析到一个if就跳出这个循环,不再遍历接下来的属性了
                break;
            }
            attribute = attribute->Next();
        }
        currentElement->DeleteAttribute("if");
        if(!visiable) {
            auto parent = currentElement->Parent();
            parent->DeleteChild(currentElement);
        }
        
    }
}
void DDSL::DDXMLBinding::replaceElement(tinyxml2::XMLElement *element, map<string, shared_ptr<DDSL::SemaASTNodeObject>> vari) {
    auto attribute = element->FirstAttribute();
    while (attribute) {
        string value = attribute->Value();
        string key = attribute->Name();
        attribute = attribute->Next();
        replaceXMLAttribute(value, vari);
        element->SetAttribute(key.c_str(), value.c_str());
    }
}
void DDSL::DDXMLBinding::replaceAllElement(tinyxml2::XMLElement *element,
                                                       map<string, shared_ptr<DDSL::SemaASTNodeObject>> vari) {
    auto siblingElement = element;
    /// 遍历完子节点再遍历兄弟节点
    while (siblingElement) {
        /// 有子节点,首先展开遍历子节点
        if(!siblingElement->NoChildren()) {
            replaceAllElement(element->FirstChildElement(), vari);
        }
        replaceElement(siblingElement, vari);
        siblingElement = siblingElement->NextSiblingElement();
    }
}
/// 加载并动态替换XML中的内容
void DDSL::DDXMLBinding::BindingXML() {
    if(!xmlFilePath) return;
    auto xml_error = this->result->LoadFile(xmlFilePath);
    if(xml_error != tinyxml2::XMLError::XML_SUCCESS) {
        printf("XML解析失败: %d", xml_error);
        return;
    }
    auto rootElement = result->RootElement();
    handleFORStmt(rootElement);
    /// for可能产生临时变量,所以if在for之后进行消解
    handleIFStmt(rootElement);
    replaceAllElement( result->RootElement(), variable);
}

