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
#include "SemaASTNodeObject.h"
#include <DDSL-Libs/DDSL-Libs.h>
#include <DDSL-Script/DDSL-Script.h>

using namespace std;
using namespace json11;


namespace DDSL {
    class SemaObject {
    private:
        /// 本地变量
        map<string, shared_ptr<SemaASTNodeObject>> variable;
    private:
        map<string, shared_ptr<SemaASTNodeObject>> json2map(Json o) {
            map<string, shared_ptr<SemaASTNodeObject>> m;
            if(o.is_object()) {
                for(const auto &kv : o.object_items()) {
                    auto sp_obj = make_shared<SemaASTNodeObject>();
                    auto key = kv.first;
                    auto val = kv.second;
                    if(val.is_string()) {
                        sp_obj->setValue(val.string_value());
                    } else if(val.is_number()) {
                        sp_obj->setValue(val.number_value());
                    } else if(val.is_bool()) {
                        sp_obj->setValue(val.bool_value());
                    } else if(val.is_array()) {
                        vector<shared_ptr<SemaASTNodeObject>> v;
                        for(auto t : val.array_items()) {
                            auto p = new SemaASTNodeObject(json2map(t));
                            v.push_back(shared_ptr<SemaASTNodeObject>(p));
                        }
                        sp_obj->setValue(v);
                    } else if(val.is_object()) {
                        /// 如果是一个Object,则抽象成SemaObject
                        auto rt = json2map(val);
                        auto scp = make_shared<SemaObject>(rt);
                        sp_obj = make_shared<SemaASTNodeObject>(scp);
                    }
                    m[key] = sp_obj;
                }
            }
            return m;
        }
    public:
        SemaObject(Json json) noexcept {
            auto tmp = json2map(json);
            for(const auto &kv : tmp) {
                variable[kv.first] = kv.second;
            }
        }
        SemaObject(map<string, shared_ptr<SemaASTNodeObject>> variable) noexcept {
            this->variable = variable;
        }
        SemaObject(Json json, map<string, shared_ptr<SemaASTNodeObject>> vari) noexcept {
            auto tmp = json2map(json);
            for(const auto &kv : tmp) {
                this->variable[kv.first] = kv.second;
            }
            for(const auto &kv : vari) {
                this->variable[kv.first] = kv.second;
            }
        }
        ~SemaObject() {}
    public:
        map<string, shared_ptr<SemaASTNodeObject>> getVariable() { return variable; }
        void putVariable(string key, shared_ptr<SemaASTNodeObject> val) {
            variable[key] = val;
        }
        shared_ptr<SemaASTNodeObject> getVariableValue(string key) {
            if(variable.count(key) > 0) {
                auto r = variable[key];
                return r;
            }
            return SemaASTNodeObject::empty();
        }
    
    };
};

#endif /* FrameContext_hpp */
