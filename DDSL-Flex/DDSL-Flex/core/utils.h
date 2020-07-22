//
//  utils.h
//  Core
//
//  Created by youxiaobin on 2020/6/22.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef utils_h
#define utils_h
#include "YGValue.h"
#include <string>
#include "flexLog.h"

using namespace std;
namespace DDSL {
    namespace util {
        YGValue YGPointValue(float value) {
          return {.value = value, .unit = YGUnitPoint};
        }
        YGValue YGPercentValue(float value) {
          return {.value = value, .unit = YGUnitPercent};
        }
    
        DDSL::flex::enumeration::NodeType ConvertStringToNodeType(string value) {
            if(value == "View") return DDSL::flex::enumeration::view;
            else if(value == "Button") return DDSL::flex::enumeration::button;
            else if(value == "Label") return DDSL::flex::enumeration::label;
            assert(false);
            return DDSL::flex::enumeration::view;
        }

        YGFlexDirection ConvertStringToFlexDirection(string value) {
            if(value == "column") return YGFlexDirectionColumn;
            else if(value == "row") return YGFlexDirectionRow;
            else if(value == "columnReverse") return YGFlexDirectionColumnReverse;
            else if(value == "rowReverse") return YGFlexDirectionRowReverse;
            warningPrint("FlexDriection 属性值错误: %s", value.c_str());
            return YGFlexDirectionRow;
        }

        YGJustify ConvertStringToJustify(string value) {
            if(value == "start") return YGJustifyFlexStart;
            else if(value == "end") return YGJustifyFlexEnd;
            else if(value == "center") return YGJustifyCenter;
            else if(value == "spaceBetween") return YGJustifySpaceBetween;
            else if(value == "spaceAround") return YGJustifySpaceAround;
            else if(value == "spaceEvenly") return YGJustifySpaceEvenly;
            warningPrint("Justify 属性值错误: %s", value.c_str());
            return YGJustifyFlexStart;
        }

        YGAlign ConvertStringToAlign(string value) {
            if(value == "auto") return YGAlignAuto;
            else if(value == "start") return YGAlignFlexStart;
            else if(value == "center") return YGAlignCenter;
            else if(value == "end") return YGAlignFlexEnd;
            else if(value == "stretch") return YGAlignStretch;
            else if(value == "spaceBetween") return YGAlignSpaceBetween;
            else if(value == "spaceAround") return YGAlignSpaceAround;
            warningPrint("Align 属性值错误: %s", value.c_str());
            return YGAlignFlexStart;
        }
        YGPositionType ConvertStringToPositionType(string value) {
            if(value == "relative") return YGPositionTypeRelative;
            else if(value == "absolute") return YGPositionTypeAbsolute;
            warningPrint("PositionType 属性值错误: %s", value.c_str());
            return YGPositionTypeRelative;
        }
        YGWrap ConvertStringToWrap(string value) {
            if(value == "noWrap") return YGWrapNoWrap;
            else if(value == "wrap") return YGWrapWrap;
            else if(value == "wrapReverse") return YGWrapWrapReverse;
            warningPrint("Wrap 属性值错误: %s", value.c_str());
            return YGWrapNoWrap;
        }
        YGOverflow ConvertStringToOverflow(string value) {
            if(value == "visible") return YGOverflowVisible;
            else if(value == "hidden") return YGOverflowHidden;
            else if(value == "scroll") return YGOverflowScroll;
            warningPrint("Overflow 属性值错误: %s", value.c_str());
            return YGOverflowHidden;
        }
        YGDisplay ConvertStringToDisplay(string value) {
            if(value == "flex") return YGDisplayFlex;
            else if(value == "none") return YGDisplayNone;
            warningPrint("Display 属性值错误: %s", value.c_str());
            return YGDisplayFlex;
        }
        YGValue ConvertStringToYGValue(string value) {
            if(value.empty()) return YGValueZero;
            else if(value.rfind("%") != string::npos) {
                float percent = stof(value.substr(0, value.length() - 1));
                return DDSL::util::YGPercentValue(percent * 100);
            } else if(value == "auto") {
                return YGValueAuto;
            } else
                return DDSL::util::YGPointValue(stof(value));
        }

    }
}

#endif /* utils_h */
