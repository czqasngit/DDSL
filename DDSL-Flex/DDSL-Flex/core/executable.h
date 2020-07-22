//
//  executable.h
//  Core
//
//  Created by youxiaobin on 2020/6/22.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef executable_h
#define executable_h

#include <string>
using namespace std;
namespace DDSL {
    namespace executable {
        /// 可执行语句的类型
        enum Type { none = 0, st_if, st_for };
        /// 可执行语句块
        struct Stmt {
            string stmt;
            Type type;
        };
    }
}

#endif /* executable_h */
