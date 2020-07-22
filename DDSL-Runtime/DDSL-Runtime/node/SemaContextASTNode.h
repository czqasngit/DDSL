//
//  SemaContextASTNode.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/9.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef SemaContextASTNode_hpp
#define SemaContextASTNode_hpp

#include <stdio.h>
#include "SemaASTNode.h"

namespace DDSL {
    /// 只带有上下文环境的节点
    class SemaContextASTNode : public SemaASTNode {
    public:
        SemaContextASTNode(shared_ptr<DDObject> context): SemaASTNode(context, SemaASTNode::Value) {}
        void run() override {
            this->object.reset(new SemaASTNodeObject(context));
        }
        map<string, Json> getIR() override {
             map<string, Json> m;
            /// 节点类型
             m["Type"] = Json(string("Context"));
             return m;
        }
    };
};

#endif /* SemaContextASTNode_hpp */
