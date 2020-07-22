//
//  display.h
//  Core
//
//  Created by youxiaobin on 2020/6/22.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef display_h
#define display_h

using namespace std;
namespace DDSL {
    namespace display{
        /// 边框
        struct Border {
            float width;
            string colorHex;
        };
        /// 阴影
        struct Shadow {
            /// 颜色值
            string colorHex;
            /// 偏移量
            flex::data::Size offset;
            /// 扩散值
            float radius;
            /// 透明度
            float opacity;
        };
        /// 节点的展示属性
        struct Attribute {
            /// 前景色
            string foregroundColorHex;
            /// 背景色
            string backgroundColorHex;
            /// 边框
            Border border;
            /// 阴影
            Shadow shadow;
            /// 圆角
            float radius;
            
            bool foregroundColorAvailiable() {
                return !foregroundColorHex.empty();
            }
            bool backgroundColorAvailiable() {
                return !backgroundColorHex.empty();
            }
            bool borderAvailiable() {
                return border.width > 0 && !border.colorHex.empty();
            }
            bool shadowAvailiable() {
                return shadow.opacity > 0 && !shadow.colorHex.empty();
            }
            
        };
    }
}

#endif /* display_h */
