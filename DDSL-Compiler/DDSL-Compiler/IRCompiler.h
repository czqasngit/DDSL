//
//  IRCompiler.hpp
//  DDSL-Compiler
//
//  Created by youxiaobin on 2020/7/22.
//  Copyright © 2020 youxiaobin. All rights reserved.
//

#ifndef IRCompiler_hpp
#define IRCompiler_hpp

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
    /// 将原始XML转换成IR XML
    class IRComplier {
    private:
        shared_ptr<ANTLRInputStream> input;
        shared_ptr<DynamicDSLScriptLexer> lexer;
        shared_ptr<CommonTokenStream> tokens;
        shared_ptr<DynamicDSLScriptParser> parser;
        vector<DynamicDSLScriptParser::ExpressionContext *> exprs;
        vector<SemaASTNode *> nodes;
    private:
        DDSL::SemaASTNode * makeASTNode(DynamicDSLScriptParser::ExpressionContext *expr);
    public:
        IRComplier(string expression) {
            input = make_shared<ANTLRInputStream>(expression);
            lexer = make_shared<DynamicDSLScriptLexer>(input.get());
            tokens = make_shared<CommonTokenStream>(lexer.get());
            parser = make_shared<DynamicDSLScriptParser>(tokens.get());
            auto expressionContext = parser->expression();
            if(parser->getNumberOfSyntaxErrors() == 0) {
                exprs.push_back(expressionContext);
            }
            for(auto expr : exprs) {
                auto node = makeASTNode(expr);
                if(node) nodes.push_back(node);
            }
        }
        ~IRComplier() { }
        /// 将表达式转换成IR
        vector<map<string, Json>> ObtainXMLIR();
        /// 获取For语句的IR
        map<string, Json> ObtainFORStmtIR();
    };
};

#endif /* IRCompiler_hpp */
