//
//  SemaASTNodeObject.h
//  AntlrDemo
//
//  Created by mark on 2020/7/1.
//  Copyright © 2020 mark. All rights reserved.
//

#ifndef semantic_defins_h
#define semantic_defins_h

#include <string>
#include <any>
#include <iostream>
#include <DDSL-Libs/DDSL-Libs.h>
#include <DDSL-Script/DDSL-Script.h>

using namespace std;
using namespace antlr4;
using namespace json11;


namespace DDSL {
    enum Type { String, Number, Bool, Object, None };
    enum SubType { S_Object, S_ASTNodeObject };
    struct SemaASTNodeObject {
    private:
        any value;
        Type type = None;
        SubType subType;
    private:
        void initializeType() {
            string clsName = this->value.type().name();
            if(clsName == "i" || clsName == "d") this->type = Number;
            else if(clsName.find("string") != string::npos) this->type = String;
            else if(clsName == "b") this->type = Bool;
            else if(clsName.find("DDObject") != string::npos) {
                this->type = Object;
                this->subType = S_Object;
            }
            else if(clsName.find("SemaASTNodeObject") != string::npos) {
                this->type = Object;
                this->subType = S_ASTNodeObject;
            }
            else if(clsName == "v") this->type = None;
            else this->type = None;
        }
    public:
        SemaASTNodeObject() {
            
        }
        SemaASTNodeObject(const char *s) {
            this->value = string(s);
            initializeType();
        }
        SemaASTNodeObject(any value) {
            this->value = value;
            initializeType();
        }
        ~SemaASTNodeObject() { }
    public:
        const Type getType();
        const string getTypeText();
        any getRawValue() { return this->value; }
        void setValue(any v) {
            this->value = v;
            initializeType();
        }
        /// 获取数据的字符串描述
        const string getText();
    public:
        template <typename T>
        T getValue() { return any_cast<T>(this->value); }
        bool isEmpty() { return !value.has_value(); }
        static shared_ptr<SemaASTNodeObject> empty() { return make_shared<SemaASTNodeObject>(); }
    };
}
 

#endif /* semantic_defins_h */
