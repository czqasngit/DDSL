//
//  SemaParenthesisASTNode.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/9.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef SemaParenthesisASTNode_hpp
#define SemaParenthesisASTNode_hpp

#include <stdio.h>
#include "SemaASTNode.h"

namespace DDSL {
    /// 小括号()
    class SemaParenthesisASTNode : public SemaASTNode {
    private:
        std::shared_ptr<SemaASTNode> node;
    public:
        SemaParenthesisASTNode(SemaASTNode *node,
                               shared_ptr<DDObject> context)
        :SemaASTNode(context, SemaASTNode::Value) {
            this->node.reset(node);
        }
        ~SemaParenthesisASTNode() {
            //cout << "SemaUnaryASTNode: release" << endl;
        }
        void run() override {
            this->node->run();
            this->object = node->getResult();
        }
         map<string, Json> getIR() override {
            map<string, Json> m;
            m["Type"] = Json(string("Parenthesis"));
            m["Node"] = Json(this->node->getIR());
             return m;
        }
    };
}

#endif /* SemaParenthesisASTNode_hpp */
