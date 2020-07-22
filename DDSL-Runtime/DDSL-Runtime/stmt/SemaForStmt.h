//
//  SemaForStmt.hpp
//  DDSL
//
//  Created by youxiaobin on 2020/7/15.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef SemaForStmt_hpp
#define SemaForStmt_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <DDSL-Libs/DDSL-Libs.h>
#include <DDSL-Script/DDSL-Script.h>
#include "SemaASTNodeObject.h"
#include "DDObject.h"

using namespace std;
using namespace json11;

namespace DDSL {
    class SemaForStmt {
    private:
        string arrayName;
        DDArray items;
        DDObject *context;
        string itemKey;
    public:
        SemaForStmt() {}
        SemaForStmt(DynamicDSLScriptParser::ExpressionContext *expr, DDObject *context) {
            /// 获取for语句中的数组变量
            this->arrayName = expr->for_array->getText();
            this->itemKey = expr->for_local->getText();
            this->context = context;
        }
        SemaForStmt(Json ir, DDObject *context) {
            Json tmp;
            if(ir.is_array()) {
                tmp = ir.array_items()[0];
            } else if(ir.is_object()) {
                tmp = ir;
            }
            assert(!tmp.is_null());
            /// 获取for语句中的数组变量
            this->arrayName = tmp["ArrayName"].string_value();
            this->itemKey = tmp["ItemKey"].string_value();
            this->context = context;
        }
        ~SemaForStmt() {
            delete context;
        }
        
        void run() {
            auto obj = this->context->getVariableValue(this->arrayName);
            try {
                items = getArray(obj);
            } catch(std::exception &e) {
                cout << "[Warning] " << "array 类型不是DDArray" << endl;
                cout << e.what() << endl;
            }
        }
        static map<string, Json> GetIR(DynamicDSLScriptParser::ExpressionContext *expr) {
            if(!expr) return {};
            auto array_name = expr->for_array;
            auto item_key = expr->for_local;
            if(!array_name || !item_key) return {};
            if(array_name->getText().empty() || item_key->getText().empty()) return {};
            map<string, Json> m;
            m["Type"] = Json(string("For"));
            m["ArrayName"] = Json(array_name->getText());
            m["ItemKey"] = Json(item_key->getText());
            return m;
        }
        DDArray getResult() { return items; }
        const string getItemKey() { return itemKey; }
        bool isEmpty() { return context == nullptr || items.size() == 0; }
    public:
        static SemaForStmt empty() { return SemaForStmt(); }
    };
};

#endif /* SemaForStmt_hpp */
