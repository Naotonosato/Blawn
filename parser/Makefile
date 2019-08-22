LLVM_OPTION := `llvm-config --cxxflags --system-libs --ldflags --libs core` -fexceptions -O0 -std=c++14

all: blawn
blawn: main.o driver.o ../ast/node.o ./parser.o ./lexer.o ../ast_generator/ast_generator.o ../ast/node.o ../ir_generator/ir_generator.o ../utils/utils.o ../blawn_context/blawn_context.o
	g++ -g -o blawn main.o driver.o ./parser.o ./lexer.o ../ast_generator/ast_generator.o \
	../ast/node.o ../ir_generator/ir_generator.o ../utils/utils.o ../blawn_context/blawn_context.o -ll $(LLVM_OPTION)

./driver.o: ./driver.cpp ../ir_generator/ir_generator.hpp
	g++ -g -c -o driver.o driver.cpp $(LLVM_OPTION) 
./parser.o: ./parser.tab.cc ./parser.tab.hh
	g++ -g -c -o parser.o parser.tab.cc $(LLVM_OPTION)  
./parser.tab.cc ./parser.tab.hh: ./parser.yy
	bison -d ./parser.yy -r all --report-file=log.log
	python3 patch.py
./lexer.o: ./lex.yy.cc
	g++ -g -c -o lexer.o lex.yy.cc $(LLVM_OPTION)
./lex.yy.cc: ./lexer.ll
	flex++ -d ./lexer.ll
./main.o: ./main.cpp
	g++ -g -c -o main.o main.cpp $(LLVM_OPTION)
../ir_generator/ir_generator.o: ../ir_generator/ir_generator.cpp ../ir_generator/ir_generator.hpp ../ast_generator/node_collector.hpp ../utils/utils.hpp
	g++ -g -c ../ir_generator/ir_generator.cpp -o ../ir_generator/ir_generator.o  $(LLVM_OPTION)
../blawn_context/blawn_context.o: ../blawn_context/blawn_context.cpp ../blawn_context/blawn_context.hpp
	g++ -g -c ../blawn_context/blawn_context.cpp -o ../blawn_context/blawn_context.o $(LLVM_OPTION)
../utils/utils.o: ../utils/utils.cpp
	g++ -g -c ../utils/utils.cpp -o ../utils/utils.o $(LLVM_OPTION)
../ast_generator/ast_generator.o: ../ast_generator/ast_generator.cpp ../ast_generator/ast_generator.hpp ../ast_generator/node_collector.hpp
	g++ -g -c ../ast_generator/ast_generator.cpp -o ../ast_generator/ast_generator.o $(LLVM_OPTION)
../ast/node.o: ../ast/node.cpp ../ast/node.hpp ../ir_generator/ir_generator.hpp
	g++ -g -c ../ast/node.cpp -o ../ast/node.o  $(LLVM_OPTION)

clean:
	rm ../**/*.o
	-fsanitize=address
test:
	llc result.ll
	gcc result.s -o result
	./result
	echo $$?