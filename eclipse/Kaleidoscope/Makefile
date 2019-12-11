PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

CC = clang
CXX = clang++
CFLAGS += -g3 -O0

OBJS = parser.o

# ifeq ($(BUILD_MODE),debug)
#	CFLAGS += -g
# else ifeq ($(BUILD_MODE),run)
#	CFLAGS += -O2
# else
#	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
# endif

all:	parser

parser:	$(OBJS)
	$(CXX) `llvm-config --ldflags --libs` -o $@ $^

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) `llvm-config --cxxflags` -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) `llvm-config --cxxflags` -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr parser $(CLIENT_OBJS)
