CC=g++
INCDIRS= -I../boost_1_55_0 -I../include
LIBDIRS= -L../boost_1_55_0/stage/lib -L../lib -L/usr/lib/x86_64-linux-gnu
LIBS= ../boost_1_55_0/stage/lib/libboost_system.a -lpthread 
LDFLAGS= $(LIBDIRS)
CFLAGS= -std=c++0x -Wall $(INCDIRS)
SOURCES=Core.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=./SEClient

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

Core.o: Core.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

clean:
	rm -f *.o
