//
//  DDExprHelper.hpp
//  DDSL-Script
//
//  Created by youxiaobin on 2020/7/21.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef DDExprHelper_hpp
#define DDExprHelper_hpp

#include <stdio.h>
#include <string>

using namespace std;

namespace DDSL {
namespace Script {
    class DDExprHelper {
    public:
        /// 判断给定的表达式是否有效
        static bool IsExprValid(string code);
        /// 提取表达式需要执行的内容,提取{{}}中的表达式
        static string ExtractExpr(string code);
    };
}
}

#endif /* DDExprHelper_hpp */
