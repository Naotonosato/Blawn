LLVM_OPTION := `llvm-config --cxxflags --system-libs --ldflags --libs core` -fexceptions -O0 -std=c++14 

all: blawn
blawn: builtins/builtins.o errors/errors.o parser/main.o parser/driver.o ast/node.o parser/parser.o parser/lexer.o ast_generator/ast_generator.o ast/node.o ir_generator/ir_generator.o utils/utils.o blawn_context/blawn_context.o
	g++ -g -o blawn ../build/main.o ../build/driver.o ../build/parser.o ../build/lexer.o ../build/ast_generator.o \
	../build/node.o ../build/builtins.o ../build/ir_generator.o ../build/utils.o ../build/errors.o ../build/blawn_context.o -ll $(LLVM_OPTION)

parser/driver.o: ../compiler/parser/driver.cpp ../compiler/ir_generator/ir_generator.hpp
	g++ -g -c -o ../build/driver.o ../compiler/parser/driver.cpp $(LLVM_OPTION) 
parser/parser.o: ../compiler/parser/parser.tab.cc ../compiler/parser/parser.tab.hh
	g++ -g -c -o ../build/parser.o ../compiler/parser/parser.tab.cc $(LLVM_OPTION)  
parser/parser.tab.cc ../compiler/parser/parser.tab.hh: ../compiler/parser/parser.yy
	bison -d ../compiler/parser/parser.yy -r all --report-file=log.log
	python3 ../compiler/parser/patch.py
parser/lexer.o: ../compiler/parser/lex.yy.cc
	g++ -g -c -o ../build/lexer.o ../compiler/parser/lex.yy.cc $(LLVM_OPTION)
parser/lex.yy.cc: ../compiler/parser/lexer.ll
	flex++ -d ../compiler/parser/lexer.ll
parser/main.o: ../compiler/parser/main.cpp
	g++ -g -c -o ../build/main.o ../compiler/parser/main.cpp $(LLVM_OPTION)
ir_generator/ir_generator.o: ../compiler/ir_generator/ir_generator.cpp ../compiler/ir_generator/ir_generator.hpp ../compiler/ast_generator/node_collector.hpp ../compiler/utils/utils.hpp
	g++ -g -c ../compiler/ir_generator/ir_generator.cpp -o ../build/ir_generator.o  $(LLVM_OPTION)
blawn_context/blawn_context.o: ../compiler/blawn_context/blawn_context.cpp ../compiler/blawn_context/blawn_context.hpp
	g++ -g -c ../compiler/blawn_context/blawn_context.cpp -o ../build/blawn_context.o $(LLVM_OPTION)
utils/utils.o: ../compiler/utils/utils.cpp
	g++ -g -c ../compiler/utils/utils.cpp -o ../build/utils.o $(LLVM_OPTION)
builtins/builtins.o: ../compiler/builtins/builtins.cpp ../compiler/builtins/builtins.hpp ../compiler/builtins/builtins.c
	g++ -g -c ../compiler/builtins/builtins.cpp -o ../build/builtins.o $(LLVM_OPTION)
	clang -c -S -emit-llvm ../compiler/builtins/builtins.c -o ../build/builtins.ll
ast_generator/ast_generator.o: ../compiler/ast_generator/ast_generator.cpp ../compiler/ast_generator/ast_generator.hpp ../compiler/ast_generator/node_collector.hpp
	g++ -g -c ../compiler/ast_generator/ast_generator.cpp -o ../build/ast_generator.o $(LLVM_OPTION)
ast/node.o: ../compiler/ast/node.cpp ../compiler/ast/node.hpp ../compiler/ir_generator/ir_generator.hpp
	g++ -g -c ../compiler/ast/node.cpp -o ../build/node.o  $(LLVM_OPTION)
errors/errors.o: ../compiler/errors/errors.cpp ../compiler/errors/errors.hpp
	g++ -g -c ../compiler/errors/errors.cpp -o ../build/errors.o


clean:
	rm ../build/*.o
	rm ../build/*.ll
	-fsanitize=address
test:
	./blawn
	lli result.ll