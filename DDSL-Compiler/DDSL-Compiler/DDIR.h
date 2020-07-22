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

namespace DDSL {
    class DDIR {
    private:
        XMLDocument doc;
        char *xmlFilePath;
    private:
        /// 将原始XML转化成IR XML
        void Setup();
        void XMLElementIRConvertEntry(XMLElement *element);
        void XMLElementExprToIR(XMLElement *element);
    public:
        DDIR(const char *path) {
            auto len = strlen(path);
            this->xmlFilePath = (char *)malloc(len);
            strcpy(this->xmlFilePath, path);
        }
        ~DDIR() {
            free(this->xmlFilePath);
            this->xmlFilePath = nullptr;
        }
        void run() {
            Setup();
        }
        /// 获取转换后的IR XML数据
        string ObtainXMLIR();
    };
}

#endif /* DDIR_hpp */
