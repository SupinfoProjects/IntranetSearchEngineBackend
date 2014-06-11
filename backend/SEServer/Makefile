CC=c++
INCDIRS= -I./boost_1_55_0 -I./include
LIBDIRS= -L./boost_1_55_0/stage/lib -L./lib
LIBS= -lpthread -lmysqlcppconn -lboost_system -static
LDFLAGS= $(LIBDIRS)
CFLAGS= -std=c++0x -Wall $(INCDIRS)
SOURCES=Core.cpp Connection.cpp Listener.cpp Sender.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=SEServer

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

Connection.o: Connection.cpp Connection.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

Listener.o: Listener.cpp Listener.h 
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

Sender.o: Sender.cpp Sender.h 
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

Database.o: Database.cpp Database.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

Core.o: Core.cpp Listener.o Sender.o Connection.o Database.o
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

clean:
	rm -f *.o
