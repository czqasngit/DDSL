// Generated from /Volumes/Work/dev/DynamicDSL/DynamicDSL/runtime/grammar/DynamicDSLScript.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class DynamicDSLScriptLexer extends Lexer {
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
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "If", "FOR", "WHILE", 
			"IN", "Int", "Double", "Float", "String", "Bool", "IntLiteral", "DoubleLiteral", 
			"StringLiteral", "True", "False", "AssignmentOP", "RelationalOP", "Star", 
			"Plus", "Sharp", "SemiColon", "Dot", "Comm", "LeftBracket", "RightBracket", 
			"LeftBrace", "RightBrace", "LeftParen", "RightParen", "Id", "WS"
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


	public DynamicDSLScriptLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "DynamicDSLScript.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2/\u010d\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\3\2\3\2\3\2\3\3\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3"+
		"\7\3\b\3\b\3\b\3\t\3\t\3\n\3\n\3\n\3\13\3\13\3\13\3\f\3\f\3\f\3\r\3\r"+
		"\3\r\3\16\3\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\21\3\22\3\22\3\22"+
		"\3\22\3\23\3\23\3\23\3\23\3\23\3\23\3\24\3\24\3\24\3\25\3\25\3\25\3\25"+
		"\3\26\3\26\3\26\3\26\3\26\3\26\3\26\3\27\3\27\3\27\3\27\3\27\3\27\3\30"+
		"\3\30\3\30\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3\31\3\31\3\32\6\32\u00b2"+
		"\n\32\r\32\16\32\u00b3\3\33\6\33\u00b7\n\33\r\33\16\33\u00b8\3\33\3\33"+
		"\6\33\u00bd\n\33\r\33\16\33\u00be\3\34\3\34\7\34\u00c3\n\34\f\34\16\34"+
		"\u00c6\13\34\3\34\3\34\3\34\7\34\u00cb\n\34\f\34\16\34\u00ce\13\34\3\34"+
		"\5\34\u00d1\n\34\3\35\3\35\3\35\3\35\3\35\3\36\3\36\3\36\3\36\3\36\3\36"+
		"\3\37\3\37\3 \3 \3 \3 \3 \3 \5 \u00e6\n \3!\3!\3\"\3\"\3#\3#\3$\3$\3%"+
		"\3%\3&\3&\3\'\3\'\3(\3(\3)\3)\3*\3*\3+\3+\3,\3,\3-\3-\7-\u0102\n-\f-\16"+
		"-\u0105\13-\3.\6.\u0108\n.\r.\16.\u0109\3.\3.\4\u00c4\u00cc\2/\3\3\5\4"+
		"\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22"+
		"#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37= ?!A\"C"+
		"#E$G%I&K\'M(O)Q*S+U,W-Y.[/\3\2\6\3\2\62;\5\2C\\aac|\6\2\62;C\\aac|\5\2"+
		"\13\f\17\17\"\"\2\u0117\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2"+
		"\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25"+
		"\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2"+
		"\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2"+
		"\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3"+
		"\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2"+
		"\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2"+
		"Q\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\3]\3"+
		"\2\2\2\5`\3\2\2\2\7c\3\2\2\2\te\3\2\2\2\13g\3\2\2\2\ri\3\2\2\2\17k\3\2"+
		"\2\2\21n\3\2\2\2\23p\3\2\2\2\25s\3\2\2\2\27v\3\2\2\2\31y\3\2\2\2\33|\3"+
		"\2\2\2\35\177\3\2\2\2\37\u0081\3\2\2\2!\u0083\3\2\2\2#\u0086\3\2\2\2%"+
		"\u008a\3\2\2\2\'\u0090\3\2\2\2)\u0093\3\2\2\2+\u0097\3\2\2\2-\u009e\3"+
		"\2\2\2/\u00a4\3\2\2\2\61\u00ab\3\2\2\2\63\u00b1\3\2\2\2\65\u00b6\3\2\2"+
		"\2\67\u00d0\3\2\2\29\u00d2\3\2\2\2;\u00d7\3\2\2\2=\u00dd\3\2\2\2?\u00e5"+
		"\3\2\2\2A\u00e7\3\2\2\2C\u00e9\3\2\2\2E\u00eb\3\2\2\2G\u00ed\3\2\2\2I"+
		"\u00ef\3\2\2\2K\u00f1\3\2\2\2M\u00f3\3\2\2\2O\u00f5\3\2\2\2Q\u00f7\3\2"+
		"\2\2S\u00f9\3\2\2\2U\u00fb\3\2\2\2W\u00fd\3\2\2\2Y\u00ff\3\2\2\2[\u0107"+
		"\3\2\2\2]^\7-\2\2^_\7-\2\2_\4\3\2\2\2`a\7/\2\2ab\7/\2\2b\6\3\2\2\2cd\7"+
		"\61\2\2d\b\3\2\2\2ef\7\'\2\2f\n\3\2\2\2gh\7/\2\2h\f\3\2\2\2ij\7>\2\2j"+
		"\16\3\2\2\2kl\7>\2\2lm\7?\2\2m\20\3\2\2\2no\7@\2\2o\22\3\2\2\2pq\7@\2"+
		"\2qr\7?\2\2r\24\3\2\2\2st\7?\2\2tu\7?\2\2u\26\3\2\2\2vw\7#\2\2wx\7?\2"+
		"\2x\30\3\2\2\2yz\7(\2\2z{\7(\2\2{\32\3\2\2\2|}\7~\2\2}~\7~\2\2~\34\3\2"+
		"\2\2\177\u0080\7A\2\2\u0080\36\3\2\2\2\u0081\u0082\7<\2\2\u0082 \3\2\2"+
		"\2\u0083\u0084\7k\2\2\u0084\u0085\7h\2\2\u0085\"\3\2\2\2\u0086\u0087\7"+
		"h\2\2\u0087\u0088\7q\2\2\u0088\u0089\7t\2\2\u0089$\3\2\2\2\u008a\u008b"+
		"\7y\2\2\u008b\u008c\7j\2\2\u008c\u008d\7k\2\2\u008d\u008e\7n\2\2\u008e"+
		"\u008f\7g\2\2\u008f&\3\2\2\2\u0090\u0091\7k\2\2\u0091\u0092\7p\2\2\u0092"+
		"(\3\2\2\2\u0093\u0094\7k\2\2\u0094\u0095\7p\2\2\u0095\u0096\7v\2\2\u0096"+
		"*\3\2\2\2\u0097\u0098\7f\2\2\u0098\u0099\7q\2\2\u0099\u009a\7w\2\2\u009a"+
		"\u009b\7d\2\2\u009b\u009c\7n\2\2\u009c\u009d\7g\2\2\u009d,\3\2\2\2\u009e"+
		"\u009f\7h\2\2\u009f\u00a0\7n\2\2\u00a0\u00a1\7q\2\2\u00a1\u00a2\7c\2\2"+
		"\u00a2\u00a3\7v\2\2\u00a3.\3\2\2\2\u00a4\u00a5\7u\2\2\u00a5\u00a6\7v\2"+
		"\2\u00a6\u00a7\7t\2\2\u00a7\u00a8\7k\2\2\u00a8\u00a9\7p\2\2\u00a9\u00aa"+
		"\7i\2\2\u00aa\60\3\2\2\2\u00ab\u00ac\7d\2\2\u00ac\u00ad\7q\2\2\u00ad\u00ae"+
		"\7q\2\2\u00ae\u00af\7n\2\2\u00af\62\3\2\2\2\u00b0\u00b2\t\2\2\2\u00b1"+
		"\u00b0\3\2\2\2\u00b2\u00b3\3\2\2\2\u00b3\u00b1\3\2\2\2\u00b3\u00b4\3\2"+
		"\2\2\u00b4\64\3\2\2\2\u00b5\u00b7\t\2\2\2\u00b6\u00b5\3\2\2\2\u00b7\u00b8"+
		"\3\2\2\2\u00b8\u00b6\3\2\2\2\u00b8\u00b9\3\2\2\2\u00b9\u00ba\3\2\2\2\u00ba"+
		"\u00bc\5I%\2\u00bb\u00bd\t\2\2\2\u00bc\u00bb\3\2\2\2\u00bd\u00be\3\2\2"+
		"\2\u00be\u00bc\3\2\2\2\u00be\u00bf\3\2\2\2\u00bf\66\3\2\2\2\u00c0\u00c4"+
		"\7$\2\2\u00c1\u00c3\13\2\2\2\u00c2\u00c1\3\2\2\2\u00c3\u00c6\3\2\2\2\u00c4"+
		"\u00c5\3\2\2\2\u00c4\u00c2\3\2\2\2\u00c5\u00c7\3\2\2\2\u00c6\u00c4\3\2"+
		"\2\2\u00c7\u00d1\7$\2\2\u00c8\u00cc\7)\2\2\u00c9\u00cb\13\2\2\2\u00ca"+
		"\u00c9\3\2\2\2\u00cb\u00ce\3\2\2\2\u00cc\u00cd\3\2\2\2\u00cc\u00ca\3\2"+
		"\2\2\u00cd\u00cf\3\2\2\2\u00ce\u00cc\3\2\2\2\u00cf\u00d1\7)\2\2\u00d0"+
		"\u00c0\3\2\2\2\u00d0\u00c8\3\2\2\2\u00d18\3\2\2\2\u00d2\u00d3\7v\2\2\u00d3"+
		"\u00d4\7t\2\2\u00d4\u00d5\7w\2\2\u00d5\u00d6\7g\2\2\u00d6:\3\2\2\2\u00d7"+
		"\u00d8\7h\2\2\u00d8\u00d9\7c\2\2\u00d9\u00da\7n\2\2\u00da\u00db\7u\2\2"+
		"\u00db\u00dc\7g\2\2\u00dc<\3\2\2\2\u00dd\u00de\7?\2\2\u00de>\3\2\2\2\u00df"+
		"\u00e6\7@\2\2\u00e0\u00e1\7@\2\2\u00e1\u00e6\7?\2\2\u00e2\u00e6\7>\2\2"+
		"\u00e3\u00e4\7>\2\2\u00e4\u00e6\7?\2\2\u00e5\u00df\3\2\2\2\u00e5\u00e0"+
		"\3\2\2\2\u00e5\u00e2\3\2\2\2\u00e5\u00e3\3\2\2\2\u00e6@\3\2\2\2\u00e7"+
		"\u00e8\7,\2\2\u00e8B\3\2\2\2\u00e9\u00ea\7-\2\2\u00eaD\3\2\2\2\u00eb\u00ec"+
		"\7%\2\2\u00ecF\3\2\2\2\u00ed\u00ee\7=\2\2\u00eeH\3\2\2\2\u00ef\u00f0\7"+
		"\60\2\2\u00f0J\3\2\2\2\u00f1\u00f2\7.\2\2\u00f2L\3\2\2\2\u00f3\u00f4\7"+
		"]\2\2\u00f4N\3\2\2\2\u00f5\u00f6\7_\2\2\u00f6P\3\2\2\2\u00f7\u00f8\7}"+
		"\2\2\u00f8R\3\2\2\2\u00f9\u00fa\7\177\2\2\u00faT\3\2\2\2\u00fb\u00fc\7"+
		"*\2\2\u00fcV\3\2\2\2\u00fd\u00fe\7+\2\2\u00feX\3\2\2\2\u00ff\u0103\t\3"+
		"\2\2\u0100\u0102\t\4\2\2\u0101\u0100\3\2\2\2\u0102\u0105\3\2\2\2\u0103"+
		"\u0101\3\2\2\2\u0103\u0104\3\2\2\2\u0104Z\3\2\2\2\u0105\u0103\3\2\2\2"+
		"\u0106\u0108\t\5\2\2\u0107\u0106\3\2\2\2\u0108\u0109\3\2\2\2\u0109\u0107"+
		"\3\2\2\2\u0109\u010a\3\2\2\2\u010a\u010b\3\2\2\2\u010b\u010c\b.\2\2\u010c"+
		"\\\3\2\2\2\r\2\u00b3\u00b8\u00be\u00c4\u00cc\u00d0\u00e5\u0101\u0103\u0109"+
		"\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}