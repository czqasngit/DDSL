lexer grammar DynamicDSLLexer;

//关键字
If: 'if';
FOR: 'for';
WHILE: 'while';
IN: 'in';

/// 基础数据类型
Int: 'int';
Double: 'double';
Float: 'float';
String: 'string';
Bool: 'bool';

//字面量
IntLiteral: [0-9]+;
DoubleLiteral: [0-9]+ Dot [0-9]+;
StringLiteral: ('"' .*? '"') | ('\'' .*? '\''); //字符串字面量
True: 'true';
False: 'false';

//操作符
AssignmentOP: '=';
RelationalOP: '>' | '>=' | '<' | '<=';
Star: '*';
Plus: '+';
Sharp: '#';
SemiColon: ';';
Dot: '.';
Comm: ',';
LeftBracket: '[';
RightBracket: ']';
LeftBrace: '{';
RightBrace: '}';
LeftParen: '(';
RightParen: ')';

//标识符
Id: [a-zA-Z_] ([a-zA-Z_] | [0-9])*;

//空白字符，抛弃
WS: [ \t\r\n]+ -> skip;