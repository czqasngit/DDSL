//
//  SemaUnaryASTNode.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/8.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef SemanticUnaryASTNode_hpp
#define SemanticUnaryASTNode_hpp

#include <stdio.h>
#include "SemaASTNode.h"

namespace DDSL {
    /// 一元节点
    class SemaUnaryASTNode : public SemaASTNode {
    private:
        SemaASTNode *node;
        /// 操作符
        string op;
    public:
        SemaUnaryASTNode(SemaASTNode *node,
                             string op,
                             shared_ptr<DDObject> context)
        :SemaASTNode(context, SemaASTNode::Value) {
            this->op = op;
            this->node = node;
        }
        ~SemaUnaryASTNode() {
            //cout << "SemaUnaryASTNode: release" << endl;
            delete node;
        }
        void run() override {
            this->node->run();
            this->object = node->getResult();
            /// 仅Number支持
            if(object->getType() == DDSL::Number) {
                if(op == "++") {
                    object->setValue(getNumber(object) + 1);
                } else if(op == "--") {
                    object->setValue(getNumber(object) - 1);
                } else {
                    throw "一元表达式暂不支持: " + op + " 运算符";
                }
            } else {
                cout << "[Warning] " << "++或--只能对Number类型有效, " << "当前的类型是: " << object->getTypeText() << endl;
            }
        }
         map<string, Json> getIR() override {
            map<string, Json> m;
            m["Type"] = Json(string("Unary"));
            m["Node"] = Json(this->node->getIR());
            m["OP"] = Json(op);
             return m;
        }
    };

}

#endif /* SemanticUnaryASTNode_hpp */
