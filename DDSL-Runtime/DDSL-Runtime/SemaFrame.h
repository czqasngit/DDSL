//
//  DynamicDSLFrame.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/7.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef DynamicDSLFrame_hpp
#define DynamicDSLFrame_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <DDSL-Libs/DDSL-Libs.h>
#include <DDSL-Script/DDSL-Script.h>
#include "SemaASTNodeObject.h"
#include "SemaASTNode.h"
#include "SemaUnaryASTNode.h"
#include "SemaBinaryASTNode.h"
#include "SemaTernaryASTNode.h"
#include "SemaPrimaryASTNode.h"
#include "SemaAssignASTNode.h"
#include "SemaEvalASTNode.h"
#include "DDObject.h"
#include "SemaContextASTNode.h"
#include "SemaParenthesisASTNode.h"
#include "SemaForStmt.h"

using namespace std;
using namespace json11;

namespace DDSL {
    /// 栈帧
    class SemaFrame {
    private:
        /// 需要运算的AST节点
        vector<SemaASTNode *> nodes;
        /// 当前帧的执行结果
        shared_ptr<SemaASTNodeObject> result;
        /// 上下文环境(变量，注入的JSON)
        shared_ptr<DDObject> context;
        /// 错误信息
        string errMsg;
    public:
        /// 父帧
        SemaFrame *parent;
        SemaFrame(string errMsg) {
            this->errMsg = errMsg;
        }
        SemaFrame(Json irs/*IR Exprs*/,
                  Json json = Json(),
                  DDMap variable = {},
                  SemaFrame *p = nullptr) {
            this->parent = p;
            this->context.reset(new DDObject(json, variable));
            if(irs.is_array()) {
                for(auto expr : irs.array_items()) {
                    auto node = makeASTNode(expr);
                    if(node) nodes.push_back(node);
                }
            }
        }
        static SemaFrame empty(string errMsg) {
            return SemaFrame(errMsg);
        }
        ~SemaFrame() {
            for(auto n : nodes) {
                if(n) delete n;
            }
        }
        /// 是否可以有效运行
        bool valid() {
            return errMsg.empty();
        }
        string getErrorMsg() { return errMsg; }
    private:
        SemaASTNode * makeASTNode(Json ir);
    public:
        void putVariable(string key, shared_ptr<SemaASTNodeObject> o) {
            this->context->putVariable(key, o);
        }
        shared_ptr<SemaASTNodeObject> getVariableValue(string key) {
            auto tmp = this->context->getVariableValue(key);
            if(!tmp->isEmpty()) return tmp;
            if(this->parent) {
                auto po = this->parent->getVariableValue(key);
                if(!po->isEmpty()) return po;
            }
            return SemaASTNodeObject::empty();
        }
    public:
        /// 执行当前帧,并返回一个执行结果
        /// 0: 执行成功
        /// 1: 执行异常
        /// 2: 没有可执行的表达式
        int run() {
            if(nodes.size() == 0) return 2;
            for(auto node : nodes) {
                if(node->type == SemaASTNode::Assign) {
                    /// 申明变量,或者对变量重新赋值,改变对上下文环境变量
                } else {
                    /// 表达式求值
                    node->run();
                    result = node->getResult();
                }
            }
            return 0;
        }
        shared_ptr<SemaASTNodeObject> getResult() {
            return result;
        }
        /// 获取栈帧中需要执行的AST Nodes
        vector<SemaASTNode *> getASTNodes() { return nodes; }
        
    };
};

#endif /* DynamicDSLFrame_hpp */
