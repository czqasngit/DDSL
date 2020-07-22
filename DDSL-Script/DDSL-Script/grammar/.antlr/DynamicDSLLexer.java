// Generated from /Volumes/Work/dev/DynamicDSL/DynamicDSL/runtime/grammar/DynamicDSLLexer.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class DynamicDSLLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		If=1, FOR=2, WHILE=3, IN=4, Int=5, Double=6, Float=7, String=8, Bool=9, 
		IntLiteral=10, DoubleLiteral=11, StringLiteral=12, True=13, False=14, 
		AssignmentOP=15, RelationalOP=16, Star=17, Plus=18, Sharp=19, SemiColon=20, 
		Dot=21, Comm=22, LeftBracket=23, RightBracket=24, LeftBrace=25, RightBrace=26, 
		LeftParen=27, RightParen=28, Id=29, WS=30;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"If", "FOR", "WHILE", "IN", "Int", "Double", "Float", "String", "Bool", 
			"IntLiteral", "DoubleLiteral", "StringLiteral", "True", "False", "AssignmentOP", 
			"RelationalOP", "Star", "Plus", "Sharp", "SemiColon", "Dot", "Comm", 
			"LeftBracket", "RightBracket", "LeftBrace", "RightBrace", "LeftParen", 
			"RightParen", "Id", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'if'", "'for'", "'while'", "'in'", "'int'", "'double'", "'float'", 
			"'string'", "'bool'", null, null, null, "'true'", "'false'", "'='", null, 
			"'*'", "'+'", "'#'", "';'", "'.'", "','", "'['", "']'", "'{'", "'}'", 
			"'('", "')'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "If", "FOR", "WHILE", "IN", "Int", "Double", "Float", "String", 
			"Bool", "IntLiteral", "DoubleLiteral", "StringLiteral", "True", "False", 
			"AssignmentOP", "RelationalOP", "Star", "Plus", "Sharp", "SemiColon", 
			"Dot", "Comm", "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", 
			"LeftParen", "RightParen", "Id", "WS"
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


	public DynamicDSLLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "DynamicDSLLexer.g4"; }

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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2 \u00c9\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\3\2\3\2\3"+
		"\2\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\6\3\6\3\6\3\6"+
		"\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3"+
		"\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\13\6\13n\n\13\r\13\16\13o\3\f\6\fs\n"+
		"\f\r\f\16\ft\3\f\3\f\6\fy\n\f\r\f\16\fz\3\r\3\r\7\r\177\n\r\f\r\16\r\u0082"+
		"\13\r\3\r\3\r\3\r\7\r\u0087\n\r\f\r\16\r\u008a\13\r\3\r\5\r\u008d\n\r"+
		"\3\16\3\16\3\16\3\16\3\16\3\17\3\17\3\17\3\17\3\17\3\17\3\20\3\20\3\21"+
		"\3\21\3\21\3\21\3\21\3\21\5\21\u00a2\n\21\3\22\3\22\3\23\3\23\3\24\3\24"+
		"\3\25\3\25\3\26\3\26\3\27\3\27\3\30\3\30\3\31\3\31\3\32\3\32\3\33\3\33"+
		"\3\34\3\34\3\35\3\35\3\36\3\36\7\36\u00be\n\36\f\36\16\36\u00c1\13\36"+
		"\3\37\6\37\u00c4\n\37\r\37\16\37\u00c5\3\37\3\37\4\u0080\u0088\2 \3\3"+
		"\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21"+
		"!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37= \3"+
		"\2\6\3\2\62;\5\2C\\aac|\6\2\62;C\\aac|\5\2\13\f\17\17\"\"\2\u00d3\2\3"+
		"\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2"+
		"\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31"+
		"\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2"+
		"\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2"+
		"\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2"+
		"\2\2=\3\2\2\2\3?\3\2\2\2\5B\3\2\2\2\7F\3\2\2\2\tL\3\2\2\2\13O\3\2\2\2"+
		"\rS\3\2\2\2\17Z\3\2\2\2\21`\3\2\2\2\23g\3\2\2\2\25m\3\2\2\2\27r\3\2\2"+
		"\2\31\u008c\3\2\2\2\33\u008e\3\2\2\2\35\u0093\3\2\2\2\37\u0099\3\2\2\2"+
		"!\u00a1\3\2\2\2#\u00a3\3\2\2\2%\u00a5\3\2\2\2\'\u00a7\3\2\2\2)\u00a9\3"+
		"\2\2\2+\u00ab\3\2\2\2-\u00ad\3\2\2\2/\u00af\3\2\2\2\61\u00b1\3\2\2\2\63"+
		"\u00b3\3\2\2\2\65\u00b5\3\2\2\2\67\u00b7\3\2\2\29\u00b9\3\2\2\2;\u00bb"+
		"\3\2\2\2=\u00c3\3\2\2\2?@\7k\2\2@A\7h\2\2A\4\3\2\2\2BC\7h\2\2CD\7q\2\2"+
		"DE\7t\2\2E\6\3\2\2\2FG\7y\2\2GH\7j\2\2HI\7k\2\2IJ\7n\2\2JK\7g\2\2K\b\3"+
		"\2\2\2LM\7k\2\2MN\7p\2\2N\n\3\2\2\2OP\7k\2\2PQ\7p\2\2QR\7v\2\2R\f\3\2"+
		"\2\2ST\7f\2\2TU\7q\2\2UV\7w\2\2VW\7d\2\2WX\7n\2\2XY\7g\2\2Y\16\3\2\2\2"+
		"Z[\7h\2\2[\\\7n\2\2\\]\7q\2\2]^\7c\2\2^_\7v\2\2_\20\3\2\2\2`a\7u\2\2a"+
		"b\7v\2\2bc\7t\2\2cd\7k\2\2de\7p\2\2ef\7i\2\2f\22\3\2\2\2gh\7d\2\2hi\7"+
		"q\2\2ij\7q\2\2jk\7n\2\2k\24\3\2\2\2ln\t\2\2\2ml\3\2\2\2no\3\2\2\2om\3"+
		"\2\2\2op\3\2\2\2p\26\3\2\2\2qs\t\2\2\2rq\3\2\2\2st\3\2\2\2tr\3\2\2\2t"+
		"u\3\2\2\2uv\3\2\2\2vx\5+\26\2wy\t\2\2\2xw\3\2\2\2yz\3\2\2\2zx\3\2\2\2"+
		"z{\3\2\2\2{\30\3\2\2\2|\u0080\7$\2\2}\177\13\2\2\2~}\3\2\2\2\177\u0082"+
		"\3\2\2\2\u0080\u0081\3\2\2\2\u0080~\3\2\2\2\u0081\u0083\3\2\2\2\u0082"+
		"\u0080\3\2\2\2\u0083\u008d\7$\2\2\u0084\u0088\7)\2\2\u0085\u0087\13\2"+
		"\2\2\u0086\u0085\3\2\2\2\u0087\u008a\3\2\2\2\u0088\u0089\3\2\2\2\u0088"+
		"\u0086\3\2\2\2\u0089\u008b\3\2\2\2\u008a\u0088\3\2\2\2\u008b\u008d\7)"+
		"\2\2\u008c|\3\2\2\2\u008c\u0084\3\2\2\2\u008d\32\3\2\2\2\u008e\u008f\7"+
		"v\2\2\u008f\u0090\7t\2\2\u0090\u0091\7w\2\2\u0091\u0092\7g\2\2\u0092\34"+
		"\3\2\2\2\u0093\u0094\7h\2\2\u0094\u0095\7c\2\2\u0095\u0096\7n\2\2\u0096"+
		"\u0097\7u\2\2\u0097\u0098\7g\2\2\u0098\36\3\2\2\2\u0099\u009a\7?\2\2\u009a"+
		" \3\2\2\2\u009b\u00a2\7@\2\2\u009c\u009d\7@\2\2\u009d\u00a2\7?\2\2\u009e"+
		"\u00a2\7>\2\2\u009f\u00a0\7>\2\2\u00a0\u00a2\7?\2\2\u00a1\u009b\3\2\2"+
		"\2\u00a1\u009c\3\2\2\2\u00a1\u009e\3\2\2\2\u00a1\u009f\3\2\2\2\u00a2\""+
		"\3\2\2\2\u00a3\u00a4\7,\2\2\u00a4$\3\2\2\2\u00a5\u00a6\7-\2\2\u00a6&\3"+
		"\2\2\2\u00a7\u00a8\7%\2\2\u00a8(\3\2\2\2\u00a9\u00aa\7=\2\2\u00aa*\3\2"+
		"\2\2\u00ab\u00ac\7\60\2\2\u00ac,\3\2\2\2\u00ad\u00ae\7.\2\2\u00ae.\3\2"+
		"\2\2\u00af\u00b0\7]\2\2\u00b0\60\3\2\2\2\u00b1\u00b2\7_\2\2\u00b2\62\3"+
		"\2\2\2\u00b3\u00b4\7}\2\2\u00b4\64\3\2\2\2\u00b5\u00b6\7\177\2\2\u00b6"+
		"\66\3\2\2\2\u00b7\u00b8\7*\2\2\u00b88\3\2\2\2\u00b9\u00ba\7+\2\2\u00ba"+
		":\3\2\2\2\u00bb\u00bf\t\3\2\2\u00bc\u00be\t\4\2\2\u00bd\u00bc\3\2\2\2"+
		"\u00be\u00c1\3\2\2\2\u00bf\u00bd\3\2\2\2\u00bf\u00c0\3\2\2\2\u00c0<\3"+
		"\2\2\2\u00c1\u00bf\3\2\2\2\u00c2\u00c4\t\5\2\2\u00c3\u00c2\3\2\2\2\u00c4"+
		"\u00c5\3\2\2\2\u00c5\u00c3\3\2\2\2\u00c5\u00c6\3\2\2\2\u00c6\u00c7\3\2"+
		"\2\2\u00c7\u00c8\b\37\2\2\u00c8>\3\2\2\2\r\2otz\u0080\u0088\u008c\u00a1"+
		"\u00bd\u00bf\u00c5\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}