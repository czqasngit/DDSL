//
//  Context.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/8.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef FrameContext_hpp
#define FrameContext_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <DDSL-Libs/DDSL-Libs.h>
#include <DDSL-Script/DDSL-Script.h>
#include "SemaASTNodeObject.h"

using namespace std;
using namespace json11;

typedef map<string, shared_ptr<DDSL::SemaASTNodeObject>> DDMap;
typedef double DDNumber;
typedef string DDString;
typedef bool DDBool;
typedef vector<shared_ptr<DDSL::SemaASTNodeObject>> DDArray;


namespace DDSL {
    class DDObject {
    private:
        /// 本地变量
        DDMap variable;
    private:
        DDMap json2map(Json o);
    public:
        DDObject(Json json) noexcept {
            auto tmp = json2map(json);
            for(const auto &kv : tmp) {
                variable[kv.first] = kv.second;
            }
        }
        DDObject(DDMap variable) noexcept {
            this->variable = variable;
        }
        DDObject(Json json, DDMap vari) noexcept {
            auto tmp = json2map(json);
            for(const auto &kv : tmp) {
                this->variable[kv.first] = kv.second;
            }
            /// 如果vari里有与json中同名的字段,则覆盖
            for(const auto &kv : vari) {
                this->variable[kv.first] = kv.second;
            }
        }
        ~DDObject() {}
    public:
        DDMap getVariable() { return variable; }
        void putVariable(string key, shared_ptr<SemaASTNodeObject> val) {
            variable[key] = val;
        }
        shared_ptr<SemaASTNodeObject> getVariableValue(string key) {
            cout << key << endl;
            if(variable.count(key) > 0) {
                auto r = variable[key];
                return r;
            }
            return SemaASTNodeObject::empty();
        }
    
    };
};





static DDArray getArray(shared_ptr<DDSL::SemaASTNodeObject> obj) {
    return obj->getValue<DDArray>();
}
static DDNumber getNumber(shared_ptr<DDSL::SemaASTNodeObject> obj) {
    return obj->getValue<DDNumber>();
}
static DDBool getBool(shared_ptr<DDSL::SemaASTNodeObject> obj) {
    return obj->getValue<DDBool>();
}
static shared_ptr<DDSL::DDObject> getObject(shared_ptr<DDSL::SemaASTNodeObject> obj) {
    return obj->getValue<shared_ptr<DDSL::DDObject>>();
}


#endif /* FrameContext_hpp */
