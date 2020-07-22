//
//  SemaBinaryASTNode.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/8.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef SemanticBinaryASTNode_hpp
#define SemanticBinaryASTNode_hpp

#include <stdio.h>
#include "SemaASTNode.h"

namespace DDSL {
    /// 二元节点
    class SemaBinaryASTNode : public SemaASTNode {
    private:
        SemaASTNode *left;
        SemaASTNode *right;
        string op;
    public:
        SemaBinaryASTNode(SemaASTNode *left,
                          SemaASTNode *right,
                          string op,
                          shared_ptr<DDObject> context)
        :SemaASTNode(context, SemaASTNode::Value) {
            this->left = left;
            this->right = right;
            this->op = op;
        }
        ~SemaBinaryASTNode() {
            delete left;
            delete right;
            //cout << "SemaBinaryASTNode: release" << endl;
        }
        void run() override;
         map<string, Json> getIR() override;
        
    };
};
#endif /* SemanticBinaryASTNode_hpp */
