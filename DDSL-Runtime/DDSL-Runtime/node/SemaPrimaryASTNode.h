//
//  SemaPrimaryASTNode.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/8.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef SemanticPrimaryASTNode_hpp
#define SemanticPrimaryASTNode_hpp

#include <stdio.h>
#include "SemaASTNode.h"


namespace DDSL {
    /// 基础值(变量)节点
    class SemaPrimaryASTNode : public SemaASTNode {
    private:
        string idTokenText;
        string stringTokenText;
        string intTokenText;
        string doubleTokenText;
        string tfTokenText;
    public:
        SemaPrimaryASTNode(DynamicDSLScriptParser::ExpressionContext *expr,
                           shared_ptr<DDObject> context)
        :SemaASTNode(context, SemaASTNode::Value) {
            if(expr->primary()) {
                DynamicDSLScriptParser::PrimaryContext *primary = expr->primary();
                if(primary->Id()) {
                    idTokenText = primary->Id()->getText();
                } else if(primary->StringLiteral()) {
                    stringTokenText = primary->StringLiteral()->getText();
                } else if(primary->IntLiteral()) {
                    intTokenText = primary->IntLiteral()->getText();
                } else if(primary->DoubleLiteral()) {
                    doubleTokenText = primary->DoubleLiteral()->getText();
                } else if(primary->TF) {
                    tfTokenText = primary->TF->getText();
                }
            }
        }
        SemaPrimaryASTNode(Json ir,
                           shared_ptr<DDObject> context)
        :SemaASTNode(context, SemaASTNode::Value) {
            if(ir.is_null()) return;
            if(!ir.is_object()) return;
            auto o = ir.object_items();
            auto subType = o["SubType"];
            auto value = o["Value"];
            if(subType == string("ID")) {
                idTokenText = value.string_value();
            } else if(subType == string("String")) {
                stringTokenText = value.string_value();
            } else if(subType == string("Int")) {
                intTokenText = value.string_value();
            } else if(subType == string("Double")) {
                doubleTokenText = value.string_value();
            } else if(subType == string("Bool")) {
                tfTokenText = value.string_value();
            }
        }
        SemaPrimaryASTNode(shared_ptr<DDObject> context)
        :SemaASTNode(context, SemaASTNode::Value) {
        }
        ~SemaPrimaryASTNode() {
            //cout << "SemaPrimaryASTNode: release" << endl;
        }
        void run() override {
            if(idTokenText.empty() || stringTokenText.empty() || intTokenText.empty() || doubleTokenText.empty() || tfTokenText.empty()) {
                /// 这里对变量进行消解
                if(!idTokenText.empty()) {
                    object = this->context->getVariableValue(idTokenText);
                } else if(!stringTokenText.empty()) {
                    object->setValue(stringTokenText.substr(1, stringTokenText.length() - 2));
                } else if(!intTokenText.empty()) {
                    object->setValue(stod(intTokenText));
                } else if(!doubleTokenText.empty()) {
                    object->setValue(stod(doubleTokenText));
                } else if(!tfTokenText.empty()) {
                    if(tfTokenText == "true") {
                        object->setValue(true);
                    } else {
                        object->setValue(false);
                    }
                } else {
                    cout << "[Warning] " << "未支持的类型" << endl;
                }
            } else {
                this->object.reset(new SemaASTNodeObject(context));
            }
        }
        map<string, Json> getIR() override {
             map<string, Json> m;
             m["Type"] = Json(string("Primary"));
             if(!idTokenText.empty()) {
                 m["SubType"] = Json(string("ID"));
                 m["Value"] = Json(string(idTokenText));
             } else if(!stringTokenText.empty()) {
                 m["SubType"] = Json(string("String"));
                 m["Value"] = Json(string(stringTokenText));
             } else if(!intTokenText.empty()) {
                 m["SubType"] = Json(string("Int"));
                 m["Value"] = Json(string(intTokenText));
             } else if(!doubleTokenText.empty()) {
                 m["SubType"] = Json(string("Double"));
                 m["Value"] = Json(string(doubleTokenText));
             } else if(!tfTokenText.empty()) {
                 m["SubType"] = Json(string("Bool"));
                 m["Value"] = Json(string(tfTokenText));
             } else {
                 m["SubType"] = Json(string("None"));
             }
             return m;
        }
    };
};
#endif /* SemanticPrimaryASTNode_hpp */
