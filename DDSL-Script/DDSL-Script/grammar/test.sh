clear

rm -rf *.class
rm -rf *.java
rm -rf *.interp
rm -rf *.tokens
rm -rf *.h
rm -rf *.cpp

source ~/.bash_profile
antlr4 -Dlanguage=Cpp -visitor -no-listener DynamicDSLScript.g4

# antlr4 DynamicDSLScript.g4
# javac *.java
# grun DynamicDSLScript expression -gui

# antlr4 DynamicDSLLexer.g4
# javac *.java
# grun DynamicDSLLexer tokens -tokens Hello.play
