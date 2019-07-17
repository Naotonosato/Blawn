LLVM_OPTION := `llvm-config --cxxflags --system-libs --ldflags --libs core`

all: blawn
blawn: main.o driver.o ./parser.o ./lexer.o ../ast_generator/ast_generator.o ../ast/node.o ../builtins/type.o
	g++ -o blawn main.o driver.o ./parser.o ./lexer.o ../ast_generator/ast_generator.o ../ast/node.o ../builtins/type.o -ll $(LLVM_OPTION)

./driver.o: ./driver.cpp ./parser.tab.hh
	g++ -c -o driver.o driver.cpp $(LLVM_OPTION) -fexceptions
./parser.o: ./parser.tab.cc ./parser.tab.hh
	g++ -c -o parser.o parser.tab.cc $(LLVM_OPTION) -fexceptions -lfl
./parser.tab.cc ./parser.tab.hh: ./parser.yy
	bison -d -v ./parser.yy -r all --report-file=log.log
./lexer.o: ./lex.yy.cc
	g++ -c -o lexer.o lex.yy.cc $(LLVM_OPTION) -lfl
./lex.yy.cc: ./lexer.ll
	flex++ -d ./lexer.ll
./main.o: ./main.cpp
	g++ -c -o main.o main.cpp $(LLVM_OPTION)
../ast_generator/ast_generator.o: ../ast_generator/ast_generator.cpp 
	g++ -c ../ast_generator/ast_generator.cpp -o ../ast_generator/ast_generator.o $(LLVM_OPTION)
../ast/node.o: ../ast/node.cpp
	g++ -c ../ast/node.cpp -o ../ast/node.o
../builtins/type.o: ../builtins/type.cpp
	g++ -c ../builtins/type.cpp -o ../builtins/type.o