//
//  TextNode.hpp
//  Core
//
//  Created by youxiaobin on 2020/6/23.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef TextNode_hpp
#define TextNode_hpp

#include <stdio.h>
#include "Node.h"
#include <string>

using namespace DDSL;
using namespace flex;
using namespace std;

namespace DDSL {
    namespace flex {
        class TextNode: public Node {
        private:
            /// 文字
            string text;
            /// 字体大小
            int fontSize;
            /// 最大行数
            int maxLineNumber;
        public:
            TextNode(float scale, enumeration::NodeType nodeType, _NodeMeasureFunc func = NULL)
            :Node(scale, nodeType, func) {
                YGNodeSetMeasureFunc(this->node, Node::measure);
                this->fontSize = 10;
                this->getDisplayAttribute().foregroundColorHex = "#000000";
                this->maxLineNumber = 1;
                this->text = "";
            }
            void setText(string text) { this->text = text; }
            const string getText() { return this->text; }
            void setFontSize(int fontSize) { this->fontSize = fontSize; }
            const int getFontSize() { return this->fontSize; }
            void setMaxLineNumber(int maxLineNumber) { this->maxLineNumber = maxLineNumber; }
            const int getMaxLineNumber() { return this->maxLineNumber; }
        };
    }
}

#endif /* TextNode_hpp */

