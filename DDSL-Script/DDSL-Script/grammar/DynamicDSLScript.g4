grammar DynamicDSLScript;
import DynamicDSLLexer;

/// 表达式,按右边产生式的顺序来依次优先推导
expression:
	primary
	| LSB = '[' expression RSB = ']'
	| expression LSB = '[' expression RSB = ']'
	| LB = '(' expression RB = ')'
	| expression LB = '(' expression RB = ')'
	| FOR for_local = Id IN for_array = Id
	| declare = (Int | Double | Float | String | Bool) Id assign = '=' expression // 申明变量并赋值
	| declare = (Int | Double | Float | String | Bool) Id /// 申明变量,没有赋值
	| Id assign = '=' expression /// 赋值,需要查变量是否申明
	| expression postfix = ('++' | '--')
	| prefix = ('++' | '--') expression
	| expression bop = ('*' | '/' | '%') expression
	| expression bop = ('+' | '-') expression
	| expression bop = ('<' | '<=' | '>' | '>=') expression
	| expression bop = ('==' | '!=') expression
	| expression bop = ('&&' | '||') expression
	| expression bop = '?' expression bop = ':' expression;

primary:
	Id
	| StringLiteral
	| IntLiteral
	| DoubleLiteral
	| TF = (True | False);
