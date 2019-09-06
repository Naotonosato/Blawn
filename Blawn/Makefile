LLVM_OPTION := `llvm-config --cxxflags --system-libs --ldflags --libs core` -fexceptions -O3 -std=c++14 

all: blawn
blawn: ../compiler/builtins/builtins.o ../compiler/errors/errors.o ../compiler/parser/main.o ../compiler/parser/driver.o ../compiler/ast/node.o ../compiler/parser/parser.o ../compiler/parser/lexer.o ../compiler/ast_generator/ast_generator.o ../compiler/ast/node.o ../compiler/ir_generator/ir_generator.o ../compiler/utils/utils.o ../compiler/blawn_context/blawn_context.o
	g++ -g -o blawn ../compiler/parser/main.o ../compiler/parser/driver.o ../compiler/parser/parser.o ../compiler/parser/lexer.o ../compiler/ast_generator/ast_generator.o \
	../compiler/ast/node.o ../compiler/builtins/builtins.o ../compiler/ir_generator/ir_generator.o ../compiler/utils/utils.o ../compiler/errors/errors.o ../compiler/blawn_context/blawn_context.o -ll $(LLVM_OPTION)

../compiler/parser/driver.o: ../compiler/parser/driver.cpp ../compiler/ir_generator/ir_generator.hpp
	g++ -g -c -o ../compiler/parser/driver.o ../compiler/parser/driver.cpp $(LLVM_OPTION) 
../compiler/parser/parser.o: ../compiler/parser/parser.tab.cc ../compiler/parser/parser.tab.hh
	g++ -g -c -o ../compiler/parser/parser.o ../compiler/parser/parser.tab.cc $(LLVM_OPTION)  
../compiler/parser/parser.tab.cc ../compiler/parser/parser.tab.hh: ../compiler/parser/parser.yy
	bison -d ../compiler/parser/parser.yy -r all --report-file=log.log
	python3 ../compiler/parser/patch.py
../compiler/parser/lexer.o: ../compiler/parser/lex.yy.cc
	g++ -g -c -o ../compiler/parser/lexer.o ../compiler/parser/lex.yy.cc $(LLVM_OPTION)
../compiler/parser/lex.yy.cc: ../compiler/parser/lexer.ll
	flex++ -d ../compiler/parser/lexer.ll
../compiler/parser/main.o: ../compiler/parser/main.cpp
	g++ -g -c -o ../compiler/parser/main.o ../compiler/parser/main.cpp $(LLVM_OPTION)
../compiler/ir_generator/ir_generator.o: ../compiler/ir_generator/ir_generator.cpp ../compiler/ir_generator/ir_generator.hpp ../compiler/ast_generator/node_collector.hpp ../compiler/utils/utils.hpp
	g++ -g -c ../compiler/ir_generator/ir_generator.cpp -o ../compiler/ir_generator/ir_generator.o  $(LLVM_OPTION)
../compiler/blawn_context/blawn_context.o: ../compiler/blawn_context/blawn_context.cpp ../compiler/blawn_context/blawn_context.hpp
	g++ -g -c ../compiler/blawn_context/blawn_context.cpp -o ../compiler/blawn_context/blawn_context.o $(LLVM_OPTION)
../compiler/utils/utils.o: ../compiler/utils/utils.cpp
	g++ -g -c ../compiler/utils/utils.cpp -o ../compiler/utils/utils.o $(LLVM_OPTION)
../compiler/builtins/builtins.o: ../compiler/builtins/builtins.cpp ../compiler/builtins/builtins.hpp ../compiler/builtins/builtins.c
	g++ -g -c ../compiler/builtins/builtins.cpp -o ../compiler/builtins/builtins.o $(LLVM_OPTION)
	clang -c -S -emit-llvm ../compiler/builtins/builtins.c -o ../compiler/builtins/builtins.ll
../compiler/ast_generator/ast_generator.o: ../compiler/ast_generator/ast_generator.cpp ../compiler/ast_generator/ast_generator.hpp ../compiler/ast_generator/node_collector.hpp
	g++ -g -c ../compiler/ast_generator/ast_generator.cpp -o ../compiler/ast_generator/ast_generator.o $(LLVM_OPTION)
../compiler/ast/node.o: ../compiler/ast/node.cpp ../compiler/ast/node.hpp ../compiler/ir_generator/ir_generator.hpp
	g++ -g -c ../compiler/ast/node.cpp -o ../compiler/ast/node.o  $(LLVM_OPTION)
../compiler/errors/errors.o: ../compiler/errors/errors.cpp ../compiler/errors/errors.hpp
	g++ -g -c ../compiler/errors/errors.cpp -o ../compiler/errors/errors.o


clean:
	rm ../compiler/**/*.o
	-fsanitize=address
test:
	./blawn
	lli result.ll