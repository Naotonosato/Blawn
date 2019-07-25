LLVM_OPTION := `llvm-config --cxxflags --system-libs --ldflags --libs core`

all: blawn
blawn: main.o driver.o ../ast/node.o ./parser.o ./lexer.o ../ast_generator/ast_generator.o ../ast/node.o ../builtins/type.o ../ir_generator/ir_generator.o
	g++ -o blawn main.o driver.o ./parser.o ./lexer.o ../ast_generator/ast_generator.o \
	../builtins/type.o ../ast/node.o ../ir_generator/ir_generator.o -ll $(LLVM_OPTION)

./driver.o: ./driver.cpp
	g++ -c -o driver.o driver.cpp $(LLVM_OPTION) -fexceptions
./parser.o: ./parser.tab.cc ./parser.tab.hh
	g++ -c -o parser.o parser.tab.cc $(LLVM_OPTION) -fexceptions 
./parser.tab.cc ./parser.tab.hh: ./parser.yy
	bison -d -v ./parser.yy -r all --report-file=log.log
./lexer.o: ./lex.yy.cc
	g++ -c -o lexer.o lex.yy.cc $(LLVM_OPTION)
./lex.yy.cc: ./lexer.ll
	flex++ -d ./lexer.ll
./main.o: ./main.cpp
	g++ -c -o main.o main.cpp $(LLVM_OPTION)
../ir_generator/ir_generator.o: ../ir_generator/ir_generator.cpp ../ir_generator/ir_generator.hpp
	g++ -c ../ir_generator/ir_generator.cpp -o ../ir_generator/ir_generator.o  $(LLVM_OPTION)
../ast_generator/ast_generator.o: ../ast_generator/ast_generator.cpp ../ast_generator/ast_generator.hpp
	g++ -c ../ast_generator/ast_generator.cpp -o ../ast_generator/ast_generator.o $(LLVM_OPTION)
../ast/node.o: ../ast/node.cpp
	g++ -c ../ast/node.cpp -o ../ast/node.o  $(LLVM_OPTION)
../builtins/type.o: ../builtins/type.cpp ../builtins/type.hpp
	g++ -c ../builtins/type.cpp -o ../builtins/type.o  $(LLVM_OPTION)