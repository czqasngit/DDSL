
// Generated from DynamicDSLScript.g4 by ANTLR 4.8

#pragma once


#include <DDSL-Antlr/DDSL-Antlr.h>
#include "DynamicDSLScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by DynamicDSLScriptParser.
 */
class  DynamicDSLScriptVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by DynamicDSLScriptParser.
   */
    virtual antlrcpp::Any visitExpression(DynamicDSLScriptParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimary(DynamicDSLScriptParser::PrimaryContext *context) = 0;


};

