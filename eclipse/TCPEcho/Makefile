PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

CLIENT_OBJS = client.o config.o util.o
SERVER_OBJS = server.o config.o util.o

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else
	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all:	tcp_client tcp_server

tcp_client:	$(CLIENT_OBJS)
	$(CXX) -llog4c -o $@ $^

tcp_server:	$(SERVER_OBJS)
	$(CXX) -llog4c -o $@ $^

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr tcp_client tcp_server $(CLIENT_OBJS) $(SERVER_OBJS)
