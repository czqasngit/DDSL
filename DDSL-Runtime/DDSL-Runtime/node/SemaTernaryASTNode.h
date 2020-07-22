//
//  SemaTernaryASTNode.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/8.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef SemanticTernaryASTNode_hpp
#define SemanticTernaryASTNode_hpp

#include <stdio.h>
#include "SemaASTNode.h"

namespace DDSL {
    /// 三元节点
    class SemaTernaryASTNode: public SemaASTNode {
    private:
        
        SemaASTNode *condition;
        SemaASTNode *first;
        SemaASTNode *second;
    public:
        SemaTernaryASTNode(SemaASTNode *condition,
                               SemaASTNode *first,
                               SemaASTNode *second,
                               shared_ptr<DDObject> context)
        :SemaASTNode(context, SemaASTNode::Value) {
            this->condition = condition;
            this->first = first;
            this->second = second;
        }
        ~SemaTernaryASTNode() {
            delete condition;
            delete first;
            delete second;
            //cout << "SemaTernaryASTNode: release" << endl;
        }
        
        void run() override {
            this->condition->run();
            this->first->run();
            this->second->run();
            shared_ptr<SemaASTNodeObject> condition = this->condition->getResult();
            shared_ptr<SemaASTNodeObject> first = this->first->getResult();
            shared_ptr<SemaASTNodeObject> second = this->second->getResult();
            if(condition->getType() == DDSL::Bool) {
                if(getBool(condition)) {
                    object = first;
                } else {
                    object = second;
                }
            } else {
                cout << "[Warning] " << "三元表达式条件语句的结果必须是Bool数据类型" << endl;
            }
        }
         map<string, Json> getIR() override {
            map<string, Json> m;
            m["Type"] = Json(string("Ternary"));
            m["condition"] = Json(this->condition->getIR());
            m["first"] = Json(this->first->getIR());
            m["second"] = Json(this->second->getIR());
             return m;
        }
    };
};

#endif /* SemanticTernaryASTNode_hpp */
