//
//  DDExprHelper.cpp
//  DDSL-Script
//
//  Created by youxiaobin on 2020/7/21.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#include "DDExprHelper.h"
using namespace DDSL;
using namespace Script;

bool DDExprHelper::IsExprValid(string code) {
    if(code.length() < 4) return false;
    string copy_s = code;
    copy_s.erase(0,copy_s.find_first_not_of(" "));
    copy_s.erase(copy_s.find_last_not_of(" ") + 1);
    return (copy_s.substr(0, 2) == string("{{") && copy_s.substr(copy_s.length() - 2, 2) == string("}}"));
}

string DDExprHelper::ExtractExpr(string code) {
    string result = code;
    result.erase(0,result.find_first_not_of(" "));
    result.erase(result.find_last_not_of(" ") + 1);
    result = result.substr(2, result.length() - 4);
    return result;
}

