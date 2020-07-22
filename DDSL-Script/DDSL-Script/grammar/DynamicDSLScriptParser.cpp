
// Generated from DynamicDSLScript.g4 by ANTLR 4.8


#include "DynamicDSLScriptVisitor.h"

#include "DynamicDSLScriptParser.h"


using namespace antlrcpp;
using namespace antlr4;

DynamicDSLScriptParser::DynamicDSLScriptParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

DynamicDSLScriptParser::~DynamicDSLScriptParser() {
  delete _interpreter;
}

std::string DynamicDSLScriptParser::getGrammarFileName() const {
  return "DynamicDSLScript.g4";
}

const std::vector<std::string>& DynamicDSLScriptParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& DynamicDSLScriptParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ExpressionContext ------------------------------------------------------------------

DynamicDSLScriptParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DynamicDSLScriptParser::PrimaryContext* DynamicDSLScriptParser::ExpressionContext::primary() {
  return getRuleContext<DynamicDSLScriptParser::PrimaryContext>(0);
}

std::vector<DynamicDSLScriptParser::ExpressionContext *> DynamicDSLScriptParser::ExpressionContext::expression() {
  return getRuleContexts<DynamicDSLScriptParser::ExpressionContext>();
}

DynamicDSLScriptParser::ExpressionContext* DynamicDSLScriptParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<DynamicDSLScriptParser::ExpressionContext>(i);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::LeftBracket() {
  return getToken(DynamicDSLScriptParser::LeftBracket, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::RightBracket() {
  return getToken(DynamicDSLScriptParser::RightBracket, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::LeftParen() {
  return getToken(DynamicDSLScriptParser::LeftParen, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::RightParen() {
  return getToken(DynamicDSLScriptParser::RightParen, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::FOR() {
  return getToken(DynamicDSLScriptParser::FOR, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::IN() {
  return getToken(DynamicDSLScriptParser::IN, 0);
}

std::vector<tree::TerminalNode *> DynamicDSLScriptParser::ExpressionContext::Id() {
  return getTokens(DynamicDSLScriptParser::Id);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::Id(size_t i) {
  return getToken(DynamicDSLScriptParser::Id, i);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::AssignmentOP() {
  return getToken(DynamicDSLScriptParser::AssignmentOP, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::Int() {
  return getToken(DynamicDSLScriptParser::Int, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::Double() {
  return getToken(DynamicDSLScriptParser::Double, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::Float() {
  return getToken(DynamicDSLScriptParser::Float, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::String() {
  return getToken(DynamicDSLScriptParser::String, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::Bool() {
  return getToken(DynamicDSLScriptParser::Bool, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::Star() {
  return getToken(DynamicDSLScriptParser::Star, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::ExpressionContext::Plus() {
  return getToken(DynamicDSLScriptParser::Plus, 0);
}


size_t DynamicDSLScriptParser::ExpressionContext::getRuleIndex() const {
  return DynamicDSLScriptParser::RuleExpression;
}


antlrcpp::Any DynamicDSLScriptParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DynamicDSLScriptVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


DynamicDSLScriptParser::ExpressionContext* DynamicDSLScriptParser::expression() {
   return expression(0);
}

DynamicDSLScriptParser::ExpressionContext* DynamicDSLScriptParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  DynamicDSLScriptParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  DynamicDSLScriptParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 0;
  enterRecursionRule(_localctx, 0, DynamicDSLScriptParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(29);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(5);
      primary();
      break;
    }

    case 2: {
      setState(6);
      dynamic_cast<ExpressionContext *>(_localctx)->LSB = match(DynamicDSLScriptParser::LeftBracket);
      setState(7);
      expression(0);
      setState(8);
      dynamic_cast<ExpressionContext *>(_localctx)->RSB = match(DynamicDSLScriptParser::RightBracket);
      break;
    }

    case 3: {
      setState(10);
      dynamic_cast<ExpressionContext *>(_localctx)->LB = match(DynamicDSLScriptParser::LeftParen);
      setState(11);
      expression(0);
      setState(12);
      dynamic_cast<ExpressionContext *>(_localctx)->RB = match(DynamicDSLScriptParser::RightParen);
      break;
    }

    case 4: {
      setState(14);
      match(DynamicDSLScriptParser::FOR);
      setState(15);
      dynamic_cast<ExpressionContext *>(_localctx)->for_local = match(DynamicDSLScriptParser::Id);
      setState(16);
      match(DynamicDSLScriptParser::IN);
      setState(17);
      dynamic_cast<ExpressionContext *>(_localctx)->for_array = match(DynamicDSLScriptParser::Id);
      break;
    }

    case 5: {
      setState(18);
      dynamic_cast<ExpressionContext *>(_localctx)->declare = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DynamicDSLScriptParser::Int)
        | (1ULL << DynamicDSLScriptParser::Double)
        | (1ULL << DynamicDSLScriptParser::Float)
        | (1ULL << DynamicDSLScriptParser::String)
        | (1ULL << DynamicDSLScriptParser::Bool))) != 0))) {
        dynamic_cast<ExpressionContext *>(_localctx)->declare = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(19);
      match(DynamicDSLScriptParser::Id);
      setState(20);
      dynamic_cast<ExpressionContext *>(_localctx)->assign = match(DynamicDSLScriptParser::AssignmentOP);
      setState(21);
      expression(11);
      break;
    }

    case 6: {
      setState(22);
      dynamic_cast<ExpressionContext *>(_localctx)->declare = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DynamicDSLScriptParser::Int)
        | (1ULL << DynamicDSLScriptParser::Double)
        | (1ULL << DynamicDSLScriptParser::Float)
        | (1ULL << DynamicDSLScriptParser::String)
        | (1ULL << DynamicDSLScriptParser::Bool))) != 0))) {
        dynamic_cast<ExpressionContext *>(_localctx)->declare = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(23);
      match(DynamicDSLScriptParser::Id);
      break;
    }

    case 7: {
      setState(24);
      match(DynamicDSLScriptParser::Id);
      setState(25);
      dynamic_cast<ExpressionContext *>(_localctx)->assign = match(DynamicDSLScriptParser::AssignmentOP);
      setState(26);
      expression(9);
      break;
    }

    case 8: {
      setState(27);
      dynamic_cast<ExpressionContext *>(_localctx)->prefix = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == DynamicDSLScriptParser::T__0

      || _la == DynamicDSLScriptParser::T__1)) {
        dynamic_cast<ExpressionContext *>(_localctx)->prefix = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(28);
      expression(7);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(66);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(64);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(31);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(32);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << DynamicDSLScriptParser::T__2)
            | (1ULL << DynamicDSLScriptParser::T__3)
            | (1ULL << DynamicDSLScriptParser::Star))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(33);
          expression(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(34);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(35);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == DynamicDSLScriptParser::T__4

          || _la == DynamicDSLScriptParser::Plus)) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(36);
          expression(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(37);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(38);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << DynamicDSLScriptParser::T__5)
            | (1ULL << DynamicDSLScriptParser::T__6)
            | (1ULL << DynamicDSLScriptParser::T__7)
            | (1ULL << DynamicDSLScriptParser::T__8))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(39);
          expression(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(40);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(41);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == DynamicDSLScriptParser::T__9

          || _la == DynamicDSLScriptParser::T__10)) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(42);
          expression(4);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(43);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(44);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == DynamicDSLScriptParser::T__11

          || _la == DynamicDSLScriptParser::T__12)) {
            dynamic_cast<ExpressionContext *>(_localctx)->bop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(45);
          expression(3);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(46);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(47);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(DynamicDSLScriptParser::T__13);
          setState(48);
          expression(0);
          setState(49);
          dynamic_cast<ExpressionContext *>(_localctx)->bop = match(DynamicDSLScriptParser::T__14);
          setState(50);
          expression(2);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(52);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(53);
          dynamic_cast<ExpressionContext *>(_localctx)->LSB = match(DynamicDSLScriptParser::LeftBracket);
          setState(54);
          expression(0);
          setState(55);
          dynamic_cast<ExpressionContext *>(_localctx)->RSB = match(DynamicDSLScriptParser::RightBracket);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(57);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(58);
          dynamic_cast<ExpressionContext *>(_localctx)->LB = match(DynamicDSLScriptParser::LeftParen);
          setState(59);
          expression(0);
          setState(60);
          dynamic_cast<ExpressionContext *>(_localctx)->RB = match(DynamicDSLScriptParser::RightParen);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(62);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(63);
          dynamic_cast<ExpressionContext *>(_localctx)->postfix = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == DynamicDSLScriptParser::T__0

          || _la == DynamicDSLScriptParser::T__1)) {
            dynamic_cast<ExpressionContext *>(_localctx)->postfix = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        } 
      }
      setState(68);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

DynamicDSLScriptParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DynamicDSLScriptParser::PrimaryContext::Id() {
  return getToken(DynamicDSLScriptParser::Id, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::PrimaryContext::StringLiteral() {
  return getToken(DynamicDSLScriptParser::StringLiteral, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::PrimaryContext::IntLiteral() {
  return getToken(DynamicDSLScriptParser::IntLiteral, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::PrimaryContext::DoubleLiteral() {
  return getToken(DynamicDSLScriptParser::DoubleLiteral, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::PrimaryContext::True() {
  return getToken(DynamicDSLScriptParser::True, 0);
}

tree::TerminalNode* DynamicDSLScriptParser::PrimaryContext::False() {
  return getToken(DynamicDSLScriptParser::False, 0);
}


size_t DynamicDSLScriptParser::PrimaryContext::getRuleIndex() const {
  return DynamicDSLScriptParser::RulePrimary;
}


antlrcpp::Any DynamicDSLScriptParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DynamicDSLScriptVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

DynamicDSLScriptParser::PrimaryContext* DynamicDSLScriptParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 2, DynamicDSLScriptParser::RulePrimary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(74);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DynamicDSLScriptParser::Id: {
        enterOuterAlt(_localctx, 1);
        setState(69);
        match(DynamicDSLScriptParser::Id);
        break;
      }

      case DynamicDSLScriptParser::StringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(70);
        match(DynamicDSLScriptParser::StringLiteral);
        break;
      }

      case DynamicDSLScriptParser::IntLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(71);
        match(DynamicDSLScriptParser::IntLiteral);
        break;
      }

      case DynamicDSLScriptParser::DoubleLiteral: {
        enterOuterAlt(_localctx, 4);
        setState(72);
        match(DynamicDSLScriptParser::DoubleLiteral);
        break;
      }

      case DynamicDSLScriptParser::True:
      case DynamicDSLScriptParser::False: {
        enterOuterAlt(_localctx, 5);
        setState(73);
        dynamic_cast<PrimaryContext *>(_localctx)->TF = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == DynamicDSLScriptParser::True

        || _la == DynamicDSLScriptParser::False)) {
          dynamic_cast<PrimaryContext *>(_localctx)->TF = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool DynamicDSLScriptParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 0: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool DynamicDSLScriptParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 1);
    case 6: return precpred(_ctx, 15);
    case 7: return precpred(_ctx, 13);
    case 8: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> DynamicDSLScriptParser::_decisionToDFA;
atn::PredictionContextCache DynamicDSLScriptParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN DynamicDSLScriptParser::_atn;
std::vector<uint16_t> DynamicDSLScriptParser::_serializedATN;

std::vector<std::string> DynamicDSLScriptParser::_ruleNames = {
  "expression", "primary"
};

std::vector<std::string> DynamicDSLScriptParser::_literalNames = {
  "", "'++'", "'--'", "'/'", "'%'", "'-'", "'<'", "'<='", "'>'", "'>='", 
  "'=='", "'!='", "'&&'", "'||'", "'?'", "':'", "'if'", "'for'", "'while'", 
  "'in'", "'int'", "'double'", "'float'", "'string'", "'bool'", "", "", 
  "", "'true'", "'false'", "'='", "", "'*'", "'+'", "'#'", "';'", "'.'", 
  "','", "'['", "']'", "'{'", "'}'", "'('", "')'"
};

std::vector<std::string> DynamicDSLScriptParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "If", 
  "FOR", "WHILE", "IN", "Int", "Double", "Float", "String", "Bool", "IntLiteral", 
  "DoubleLiteral", "StringLiteral", "True", "False", "AssignmentOP", "RelationalOP", 
  "Star", "Plus", "Sharp", "SemiColon", "Dot", "Comm", "LeftBracket", "RightBracket", 
  "LeftBrace", "RightBrace", "LeftParen", "RightParen", "Id", "WS"
};

dfa::Vocabulary DynamicDSLScriptParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> DynamicDSLScriptParser::_tokenNames;

DynamicDSLScriptParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2f, 0x4f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x20, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x43, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0x46, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x4d, 0xa, 0x3, 0x3, 0x3, 0x2, 0x3, 0x2, 0x4, 0x2, 0x4, 0x2, 
    0xa, 0x3, 0x2, 0x16, 0x1a, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 0x5, 0x6, 0x22, 
    0x22, 0x4, 0x2, 0x7, 0x7, 0x23, 0x23, 0x3, 0x2, 0x8, 0xb, 0x3, 0x2, 
    0xc, 0xd, 0x3, 0x2, 0xe, 0xf, 0x3, 0x2, 0x1e, 0x1f, 0x2, 0x60, 0x2, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7, 0x8, 
    0x2, 0x1, 0x2, 0x7, 0x20, 0x5, 0x4, 0x3, 0x2, 0x8, 0x9, 0x7, 0x28, 0x2, 
    0x2, 0x9, 0xa, 0x5, 0x2, 0x2, 0x2, 0xa, 0xb, 0x7, 0x29, 0x2, 0x2, 0xb, 
    0x20, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x7, 0x2c, 0x2, 0x2, 0xd, 0xe, 0x5, 
    0x2, 0x2, 0x2, 0xe, 0xf, 0x7, 0x2d, 0x2, 0x2, 0xf, 0x20, 0x3, 0x2, 0x2, 
    0x2, 0x10, 0x11, 0x7, 0x13, 0x2, 0x2, 0x11, 0x12, 0x7, 0x2e, 0x2, 0x2, 
    0x12, 0x13, 0x7, 0x15, 0x2, 0x2, 0x13, 0x20, 0x7, 0x2e, 0x2, 0x2, 0x14, 
    0x15, 0x9, 0x2, 0x2, 0x2, 0x15, 0x16, 0x7, 0x2e, 0x2, 0x2, 0x16, 0x17, 
    0x7, 0x20, 0x2, 0x2, 0x17, 0x20, 0x5, 0x2, 0x2, 0xd, 0x18, 0x19, 0x9, 
    0x2, 0x2, 0x2, 0x19, 0x20, 0x7, 0x2e, 0x2, 0x2, 0x1a, 0x1b, 0x7, 0x2e, 
    0x2, 0x2, 0x1b, 0x1c, 0x7, 0x20, 0x2, 0x2, 0x1c, 0x20, 0x5, 0x2, 0x2, 
    0xb, 0x1d, 0x1e, 0x9, 0x3, 0x2, 0x2, 0x1e, 0x20, 0x5, 0x2, 0x2, 0x9, 
    0x1f, 0x6, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x8, 0x3, 0x2, 0x2, 0x2, 0x1f, 
    0xc, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x10, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x14, 
    0x3, 0x2, 0x2, 0x2, 0x1f, 0x18, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1a, 0x3, 
    0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x44, 0x3, 0x2, 
    0x2, 0x2, 0x21, 0x22, 0xc, 0x8, 0x2, 0x2, 0x22, 0x23, 0x9, 0x4, 0x2, 
    0x2, 0x23, 0x43, 0x5, 0x2, 0x2, 0x9, 0x24, 0x25, 0xc, 0x7, 0x2, 0x2, 
    0x25, 0x26, 0x9, 0x5, 0x2, 0x2, 0x26, 0x43, 0x5, 0x2, 0x2, 0x8, 0x27, 
    0x28, 0xc, 0x6, 0x2, 0x2, 0x28, 0x29, 0x9, 0x6, 0x2, 0x2, 0x29, 0x43, 
    0x5, 0x2, 0x2, 0x7, 0x2a, 0x2b, 0xc, 0x5, 0x2, 0x2, 0x2b, 0x2c, 0x9, 
    0x7, 0x2, 0x2, 0x2c, 0x43, 0x5, 0x2, 0x2, 0x6, 0x2d, 0x2e, 0xc, 0x4, 
    0x2, 0x2, 0x2e, 0x2f, 0x9, 0x8, 0x2, 0x2, 0x2f, 0x43, 0x5, 0x2, 0x2, 
    0x5, 0x30, 0x31, 0xc, 0x3, 0x2, 0x2, 0x31, 0x32, 0x7, 0x10, 0x2, 0x2, 
    0x32, 0x33, 0x5, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x11, 0x2, 0x2, 0x34, 
    0x35, 0x5, 0x2, 0x2, 0x4, 0x35, 0x43, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 
    0xc, 0x11, 0x2, 0x2, 0x37, 0x38, 0x7, 0x28, 0x2, 0x2, 0x38, 0x39, 0x5, 
    0x2, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x29, 0x2, 0x2, 0x3a, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x3c, 0xc, 0xf, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x2c, 0x2, 
    0x2, 0x3d, 0x3e, 0x5, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x2d, 0x2, 0x2, 
    0x3f, 0x43, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0xc, 0xa, 0x2, 0x2, 0x41, 
    0x43, 0x9, 0x3, 0x2, 0x2, 0x42, 0x21, 0x3, 0x2, 0x2, 0x2, 0x42, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x27, 0x3, 0x2, 0x2, 0x2, 0x42, 0x2a, 0x3, 
    0x2, 0x2, 0x2, 0x42, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x42, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x36, 0x3, 0x2, 0x2, 0x2, 0x42, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x46, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4d, 
    0x7, 0x2e, 0x2, 0x2, 0x48, 0x4d, 0x7, 0x1d, 0x2, 0x2, 0x49, 0x4d, 0x7, 
    0x1b, 0x2, 0x2, 0x4a, 0x4d, 0x7, 0x1c, 0x2, 0x2, 0x4b, 0x4d, 0x9, 0x9, 
    0x2, 0x2, 0x4c, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x6, 
    0x1f, 0x42, 0x44, 0x4c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

DynamicDSLScriptParser::Initializer DynamicDSLScriptParser::_init;
