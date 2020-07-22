//
//  IRCompiler.cpp
//  DDSL-Compiler
//
//  Created by youxiaobin on 2020/7/22.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#include "IRCompiler.h"
using namespace DDSL;
using namespace json11;

/// 生成IR的时候不需要context上下文环境变量的参与
DDSL::SemaASTNode *IRComplier::makeASTNode(DynamicDSLScriptParser::ExpressionContext *expr) {
    size_t expr_count = expr->expression().size();
    SemaASTNode *node = nullptr;
    if(expr->LSB && expr->RSB) {
        if(expr_count == 1) {
            auto subNode = new SemaContextASTNode(nullptr);
            auto key = expr->expression(0)->getText();
            node = new SemaEvalASTNode(subNode, key, nullptr);
        } else if(expr_count == 2) {
            auto subExpr = expr->expression(0);
            auto subNode = makeASTNode(subExpr);
            string key = expr->expression(1)->getText();
            node = new SemaEvalASTNode(subNode, key, nullptr);
        } else {
            throw "未知的点取值表达式类型";
        }
    } else {
        if(expr_count == 0) {
            /// primary
            if(expr->primary()) {
                node = new SemaPrimaryASTNode(expr, nullptr);
            } else if(expr->FOR()) {
                /// For
            }
        } else if(expr_count == 1) {
            /// 一元表达式
            if(expr->prefix || expr->postfix) {
                string prefix;
                if(expr->prefix) {
                    prefix = expr->prefix->getText();
                }
                string postfix;
                if(expr->postfix) {
                    postfix = expr->postfix->getText();
                }
                auto subExpr = expr->expression(0);
                auto subNode = makeASTNode(subExpr);
                if(!prefix.empty()) {
                    node = new SemaUnaryASTNode(subNode, prefix, nullptr);
                } else {
                    node = new SemaUnaryASTNode(subNode, postfix, nullptr);
                }
            } else if(expr->LB && expr->RB) {
                auto subExpr = expr->expression(0);
                auto subNode = makeASTNode(subExpr);
                node = new SemaParenthesisASTNode(subNode, nullptr);
            } else {
                throw "未知的一元表达式类型";
            }
        } else if(expr_count == 2) {
            /// 二元表达式
            if(expr->bop) {
                auto leftExpr = expr->expression(0);
                auto rightExpr = expr->expression(1);
                auto leftNode = makeASTNode(leftExpr);
                auto rightNode = makeASTNode(rightExpr);
                node = new SemaBinaryASTNode(leftNode, rightNode, expr->bop->getText(), nullptr);
            } else {
                throw "未知的二元表达式类型";
            }
        } else if(expr_count == 3) {
            /// 三元表达式
            auto conditionExpr = expr->expression(0);
            auto firstExpr = expr->expression(1);
            auto secondExpr = expr->expression(2);
            auto conditionNode = makeASTNode(conditionExpr);
            auto firstNode = makeASTNode(firstExpr);
            auto secondNode = makeASTNode(secondExpr);
            node = new SemaTernaryASTNode(conditionNode, firstNode, secondNode, nullptr);
        } else {
            throw "未支持的表达式数量: " + to_string(expr_count);
        }
    }
    return node;
}


map<string, Json> IRComplier::ObtainFORStmtIR() {
    if(exprs.size() == 1) {
        auto expr = exprs[0];
        return SemaForStmt::GetIR(expr);
    } else {
        return {};
    }
}

vector<map<string, Json>> IRComplier::ObtainXMLIR() {
    vector<map<string, Json>> irs;
    for(auto node : this->nodes) {
        irs.push_back(node->getIR());
    }
    return irs;
}

