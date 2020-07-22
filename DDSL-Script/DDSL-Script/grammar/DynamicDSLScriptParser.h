
// Generated from DynamicDSLScript.g4 by ANTLR 4.8

#pragma once


#include <DDSL-Antlr/DDSL-Antlr.h>




class  DynamicDSLScriptParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, If = 16, FOR = 17, WHILE = 18, IN = 19, Int = 20, Double = 21, 
    Float = 22, String = 23, Bool = 24, IntLiteral = 25, DoubleLiteral = 26, 
    StringLiteral = 27, True = 28, False = 29, AssignmentOP = 30, RelationalOP = 31, 
    Star = 32, Plus = 33, Sharp = 34, SemiColon = 35, Dot = 36, Comm = 37, 
    LeftBracket = 38, RightBracket = 39, LeftBrace = 40, RightBrace = 41, 
    LeftParen = 42, RightParen = 43, Id = 44, WS = 45
  };

  enum {
    RuleExpression = 0, RulePrimary = 1
  };

  DynamicDSLScriptParser(antlr4::TokenStream *input);
  ~DynamicDSLScriptParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ExpressionContext;
  class PrimaryContext; 

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *LSB = nullptr;;
    antlr4::Token *RSB = nullptr;;
    antlr4::Token *LB = nullptr;;
    antlr4::Token *RB = nullptr;;
    antlr4::Token *for_local = nullptr;;
    antlr4::Token *for_array = nullptr;;
    antlr4::Token *declare = nullptr;;
    antlr4::Token *assign = nullptr;;
    antlr4::Token *prefix = nullptr;;
    antlr4::Token *bop = nullptr;;
    antlr4::Token *postfix = nullptr;;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryContext *primary();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *IN();
    std::vector<antlr4::tree::TerminalNode *> Id();
    antlr4::tree::TerminalNode* Id(size_t i);
    antlr4::tree::TerminalNode *AssignmentOP();
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Double();
    antlr4::tree::TerminalNode *Float();
    antlr4::tree::TerminalNode *String();
    antlr4::tree::TerminalNode *Bool();
    antlr4::tree::TerminalNode *Star();
    antlr4::tree::TerminalNode *Plus();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *TF = nullptr;;
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Id();
    antlr4::tree::TerminalNode *StringLiteral();
    antlr4::tree::TerminalNode *IntLiteral();
    antlr4::tree::TerminalNode *DoubleLiteral();
    antlr4::tree::TerminalNode *True();
    antlr4::tree::TerminalNode *False();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryContext* primary();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

