//
//  NodeParser.hpp
//  Core
//
//  Created by youxiaobin on 2020/6/23.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef NodeParser_hpp
#define NodeParser_hpp

#include <stdio.h>
#include "Node.h"
#include <string>
#include "TextNode.h"
#include <DDSL-Libs/DDSL-Libs.h>
#include <DDSL-Runtime/DDSL-Runtime.h>

using namespace DDSL;
using namespace flex;
using namespace std;

class NodeParser {
public:
    /// 解析XML生成Node Tree
    static Node *LoadXML(const char *path,
                         float scale,
                         string json,
                         map<string, shared_ptr<SemaASTNodeObject>> variable,
                         Node::_NodeMeasureFunc func);
};

#endif /* NodeParser_hpp */
