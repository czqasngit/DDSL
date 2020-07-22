// Generated from /Volumes/Work/dev/DynamicDSL/DynamicDSL/runtime/grammar/DynamicDSLScript.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class DynamicDSLScriptParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, If=16, FOR=17, 
		WHILE=18, IN=19, Int=20, Double=21, Float=22, String=23, Bool=24, IntLiteral=25, 
		DoubleLiteral=26, StringLiteral=27, True=28, False=29, AssignmentOP=30, 
		RelationalOP=31, Star=32, Plus=33, Sharp=34, SemiColon=35, Dot=36, Comm=37, 
		LeftBracket=38, RightBracket=39, LeftBrace=40, RightBrace=41, LeftParen=42, 
		RightParen=43, Id=44, WS=45;
	public static final int
		RULE_expression = 0, RULE_primary = 1;
	private static String[] makeRuleNames() {
		return new String[] {
			"expression", "primary"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'++'", "'--'", "'/'", "'%'", "'-'", "'<'", "'<='", "'>'", "'>='", 
			"'=='", "'!='", "'&&'", "'||'", "'?'", "':'", "'if'", "'for'", "'while'", 
			"'in'", "'int'", "'double'", "'float'", "'string'", "'bool'", null, null, 
			null, "'true'", "'false'", "'='", null, "'*'", "'+'", "'#'", "';'", "'.'", 
			"','", "'['", "']'", "'{'", "'}'", "'('", "')'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, "If", "FOR", "WHILE", "IN", "Int", "Double", 
			"Float", "String", "Bool", "IntLiteral", "DoubleLiteral", "StringLiteral", 
			"True", "False", "AssignmentOP", "RelationalOP", "Star", "Plus", "Sharp", 
			"SemiColon", "Dot", "Comm", "LeftBracket", "RightBracket", "LeftBrace", 
			"RightBrace", "LeftParen", "RightParen", "Id", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "DynamicDSLScript.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public DynamicDSLScriptParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ExpressionContext extends ParserRuleContext {
		public Token LSB;
		public Token RSB;
		public Token LB;
		public Token RB;
		public Token for_local;
		public Token for_array;
		public Token declare;
		public Token assign;
		public Token prefix;
		public Token bop;
		public Token postfix;
		public PrimaryContext primary() {
			return getRuleContext(PrimaryContext.class,0);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode LeftBracket() { return getToken(DynamicDSLScriptParser.LeftBracket, 0); }
		public TerminalNode RightBracket() { return getToken(DynamicDSLScriptParser.RightBracket, 0); }
		public TerminalNode LeftParen() { return getToken(DynamicDSLScriptParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(DynamicDSLScriptParser.RightParen, 0); }
		public TerminalNode FOR() { return getToken(DynamicDSLScriptParser.FOR, 0); }
		public TerminalNode IN() { return getToken(DynamicDSLScriptParser.IN, 0); }
		public List<TerminalNode> Id() { return getTokens(DynamicDSLScriptParser.Id); }
		public TerminalNode Id(int i) {
			return getToken(DynamicDSLScriptParser.Id, i);
		}
		public TerminalNode AssignmentOP() { return getToken(DynamicDSLScriptParser.AssignmentOP, 0); }
		public TerminalNode Int() { return getToken(DynamicDSLScriptParser.Int, 0); }
		public TerminalNode Double() { return getToken(DynamicDSLScriptParser.Double, 0); }
		public TerminalNode Float() { return getToken(DynamicDSLScriptParser.Float, 0); }
		public TerminalNode String() { return getToken(DynamicDSLScriptParser.String, 0); }
		public TerminalNode Bool() { return getToken(DynamicDSLScriptParser.Bool, 0); }
		public TerminalNode Star() { return getToken(DynamicDSLScriptParser.Star, 0); }
		public TerminalNode Plus() { return getToken(DynamicDSLScriptParser.Plus, 0); }
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 0;
		enterRecursionRule(_localctx, 0, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(29);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				{
				setState(5);
				primary();
				}
				break;
			case 2:
				{
				setState(6);
				((ExpressionContext)_localctx).LSB = match(LeftBracket);
				setState(7);
				expression(0);
				setState(8);
				((ExpressionContext)_localctx).RSB = match(RightBracket);
				}
				break;
			case 3:
				{
				setState(10);
				((ExpressionContext)_localctx).LB = match(LeftParen);
				setState(11);
				expression(0);
				setState(12);
				((ExpressionContext)_localctx).RB = match(RightParen);
				}
				break;
			case 4:
				{
				setState(14);
				match(FOR);
				setState(15);
				((ExpressionContext)_localctx).for_local = match(Id);
				setState(16);
				match(IN);
				setState(17);
				((ExpressionContext)_localctx).for_array = match(Id);
				}
				break;
			case 5:
				{
				setState(18);
				((ExpressionContext)_localctx).declare = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Int) | (1L << Double) | (1L << Float) | (1L << String) | (1L << Bool))) != 0)) ) {
					((ExpressionContext)_localctx).declare = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(19);
				match(Id);
				setState(20);
				((ExpressionContext)_localctx).assign = match(AssignmentOP);
				setState(21);
				expression(11);
				}
				break;
			case 6:
				{
				setState(22);
				((ExpressionContext)_localctx).declare = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Int) | (1L << Double) | (1L << Float) | (1L << String) | (1L << Bool))) != 0)) ) {
					((ExpressionContext)_localctx).declare = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(23);
				match(Id);
				}
				break;
			case 7:
				{
				setState(24);
				match(Id);
				setState(25);
				((ExpressionContext)_localctx).assign = match(AssignmentOP);
				setState(26);
				expression(9);
				}
				break;
			case 8:
				{
				setState(27);
				((ExpressionContext)_localctx).prefix = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==T__0 || _la==T__1) ) {
					((ExpressionContext)_localctx).prefix = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(28);
				expression(7);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(66);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(64);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
					case 1:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(31);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(32);
						((ExpressionContext)_localctx).bop = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__2) | (1L << T__3) | (1L << Star))) != 0)) ) {
							((ExpressionContext)_localctx).bop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(33);
						expression(7);
						}
						break;
					case 2:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(34);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(35);
						((ExpressionContext)_localctx).bop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__4 || _la==Plus) ) {
							((ExpressionContext)_localctx).bop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(36);
						expression(6);
						}
						break;
					case 3:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(37);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(38);
						((ExpressionContext)_localctx).bop = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__5) | (1L << T__6) | (1L << T__7) | (1L << T__8))) != 0)) ) {
							((ExpressionContext)_localctx).bop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(39);
						expression(5);
						}
						break;
					case 4:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(40);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(41);
						((ExpressionContext)_localctx).bop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__9 || _la==T__10) ) {
							((ExpressionContext)_localctx).bop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(42);
						expression(4);
						}
						break;
					case 5:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(43);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(44);
						((ExpressionContext)_localctx).bop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__11 || _la==T__12) ) {
							((ExpressionContext)_localctx).bop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(45);
						expression(3);
						}
						break;
					case 6:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(46);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(47);
						((ExpressionContext)_localctx).bop = match(T__13);
						setState(48);
						expression(0);
						setState(49);
						((ExpressionContext)_localctx).bop = match(T__14);
						setState(50);
						expression(2);
						}
						break;
					case 7:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(52);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(53);
						((ExpressionContext)_localctx).LSB = match(LeftBracket);
						setState(54);
						expression(0);
						setState(55);
						((ExpressionContext)_localctx).RSB = match(RightBracket);
						}
						break;
					case 8:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(57);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(58);
						((ExpressionContext)_localctx).LB = match(LeftParen);
						setState(59);
						expression(0);
						setState(60);
						((ExpressionContext)_localctx).RB = match(RightParen);
						}
						break;
					case 9:
						{
						_localctx = new ExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(62);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(63);
						((ExpressionContext)_localctx).postfix = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__0 || _la==T__1) ) {
							((ExpressionContext)_localctx).postfix = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						}
						break;
					}
					} 
				}
				setState(68);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class PrimaryContext extends ParserRuleContext {
		public Token TF;
		public TerminalNode Id() { return getToken(DynamicDSLScriptParser.Id, 0); }
		public TerminalNode StringLiteral() { return getToken(DynamicDSLScriptParser.StringLiteral, 0); }
		public TerminalNode IntLiteral() { return getToken(DynamicDSLScriptParser.IntLiteral, 0); }
		public TerminalNode DoubleLiteral() { return getToken(DynamicDSLScriptParser.DoubleLiteral, 0); }
		public TerminalNode True() { return getToken(DynamicDSLScriptParser.True, 0); }
		public TerminalNode False() { return getToken(DynamicDSLScriptParser.False, 0); }
		public PrimaryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primary; }
	}

	public final PrimaryContext primary() throws RecognitionException {
		PrimaryContext _localctx = new PrimaryContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_primary);
		int _la;
		try {
			setState(74);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Id:
				enterOuterAlt(_localctx, 1);
				{
				setState(69);
				match(Id);
				}
				break;
			case StringLiteral:
				enterOuterAlt(_localctx, 2);
				{
				setState(70);
				match(StringLiteral);
				}
				break;
			case IntLiteral:
				enterOuterAlt(_localctx, 3);
				{
				setState(71);
				match(IntLiteral);
				}
				break;
			case DoubleLiteral:
				enterOuterAlt(_localctx, 4);
				{
				setState(72);
				match(DoubleLiteral);
				}
				break;
			case True:
			case False:
				enterOuterAlt(_localctx, 5);
				{
				setState(73);
				((PrimaryContext)_localctx).TF = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==True || _la==False) ) {
					((PrimaryContext)_localctx).TF = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 0:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 6);
		case 1:
			return precpred(_ctx, 5);
		case 2:
			return precpred(_ctx, 4);
		case 3:
			return precpred(_ctx, 3);
		case 4:
			return precpred(_ctx, 2);
		case 5:
			return precpred(_ctx, 1);
		case 6:
			return precpred(_ctx, 15);
		case 7:
			return precpred(_ctx, 13);
		case 8:
			return precpred(_ctx, 8);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3/O\4\2\t\2\4\3\t\3"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\5\2 \n\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\7\2C\n\2\f\2\16\2F\13\2\3\3\3\3\3\3\3"+
		"\3\3\3\5\3M\n\3\3\3\2\3\2\4\2\4\2\n\3\2\26\32\3\2\3\4\4\2\5\6\"\"\4\2"+
		"\7\7##\3\2\b\13\3\2\f\r\3\2\16\17\3\2\36\37\2`\2\37\3\2\2\2\4L\3\2\2\2"+
		"\6\7\b\2\1\2\7 \5\4\3\2\b\t\7(\2\2\t\n\5\2\2\2\n\13\7)\2\2\13 \3\2\2\2"+
		"\f\r\7,\2\2\r\16\5\2\2\2\16\17\7-\2\2\17 \3\2\2\2\20\21\7\23\2\2\21\22"+
		"\7.\2\2\22\23\7\25\2\2\23 \7.\2\2\24\25\t\2\2\2\25\26\7.\2\2\26\27\7 "+
		"\2\2\27 \5\2\2\r\30\31\t\2\2\2\31 \7.\2\2\32\33\7.\2\2\33\34\7 \2\2\34"+
		" \5\2\2\13\35\36\t\3\2\2\36 \5\2\2\t\37\6\3\2\2\2\37\b\3\2\2\2\37\f\3"+
		"\2\2\2\37\20\3\2\2\2\37\24\3\2\2\2\37\30\3\2\2\2\37\32\3\2\2\2\37\35\3"+
		"\2\2\2 D\3\2\2\2!\"\f\b\2\2\"#\t\4\2\2#C\5\2\2\t$%\f\7\2\2%&\t\5\2\2&"+
		"C\5\2\2\b\'(\f\6\2\2()\t\6\2\2)C\5\2\2\7*+\f\5\2\2+,\t\7\2\2,C\5\2\2\6"+
		"-.\f\4\2\2./\t\b\2\2/C\5\2\2\5\60\61\f\3\2\2\61\62\7\20\2\2\62\63\5\2"+
		"\2\2\63\64\7\21\2\2\64\65\5\2\2\4\65C\3\2\2\2\66\67\f\21\2\2\678\7(\2"+
		"\289\5\2\2\29:\7)\2\2:C\3\2\2\2;<\f\17\2\2<=\7,\2\2=>\5\2\2\2>?\7-\2\2"+
		"?C\3\2\2\2@A\f\n\2\2AC\t\3\2\2B!\3\2\2\2B$\3\2\2\2B\'\3\2\2\2B*\3\2\2"+
		"\2B-\3\2\2\2B\60\3\2\2\2B\66\3\2\2\2B;\3\2\2\2B@\3\2\2\2CF\3\2\2\2DB\3"+
		"\2\2\2DE\3\2\2\2E\3\3\2\2\2FD\3\2\2\2GM\7.\2\2HM\7\35\2\2IM\7\33\2\2J"+
		"M\7\34\2\2KM\t\t\2\2LG\3\2\2\2LH\3\2\2\2LI\3\2\2\2LJ\3\2\2\2LK\3\2\2\2"+
		"M\5\3\2\2\2\6\37BDL";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}