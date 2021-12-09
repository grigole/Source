CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Fttw.o

LIBS =		-lfftw3

TARGET =	Fttw

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
