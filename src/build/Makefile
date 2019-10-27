LLVM_LINK_OPTION := `llvm-config --cxxflags --system-libs --ldflags --libs core` -fexceptions -O0 -std=gnu++17 -std=c++17 -lstdc++fs
LLVM_OPTION := -I/usr/lib/llvm-6.0/include
CC := g++ -std=gnu++17 -std=c++17 -lstdc++fs -O0
all: blawn
blawn: builtins.o errors.o main.o compiler.o driver.o node.o parser.o lexer.o ast_generator.o node.o ir_generator.o utils.o blawn_context.o errors.o
	$(CC) -g -o blawn main.o compiler.o driver.o parser.o lexer.o ast_generator.o \
	./node.o builtins.o ir_generator.o utils.o errors.o blawn_context.o -ll $(LLVM_LINK_OPTION)
	cp blawn ../../blawn/blawn
	cp -r ../tools ../../blawn/tools
driver.o: ../compiler/parser/driver.cpp ../compiler/ir_generator/ir_generator.hpp
	$(CC) -g -c -o driver.o ../compiler/parser/driver.cpp $(LLVM_OPTION) 
parser.o: ../compiler/parser/parser.tab.cc ../compiler/parser/parser.tab.hh
	$(CC) -g -c -o parser.o ../compiler/parser/parser.tab.cc $(LLVM_OPTION)  
parser/parser.tab.cc ../compiler/parser/parser.tab.hh: ../compiler/parser/parser.yy
	cd ../compiler/parser && bison -d parser.yy -r all --report-file=log.log
	cd ../compiler/parser && python3 patch.py
lexer.o: ../compiler/parser/lexer.ll
	cd ../compiler/parser && flex++ -d lexer.ll
	$(CC) -g -c -o lexer.o ../compiler/parser/lex.yy.cc $(LLVM_OPTION)
main.o: ../compiler/parser/main.cpp
	$(CC) -g -c -o main.o ../compiler/parser/main.cpp $(LLVM_OPTION)
compiler.o: ../compiler/compiler/compiler.cpp ../compiler/compiler/compiler.hpp
	$(CC) -g -c -o compiler.o ../compiler/compiler/compiler.cpp $(LLVM_OPTION)
ir_generator.o: ../compiler/ir_generator/ir_generator.cpp ../compiler/ir_generator/ir_generator.hpp ../compiler/ast_generator/node_collector.hpp ../compiler/utils/utils.hpp
	$(CC) -g -c ../compiler/ir_generator/ir_generator.cpp -o ir_generator.o  $(LLVM_OPTION)
blawn_context.o: ../compiler/blawn_context/blawn_context.cpp ../compiler/blawn_context/blawn_context.hpp
	$(CC) -g -c ../compiler/blawn_context/blawn_context.cpp -o blawn_context.o $(LLVM_OPTION)
utils.o: ../compiler/utils/utils.cpp
	$(CC) -g -c ../compiler/utils/utils.cpp -o utils.o $(LLVM_OPTION)
builtins.o: ../compiler/builtins/builtins.cpp ../compiler/builtins/builtins.hpp ../compiler/builtins/builtins.c
	$(CC) -g -c ../compiler/builtins/builtins.cpp -o builtins.o $(LLVM_OPTION)
	clang -c ../compiler/builtins/builtins.c -o ../../blawn/data/builtins.o
ast_generator.o: ../compiler/ast_generator/ast_generator.cpp ../compiler/ast_generator/ast_generator.hpp ../compiler/ast_generator/node_collector.hpp
	$(CC) -g -c ../compiler/ast_generator/ast_generator.cpp -o ast_generator.o $(LLVM_OPTION)
node.o: ../compiler/ast/node.cpp ../compiler/ast/node.hpp ../compiler/ir_generator/ir_generator.hpp
	$(CC) -g -c ../compiler/ast/node.cpp -o node.o  $(LLVM_OPTION)
errors.o: ../compiler/errors/errors.cpp ../compiler/errors/errors.hpp
	$(CC) -g -c ../compiler/errors/errors.cpp -o errors.o


set_path:
	alias cridge="python3 /mnt/c/users/pcnaoto/desktop/blawn/blawn/tools/cridge.py"
clean:
	rm *.o
	-fsanitize=address
cridge_debug:
	cd ../blawn && ./blawn ../tools/test1.bridge
cridge:
	cd ../tools && python3 cridge.py
	cd ../blawn && ./blawn ../tools/test1.bridge
test:
	cd ../test/blawn && ./blawn test1.blawn
lli: 
	cd ../blawn && lli result.ll
format:
	python3 ../dev_utils/format_cpp.py ../compiler