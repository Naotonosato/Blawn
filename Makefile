all: blawn
blawn: ./parser/generator/parser.tab.cc ./parser/generator/lex.yy.c
	g++ -o blawn ./parser/generator/parser.tab.cc ./parser/generator/lex.yy.c -lfl
./parser/generator/blawn.tab.c: ./parser/generator/parser.yy
	bison -d ./parser/generator/parser.yy 
./parser/generator/lex.yy.c: ./parser/generator/lexer.ll
	flex -o  ./parser/generator/lexer.ll