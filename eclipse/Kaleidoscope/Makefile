PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

LEX = flex
YACC = bison

CC = clang
CXX = clang++

RELEASE_PARSER_OBJS = Release/parser.o
#RELEASE_PARSER_FLEX_OBJS = Release/parser_flex.o Release/lexer.o Release/bison.o

# C++ Recursive Descent Parser from Tutorial

DEBUG_PARSER_OBJS = Debug/parser.o

Debug/parser:	$(DEBUG_PARSER_OBJS)
	$(CXX) `llvm-config --ldflags --libs` -g3 -O0 -o $@ $^

# Bison/Flex C++ Parser

# DEBUG_PARSER_FLEX_OBJS = Debug/parser_flex.o Debug/lexer.o Debug/bison.o

# Debug/parser_flex:	$(DEBUG_PARSER_FLEX_OBJS)
#	$(CXX) `llvm-config --ldflags --libs` -g3 -O0 -o $@ $^

all:		debug release

debug:		CFLAGS += -g3 -O0
# No Flex/Bison for now
debug:		Debug/parser # Debug/parser_flex

Debug/lexer.o:	lexer.l bison.h
	$(LEX) $(LFLAGS) --outfile=$@ $<

bison.cpp bison.h:	bison.y
	$(YACC) $(YFLAGS) -d $<

Debug/%.o:	%.cpp
	$(CXX) `llvm-config --cxxflags` -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

Debug/%.o:	%.c
	$(CC) `llvm-config --cflags` -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

Release/%.o:	%.cpp
	$(CXX) `llvm-config --cxxflags` -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

Release/%.o:	%.c
	$(CC) `llvm-config --cflags` -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

release:	CFLAGS += -O2
# Np Flex/Bison for now
release:	Release/parser # dRelease/parser_flex

Release/parser:	$(RELEASE_PARSER_OBJS)
	$(CXX) `llvm-config --ldflags --libs` $(CFLAGS) $(CPPFLAGS) -o $@ $^

#Release/parser_flex:	$(RELEASE_PARSER_FLEX_OBJS)
#	$(CXX) `llvm-config --ldflags --libs` -O3 -o $@ $^

clean:
	rm -fr Debug/parser Debug/parser_flex $(DEBUG_PARSER_OBJS) $(DEBUG_PARSER_FLEX_OBJS)
	rm -fr Release/parser Release/parser_flex $(RELEASE_PARSER_OBJS) $(RELEASE_PARSER_FLEX_OBJS)
