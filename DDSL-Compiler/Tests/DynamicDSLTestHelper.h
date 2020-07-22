//
//  DynamicDSLTestHelper.hpp
//  DynamicDSLTests
//
//  Created by youxiaobin on 2020/7/14.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef DynamicDSLTestHelper_hpp
#define DynamicDSLTestHelper_hpp

#include <stdio.h>
#include <DDSL-Libs/DDSL-Libs.h>
#include <DDSL-Antlr/DDSL-Antlr.h>
#include <DDSL-Script/DDSL-Script.h>
#include <DDSL-Runtime/DDSL-Runtime.h>
#include "Compiler.h"
using namespace tinyxml2;
using namespace std;
using namespace antlr4;

class DynamicDSLTestHelper {
private:
    json11::Json jsonObject;
    map<string, shared_ptr<DDSL::SemaASTNodeObject>> variable;
    DynamicDSLTestHelper() {
        string json = "{\"agex\": 32, \"namex\": \"johnx\", \"size\": {\"width\": 20, \"height\": 30}, \"object\": {\"rect\": {\"point\": {\"x\": 200, \"y\": 100, \"name\": \"小强\"}}}, \"items\":[\"小强\", \"小明\"]}";
           string err;
        this->jsonObject = json11::Json::parse(json, err);
        auto o = make_shared<DDSL::SemaASTNodeObject>(new DDSL::SemaASTNodeObject(DDSL::SemaASTNodeObject(DDSL::SemaASTNodeObject(100)))) ;
        this->variable["default"] = o;
    }
public:
    static DynamicDSLTestHelper *shared() {
        static DynamicDSLTestHelper *helper = nullptr;
        if(!helper) {
            helper = new DynamicDSLTestHelper();
        }
        return helper;
    }
    std::string runExpr(std::string code) {
        return runExpr(code, variable);
    }
    std::string runExpr(std::string code, map<string, shared_ptr<DDSL::SemaASTNodeObject>> vari) {
        this->variable = vari;
        auto complier = DDSL::Complier(code, this->jsonObject, this->variable);
        auto frame = complier.compile();
        if(frame.valid()) {
            frame.run();
            auto obj = frame.getResult();
            return obj->getText();
        } else {
            cout << "[Error] " << frame.getErrorMsg() << endl;
            return string("");
        }
    }
};

#endif /* DynamicDSLTestHelper_hpp */
