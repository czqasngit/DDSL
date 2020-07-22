//
//  Node.hpp
//  FlexBoxTest
//
//  Created by youxiaobin on 2020/6/16.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Yoga.h"
#include "enums.h"
#include "data.h"
#include "executable.h"
#include <fstream>
#include <iostream>
#include <string>
#include "utils.h"
#include "flexLog.h"
#include "display.h"

#define NODE_SIZE_STYLE_DECL(TYPE, RETURN_TYPE, NAME) \
RETURN_TYPE get##NAME() { return YGNodeStyleGet##NAME(node); } \
void set##NAME(TYPE val) { YGNodeStyleSet##NAME(node, val); }

#define NODE_SIZE_PERCENT_STYLE_DECL(TYPE, RETURN_TYPE, NAME) \
void set##NAME##Percent(TYPE val) { YGNodeStyleSet##NAME##Percent(node, val); }

#define NODE_BASIC_STYLE_DECL(TYPE, NAME) \
TYPE get##NAME() { return YGNodeStyleGet##NAME(node); } \
void set##NAME(TYPE val) { YGNodeStyleSet##NAME(node, val); }

#define NODE_VALUE_STYLE_DECL(NAME, EDGE, STYLE) \
YGValue get##STYLE##NAME() { return YGNodeStyleGet##STYLE(node, EDGE); } \
void set##STYLE##NAME(YGValue val) { YGNodeStyleSet##STYLE(node, EDGE, val.value); }

#define NODE_BORDER_STYLE_DECL(NAME, EDGE, STYLE) \
float get##STYLE##NAME() { return YGNodeStyleGet##STYLE(node, EDGE); } \
void set##STYLE##NAME(float val) { YGNodeStyleSet##STYLE(node, EDGE, val); }

#define NODE_AUTO_SIZE_STYLE_DECL(NAME) \
void set##NAME##Auto() { YGNodeStyleSet##NAME##Auto(node); }



using namespace std;

namespace DDSL {
    namespace flex {
        /// Layout
        class Node {
        public:
            typedef DDSL::flex::data::Size (*_NodeMeasureFunc)(DDSL::flex::Node *, float, float);
        protected:
            YGNodeRef node;
        private:
            YGConfig *config;
            enumeration::NodeType nodeType;
            std::vector<Node *> *nodes;
            /// if语句
            executable::Stmt if_stmt;
            /// for语句
            executable::Stmt for_stmt;
            /// 样式展示属性
            display::Attribute displayAttribute;
        protected:
            _NodeMeasureFunc _nodeMeasureFunc;
        public:
            Node(float scale, enumeration::NodeType nodeType, _NodeMeasureFunc func = NULL) {
                debugPrint("%s", "创建Node");
                memset(&if_stmt, 0, sizeof(executable::Stmt));
                memset(&for_stmt, 0, sizeof(executable::Stmt));
                memset(&displayAttribute, 0, sizeof(display::Attribute));
                /// 默认阴影的透明度是1.0
                displayAttribute.shadow.opacity = 1.0f;
                _nodeMeasureFunc = func;
                this->nodeType = nodeType;
                nodes = new std::vector<Node *>();
                config = YGConfigNew();
                YGConfigSetExperimentalFeatureEnabled(config, YGExperimentalFeatureWebFlexBasis, true);
                YGConfigSetPointScaleFactor(config, scale);
                node = YGNodeNewWithConfig(config);
                YGNodeStyleSetDirection(node, YGDirectionInherit);
                YGNodeSetContext(node, this);
                /*
                    typedef YGSize (*YGMeasureFunc)(
                    YGNodeRef node,
                    float width,
                    YGMeasureMode widthMode,
                    float height,
                    YGMeasureMode heightMode)
                 */
            }
            ~Node()  {
                debugPrint("%s", "销毁Node");
                delete nodes;
                YGNodeFree(node);
                YGConfigFree(config);
            }
            static YGSize measure(YGNodeRef node, float width, YGMeasureMode widthMode, float height, YGMeasureMode heightMode);
            enumeration::NodeType getNodeType() { return this->nodeType; }
            data::Size getSize();
            data::Point getPoint();
            data::Rect getRect();
            void appendNode(Node *node);
            int getChildCount();
            Node *getChild(int index);
            /// 以当前节点为根节点,计算出布局后的位置与大小
            void calculateLayoutWithSize(float availableWidth, float availableHeight);
            /// 销毁当前节点与子节点
            void destory();
            display::Attribute & getDisplayAttribute() {
                return this->displayAttribute;
            }
            /// Flex
            NODE_BASIC_STYLE_DECL(YGDirection, Direction);
            NODE_BASIC_STYLE_DECL(YGFlexDirection, FlexDirection);
            NODE_BASIC_STYLE_DECL(YGJustify, JustifyContent);
            NODE_BASIC_STYLE_DECL(YGAlign, AlignSelf);
            NODE_BASIC_STYLE_DECL(YGAlign, AlignItems);
            NODE_BASIC_STYLE_DECL(YGPositionType, PositionType);
            NODE_BASIC_STYLE_DECL(YGWrap, FlexWrap);
            NODE_BASIC_STYLE_DECL(YGOverflow, Overflow);
            NODE_BASIC_STYLE_DECL(YGDisplay, Display);
            NODE_BASIC_STYLE_DECL(float, Flex);
            NODE_BASIC_STYLE_DECL(float, FlexGrow);
            NODE_BASIC_STYLE_DECL(float, FlexShrink);
            /// Position
            NODE_VALUE_STYLE_DECL(Top, YGEdgeTop, Position);
            NODE_VALUE_STYLE_DECL(Left, YGEdgeLeft, Position);
            NODE_VALUE_STYLE_DECL(Bottom, YGEdgeBottom, Position);
            NODE_VALUE_STYLE_DECL(Right, YGEdgeRight, Position);
            /// Margin
            NODE_VALUE_STYLE_DECL(Top, YGEdgeTop, Margin);
            NODE_VALUE_STYLE_DECL(Left, YGEdgeLeft, Margin);
            NODE_VALUE_STYLE_DECL(Bottom, YGEdgeBottom, Margin);
            NODE_VALUE_STYLE_DECL(Right, YGEdgeRight, Margin);
            /// Padding
            NODE_VALUE_STYLE_DECL(Top, YGEdgeTop, Padding);
            NODE_VALUE_STYLE_DECL(Left, YGEdgeLeft, Padding);
            NODE_VALUE_STYLE_DECL(Right, YGEdgeRight, Padding);
            NODE_VALUE_STYLE_DECL(Bottom, YGEdgeBottom, Padding);
            /// Border
            NODE_BORDER_STYLE_DECL(Top, YGEdgeTop, Border);
            NODE_BORDER_STYLE_DECL(Left, YGEdgeLeft, Border);
            NODE_BORDER_STYLE_DECL(Bottom, YGEdgeBottom, Border);
            NODE_BORDER_STYLE_DECL(Right, YGEdgeRight, Border);
            /// Size
            NODE_SIZE_STYLE_DECL(float, YGValue, MaxWidth);
            NODE_SIZE_STYLE_DECL(float, YGValue, MaxHeight);
            NODE_SIZE_STYLE_DECL(float, YGValue, MinWidth);
            NODE_SIZE_STYLE_DECL(float, YGValue, MinHeight);
            NODE_SIZE_STYLE_DECL(float, YGValue, Width);
            NODE_SIZE_STYLE_DECL(float, YGValue, Height);
            
            NODE_SIZE_PERCENT_STYLE_DECL(float, YGValue, MaxWidth);
            NODE_SIZE_PERCENT_STYLE_DECL(float, YGValue, MaxHeight);
            NODE_SIZE_PERCENT_STYLE_DECL(float, YGValue, MinWidth);
            NODE_SIZE_PERCENT_STYLE_DECL(float, YGValue, MinHeight);
            NODE_SIZE_PERCENT_STYLE_DECL(float, YGValue, Width);
            NODE_SIZE_PERCENT_STYLE_DECL(float, YGValue, Height);
            /// Auto
            NODE_AUTO_SIZE_STYLE_DECL(Width);
            NODE_AUTO_SIZE_STYLE_DECL(Height);
        };
    }
}



#endif /* Node_hpp */
