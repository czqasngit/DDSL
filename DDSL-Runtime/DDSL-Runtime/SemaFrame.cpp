//
//  DynamicDSLFrame.cpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/7.
//  Copyright © 2020 坏人. All rights reserved.
//

#include "SemaFrame.h"

using namespace json11;


DDSL::SemaASTNode *DDSL::SemaFrame::makeASTNode(Json ir) {
    auto type = ir["Type"];
    if(type.is_null()) return nullptr;
    if(!type.is_string()) return nullptr;
    auto typeValue = type.string_value();
    SemaASTNode *node = nullptr;
    if(typeValue == string("Primary")) {
        node = new SemaPrimaryASTNode(ir, context);
    } else if(typeValue == string("Context")) {
        node = new SemaContextASTNode(context);
    } else if(typeValue == string("Binary")) {
        auto left = makeASTNode(ir["Left"]);
        auto right = makeASTNode(ir["Right"]);
        auto op = ir["OP"].string_value();
        node = new SemaBinaryASTNode(left, right, op, context);
    } else if(typeValue == string("Unary")) {
        auto op = ir["OP"].string_value();
        auto subNodeIr = ir["Node"];
        SemaASTNode *subNode = nullptr;
        if(!subNodeIr.is_null() && subNodeIr.is_object()) {
            subNode = makeASTNode(subNodeIr);
        }
        node = new SemaUnaryASTNode(subNode, op, context);
    } else if(typeValue == string("Parenthesis")) {
        auto subNodeIr = ir["Node"];
        SemaASTNode *subNode = makeASTNode(subNodeIr);;
        node = new SemaParenthesisASTNode(subNode, context);
    } else if(typeValue == string("Eval")) {
        auto key = ir["Key"].string_value();
        auto subNodeIr = ir["Node"];
        SemaASTNode *subNode = nullptr;
        if(!subNodeIr.is_null() && subNodeIr.is_object()) {
            subNode = makeASTNode(subNodeIr);
        }
        node = new SemaEvalASTNode(subNode, key, context);
    } else if(typeValue == string("Ternary")) {
        auto condition = makeASTNode(ir["condition"]);
        auto first = makeASTNode(ir["first"]);
        auto second = makeASTNode(ir["second"]);
        node = new SemaTernaryASTNode(condition, first, second, context);
    }
    return node;
}
