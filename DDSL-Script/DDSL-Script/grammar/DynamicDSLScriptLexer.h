
// Generated from DynamicDSLScript.g4 by ANTLR 4.8

#pragma once


#include <DDSL-Antlr/DDSL-Antlr.h>




class  DynamicDSLScriptLexer : public antlr4::Lexer {
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

  DynamicDSLScriptLexer(antlr4::CharStream *input);
  ~DynamicDSLScriptLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

