//
//  SemaASTNode.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/8.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef SemanticASTNode_hpp
#define SemanticASTNode_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <DDSL-Script/DDSL-Script.h>
#include <DDSL-Libs/DDSL-Libs.h>
#include "SemaASTNodeObject.h"
#include "DDObject.h"

using namespace json11;
using namespace std;
namespace DDSL {
    /// 整理后可运算的AST
    class SemaASTNode {
    protected:
        shared_ptr<DDObject> context;
    public:
        enum Type {
            None    = 1<<0,
            Assign  = 1<<1, /// 赋值表达式, 改变上下文环境中已存在变量的值
            Declare = 1<<2, /// 申明变量,上下文环境中增加变量
            Value   = 1<<3, /// 求值表达式
            For     = 1<<4, /// For语句
            If      = 1<<5, /// If语句
        };
        /// 节点的类型
        Type type;
        shared_ptr<SemaASTNodeObject> object;
    public:
        SemaASTNode() {
            this->type = None;
            this->object = make_shared<SemaASTNodeObject>();
        }
        SemaASTNode(shared_ptr<DDObject> context, Type type) {
            this->type = type;
            /// 复制,单独管理context的内存
            this->context = context;
            this->object = make_shared<SemaASTNodeObject>();
        }
        virtual ~SemaASTNode() {
            cout << "SemaASTNode 释放了" << endl;
        }
        /// 求节点的值
        virtual void run() { assert(false); }
        /// 获取节点的IR
        virtual map<string, Json> getIR() { assert(false); }
        /// 获取节点的值
        shared_ptr<SemaASTNodeObject> getResult() { return object; }
    };
};

#endif /* SemanticASTNode_hpp */
