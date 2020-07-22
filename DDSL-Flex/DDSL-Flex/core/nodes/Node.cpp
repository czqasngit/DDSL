//
//  Node.cpp
//  FlexBoxTest
//
//  Created by youxiaobin on 2020/6/16.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#include "Node.h"
#include <thread>
#include <assert.h>

using namespace DDSL;
using namespace flex;
using namespace enumeration;
using namespace data;

void Node::calculateLayoutWithSize(float availableWidth, float availableHeight) {
    int current_thread_num = pthread_main_np();
    assert(current_thread_num > 0);
    YGNodeCalculateLayout(node, availableWidth, availableHeight, getDirection());
}
Rect Node::getRect() {
    return {
        .point = getPoint(),
        .size = getSize()
    };
}
Point Node::getPoint() {
    return {
        .x = YGNodeLayoutGetLeft(node),
        .y = YGNodeLayoutGetTop(node)
    };
}
Size Node::getSize() {
    return {
        .width = YGNodeLayoutGetWidth(node),
        .height = YGNodeLayoutGetHeight(node)
    };
}
void Node::appendNode(Node *node) {
    bool exists = false;
    for(int i = 0; i < getChildCount(); i ++) {
        if(getChild(i) == node) {
            exists = true;
            break;
        }
    }
    assert(!exists);
    nodes->push_back(node);
    int count = getChildCount();
    YGNodeInsertChild(this->node, node->node, count - 1);
}

int Node::getChildCount() {
    return (int)this->nodes->size();
}

Node * Node::getChild(int index) {
    return this->nodes->at(index);
}

void Node::destory() {
    for(int i = 0; i < getChildCount(); i ++) {
        Node *childNode = getChild(i);
        childNode->destory();
    }
    delete this;
}

YGSize Node::measure(YGNodeRef node, float width, YGMeasureMode widthMode, float height, YGMeasureMode heightMode) {
    DDSL::flex::Node *flexNode = (DDSL::flex::Node *)YGNodeGetContext(node);
    if(!flexNode->_nodeMeasureFunc) return {width, height};
    DDSL::flex::data::Size size = flexNode->_nodeMeasureFunc(flexNode, width, height);
    return {size.width, size.height};
}
