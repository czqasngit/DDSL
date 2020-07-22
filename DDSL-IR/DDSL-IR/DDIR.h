//
//  DDIR.hpp
//  DDSL-IR
//
//  Created by youxiaobin on 2020/7/21.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef DDIR_hpp
#define DDIR_hpp

#include <stdio.h>
#include <DDSL-Runtime/DDSL-Runtime.h>
#include <DDSL-Libs/DDSL-Libs.h>

using namespace tinyxml2;
using namespace std;
using namespace json11;

namespace DynamicDSL {
namespace IR {
    class DDIR {
    private:
        XMLDocument doc;
    private:
        /// 将原始XML转化成IR XML
        void Setup();
        void XMLElementIRConvertEntry(XMLElement *element);
        void XMLElementExprToIR(XMLElement *element);
    public:
        DDIR(XMLDocument d) {
            d.DeepCopy(&doc);
            Setup();
        }
        /// 获取转换后的IR XML数据
        string GetIRXMLContent();
    };
}
}

#endif /* DDIR_hpp */
