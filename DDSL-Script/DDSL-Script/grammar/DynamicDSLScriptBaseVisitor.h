
// Generated from DynamicDSLScript.g4 by ANTLR 4.8

#pragma once


#include <DDSL-Antlr/DDSL-Antlr.h>
#include "DynamicDSLScriptVisitor.h"


/**
 * This class provides an empty implementation of DynamicDSLScriptVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  DynamicDSLScriptBaseVisitor : public DynamicDSLScriptVisitor {
public:

  virtual antlrcpp::Any visitExpression(DynamicDSLScriptParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimary(DynamicDSLScriptParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }


};

