//
//  DDXMLBinding.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/2.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef DDXMLBinding_hpp
#define DDXMLBinding_hpp

#include <stdio.h>
#include <string>
#include <DDSL-Libs/DDSL-Libs.h>
#include <DDSL-Antlr/DDSL-Antlr.h>
#include <DDSL-Script/DDSL-Script.h>
#include <DDSL-Runtime/DDSL-Runtime.h>

using namespace std;
using namespace json11;
namespace DDSL {
    /// 对XML文件进行动态绑定转换
    class DDXMLBinding {
    private:
        const char *xmlFilePath;
        /// 外部注入的JSON数据
        Json jsonObject;
        /// 临时变量
        map<string, shared_ptr<DDSL::SemaASTNodeObject>> variable;
    private:
        /// 数据动态绑定完之后的结果
        shared_ptr<tinyxml2::XMLDocument> result;
    private:
        /// 计算表达式结果,获取表达式结果
        string callExpr(string code, map<string, shared_ptr<DDSL::SemaASTNodeObject>> vari);
        /// 将source中的内容替换成执行完表达式后的结果
        void replaceXMLAttribute(string &source, map<string, shared_ptr<DDSL::SemaASTNodeObject>> vari);
        /// 处理For语句(展开for)
        void handleFORStmt(tinyxml2::XMLElement *rootElement);
        /// 处理If语句
        void handleIFStmt(tinyxml2::XMLElement *rootElement);
        /// 动态绑定替换当前给定的节点
        void replaceElement(tinyxml2::XMLElement *element, map<string, shared_ptr<DDSL::SemaASTNodeObject>> vari);
        /// 动态绑定替换兄弟节点与子节点
        void replaceAllElement(tinyxml2::XMLElement *rootElement, map<string, shared_ptr<DDSL::SemaASTNodeObject>> vari);
    public:
        tinyxml2::XMLDocument *GetDoc() { return result.get(); }
        DDXMLBinding(const char *path,
                       Json &o,
                       map<string, shared_ptr<DDSL::SemaASTNodeObject>> variable) {
            this->xmlFilePath = path;
            this->jsonObject = o;
            this->variable = variable;
            this->result = make_shared<tinyxml2::XMLDocument>();
        }
    public:
        /// 加载并动态绑定
        void BindingXML();
    };

}
#endif /* DDXMLBinding_hpp */
