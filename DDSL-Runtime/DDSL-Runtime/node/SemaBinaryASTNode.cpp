//
//  SemaBinaryASTNode.cpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/8.
//  Copyright © 2020 坏人. All rights reserved.
//

#include "SemaBinaryASTNode.h"

using namespace json11;

void DDSL::SemaBinaryASTNode::run() {
    this->left->run();
    this->right->run();
    shared_ptr<SemaASTNodeObject> left = this->left->getResult();
    shared_ptr<SemaASTNodeObject> right = this->right->getResult();
    if(op == "*") {
        if(left->getType() == DDSL::Number && right->getType() == DDSL::Number) {
            object->setValue(getNumber(left) * getNumber(right));
        } else {
            cout << "[Warning] " << "二元表达式, 类型 " << left->getTypeText() << "与 " << right->getTypeText() << "不能进行 ' " + op + " ' 运算" << endl;
        }
    } else if(op == "/") {
        if(left->getType() == DDSL::Number && right->getType() == DDSL::Number) {
            object->setValue(getNumber(left) / getNumber(right));
        } else {
            cout << "[Warning] " << "二元表达式, 类型 " << left->getTypeText() << "与 " << right->getTypeText() << "不能进行 ' " + op + " ' 运算" << endl;
        }
    } else if(op == "%") {
        if(left->getType() == DDSL::Number && right->getType() == DDSL::Number)
            object->setValue((int)getNumber(left) % (int)getNumber(right));
        else {
            cout << "[Warning] " << "二元表达式, 类型 " << left->getTypeText() << "与 " << right->getTypeText() << "不能进行 ' " + op + " ' 运算" << endl;
        }
    } else if(op == "+") {
        if(left->getType() == DDSL::String || right->getType() == DDSL::String) {
            object->setValue(left->getText() + right->getText());
        } else if(left->getType() == DDSL::Number && right->getType() == DDSL::Number) {
            object->setValue(getNumber(left) + getNumber(right));
        } else {
            cout << "[Warning] " << "二元表达式, 类型 " << left->getTypeText() << "与 " << right->getTypeText() << "不能进行 ' " + op + " ' 运算" << endl;
        }
    } else if(op == "-") {
        if(left->getType() == DDSL::Number && right->getType() == DDSL::Number)
            object->setValue(getNumber(left) - getNumber(right));
        else {
            cout << "[Warning] " << "二元表达式, 类型 " << left->getTypeText() << "与 " << right->getTypeText() << "不能进行 ' " + op + " ' 运算" << endl;
        }
    } else if(op == "<") {
        if(left->getType() == DDSL::Number && right->getType() == DDSL::Number)
            object->setValue(getNumber(left) < getNumber(right));
        else {
            cout << "[Warning] " << "二元表达式, 类型 " << left->getTypeText() << "与 " << right->getTypeText() << "不能进行 ' " + op + " ' 运算" << endl;
        }
    } else if(op == "<=") {
        if(left->getType() == DDSL::Number && right->getType() == DDSL::Number)
            object->setValue(getNumber(left) <= getNumber(right));
        else {
            cout << "[Warning] " << "二元表达式, 类型 " << left->getTypeText() << "与 " << right->getTypeText() << "不能进行 ' " + op + " ' 运算" << endl;
        }
    } else if(op == ">") {
        if(left->getType() == DDSL::Number && right->getType() == DDSL::Number)
            object->setValue(getNumber(left) > getNumber(right));
        else {
            cout << "[Warning] " << "二元表达式, 类型 " << left->getTypeText() << "与 " << right->getTypeText() << "不能进行 ' " + op + " ' 运算" << endl;
        }
    } else if(op == ">=") {
        if(left->getType() == DDSL::Number && right->getType() == DDSL::Number)
            object->setValue(getNumber(left) >= getNumber(right));
        else {
            cout << "[Warning] " << "二元表达式, 类型 " << left->getTypeText() << "与 " << right->getTypeText() << "不能进行 ' " + op + " ' 运算" << endl;
        }
    } else if(op == "==") {
        if(left->getType() != right->getType()) {
            object->setValue(false);
        } else {
            object->setValue(left->getText() == right->getText());
        }
    } else if(op == "!=") {
        if(left->getType() != right->getType()) {
            object->setValue(true);
        } else {
            object->setValue(!(left->getText() == right->getText()));
        }
    } else if(op == "&&") {
        if(left->getType() == DDSL::Bool && right->getType() == DDSL::Bool)
            object->setValue(getBool(left) && getBool(right));
        else {
            cout << "[Warning] " << "二元表达式, 类型 " << left->getTypeText() << "与 " << right->getTypeText() << "不能进行 ' " + op + " ' 运算" << endl;
        }
    } else if(op == "||") {
        if(left->getType() == DDSL::Bool && right->getType() == DDSL::Bool)
            object->setValue(getBool(left) || getBool(right));
        else {
            cout << "[Warning] " << "二元表达式, 类型 " << left->getTypeText() << "与 " << right->getTypeText() << "不能进行 ' " + op + " ' 运算" << endl;
        }
    }
}

map<string, Json> DDSL::SemaBinaryASTNode::getIR() {
    map<string, Json> m;
    m["Type"] = Json(string("Binary"));
    m["Left"] = Json(this->left->getIR());
    m["Right"] = Json(this->right->getIR());
    m["OP"] = this->op;
    return m;
}
