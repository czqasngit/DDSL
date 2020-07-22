//
//  structs.h
//  CrossPlatfromTemplate-Core
//
//  Created by youxiaobin on 2020/6/22.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef structs_h
#define structs_h

namespace DDSL {
    namespace flex {
        namespace data {
            /// Node节点的大小
            struct Size {
                float width;
                float height;
            };
            /// Node节点的起始坐标
            struct Point {
                float x;
                float y;
            };
            /// Node节点的Frame
            struct Rect {
                Point point;
                Size size;
            };
        }
    }
}

#endif /* structs_h */
