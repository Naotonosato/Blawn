#CC    ?= clang
#CXX   ?= clang++
#
#EXE = my_wc
#
#CDEBUG = -g -Wall
#
#CXXDEBUG = -g -Wall
#
#CSTD = -std=c99
#CXXSTD = -std=c++14
#
#CFLAGS = -Wno-deprecated-register -O0  $(CDEBUG) $(CSTD) 
#CXXFLAGS = -Wno-deprecated-register -O0  $(CXXDEBUG) $(CXXSTD)
#
#
#CPPOBJ = main mc_driver
#SOBJ =  parser lexer
#
#FILES = $(addsuffix .cpp, $(CPPOBJ))
#
#OBJS  = $(addsuffix .o, $(CPPOBJ))
#
#CLEANLIST =  $(addsuffix .o, $(OBJ)) $(OBJS) \
#				 mc_parser.tab.cc mc_parser.tab.hh \
#				 location.hh position.hh \
#			    stack.hh mc_parser.output parser.o \
#				 lexer.o mc_lexer.yy.cc $(EXE)\
#
#.PHONY: all
#all: wc
#
#wc: $(FILES)
#	$(MAKE) $(SOBJ)
#	$(MAKE) $(OBJS)
#	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) parser.o lexer.o $(LIBS)
#
#
#parser: mc_parser.yy
#	bison -d -v mc_parser.yy
#	$(CXX) $(CXXFLAGS) -c -o parser.o mc_parser.tab.cc
#
#lexer: mc_lexer.l
#	flex --outfile=mc_lexer.yy.cc  $<
#	$(CXX)  $(CXXFLAGS) -c mc_lexer.yy.cc -o lexer.o
#
#.PHONY: test
#test:
#	test/test0.pl
#
#.PHONY: clean
#clean:
#	rm -rf $(CLEANLIST)
#
#


wc: parser lexer driver main
	g++ -o my_wc parser.o main.o lexer.o driver.o -ll `llvm-config --cxxflags --system-libs --ldflags --libs core`


parser: mc_parser.yy
	bison -d -v mc_parser.yy
	g++ -c -o parser.o mc_parser.tab.cc

lexer: mc_lexer.l
	flex --outfile=mc_lexer.yy.cc $<
	g++ -c mc_lexer.yy.cc -o lexer.o

driver: mc_driver.cpp
	g++ -o driver.o -c mc_driver.cpp `llvm-config --cxxflags --system-libs --ldflags --libs core` -fexceptions

main: main.cpp
	g++ -c main.cpp