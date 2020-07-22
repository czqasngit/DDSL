//
//  SemaEvalASTNode.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/8.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef SemanticDotASTNode_hpp
#define SemanticDotASTNode_hpp

#include <stdio.h>
#include "SemaASTNode.h"

namespace DDSL {
    /// 点取值节点
    class SemaEvalASTNode : public SemaASTNode {
    private:
        string key;
        SemaASTNode *node;
        
    public:
        SemaEvalASTNode(SemaASTNode *node,
                           string key,
                           shared_ptr<DDObject> context)
        :SemaASTNode(context, SemaASTNode::Value) {
            this->node = node;
            this->key = key;
        }
        ~SemaEvalASTNode() {
            delete node;
            //cout << "SemaEvalASTNode: release" << endl;
        }
        void run() override {
            /// 如果node不为null,则表示当前取值是从上一个表达式的结果中取值
            /// 上一个表达式结果必须是一个shared_ptr<DDObject
            /// 如果是一个基础类型,则不允许
            if(this->node) {
                /// 通过调用node的run,深度优先计算出左值
                this->node->run();
                shared_ptr<SemaASTNodeObject> tmp = this->node->getResult();
                if(tmp->getType() == DDSL::Object) {
                    try {
                        /// 从左节点返回的上下文环境变量
                        auto tmpContext = getObject(tmp);
                        this->object = tmpContext->getVariableValue(key);
                    } catch(const std::exception& e) {
                        cout << "[Warning] " << "类型出错,当前tmp中包含的值不是shared_ptr<DDObject>" << endl;
                    }
                } else {
                    cout << "[Warning] " << "取值的左表达式得到的结果必须是shared_ptr<DDObject>数据的节点" << endl;
                }
            } else {
                /// 如果没有左节点,从上下文环境变量中取值
                this->object = this->context->getVariableValue(key);
            }
        }
         map<string, Json> getIR() override {
            map<string, Json> m;
            m["Type"] = Json(string("Eval"));
            m["Key"] = Json(key);
            if(this->node) {
                m["Node"] = Json(this->node->getIR());
            }
             return m;
        }
    };
};
#endif /* SemanticDotASTNode_hpp */
