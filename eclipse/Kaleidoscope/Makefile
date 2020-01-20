PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

LEX = flex

YACC = bison

CC = clang
CXX = clang++
CFLAGS += -g3 -O0

PARSER_OBJS = parser.o

PARSER_FLEX_OBJS = parser_flex.o lexer.o bison.o

# ifeq ($(BUILD_MODE),debug)
#	CFLAGS += -g
# else ifeq ($(BUILD_MODE),run)
#	CFLAGS += -O2
# else
#	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
# endif

%.c:	%.l
	$(LEX) $(LFLAGS) --outfile=$@ $<

%.c:	%.y
	$(YACC) $(YFLAGS) $<

%.o:	%.cpp
	$(CXX) `llvm-config --cxxflags` -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	%.c
	$(CC) `llvm-config --cflags` -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

all:	parser parser_flex

parser:	$(PARSER_OBJS)
	$(CC) `llvm-config --ldflags --libs` -o $@ $^

parser_flex:	$(PARSER_FLEX_OBJS)
	$(CC) `llvm-config --ldflags --libs` -o $@ $^

lexer.o:	lexer.l bison.h

bison.h bison.c:	bison.y
	$(YACC) $(YFLAGS) -d $<

clean:
	rm -fr parser $(PARSER_OBJS) $(PARSER_FLEX_OBJS)
