//
//  Compiler.hpp
//  AntlrDemo
//
//  Created by 坏人 on 2020/7/9.
//  Copyright © 2020 坏人. All rights reserved.
//

#ifndef Compiler_hpp
#define Compiler_hpp

#include <stdio.h>
#include <string>
#include <DDSL-Libs/DDSL-Libs.h>
#include <DDSL-Antlr/DDSL-Antlr.h>
#include <DDSL-Script/DDSL-Script.h>
#include <DDSL-Runtime/DDSL-Runtime.h>

using namespace json11;
using namespace antlr4;
using namespace std;

namespace DDSL {
    class Complier {
    private:
        Json irs;
        Json jsonObject;
        map<string, shared_ptr<DDSL::SemaASTNodeObject>> variable;
    public:
        Complier(Json irs,
                 Json jsonObject = Json(),
                 map<string, shared_ptr<DDSL::SemaASTNodeObject>> variable = {}) {
            this->jsonObject = jsonObject;
            this->irs = irs;
            this->variable = variable;
        }
        ~Complier() { }
        /// 编译完成后,不再保留与编译相关的所有的对象
        SemaFrame compile();
        /// 编译成For语句
        SemaForStmt compileForStmt();
    };
};

#endif /* Compiler_hpp */
