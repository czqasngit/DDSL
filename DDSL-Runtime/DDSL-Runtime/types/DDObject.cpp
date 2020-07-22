//
//  Context.cpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/8.
//  Copyright © 2020 坏人. All rights reserved.
//

#include "DDObject.h"

using namespace DDSL;

DDMap DDObject::json2map(Json o) {
    DDMap m;
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
                DDArray v;
                for(auto t : val.array_items()) {
                    auto ddm = json2map(t);
                    auto ddo = make_shared<DDObject>(ddm);
                    v.push_back(make_shared<SemaASTNodeObject>(ddo));
                }
                sp_obj->setValue(v);
            } else if(val.is_object()) {
                /// 如果是一个Object,则抽象成DDObject
                auto rt = json2map(val);
                auto scp = make_shared<DDObject>(rt);
                sp_obj = make_shared<SemaASTNodeObject>(scp);
            }
            m[key] = sp_obj;
        }
    }
    return m;
}
