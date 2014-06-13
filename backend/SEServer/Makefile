CC=g++
INCDIRS= -I../../boost_1_55_0 -I../../include
LIBDIRS= -L../../boost_1_55_0/stage/lib -L../../lib -L/usr/lib/x86_64-linux-gnu
LIBS= ../../boost_1_55_0/stage/lib/libboost_system.a ../../lib/libmysqlcppconn-static.a -Wl,-Bdynamic -lmysqlclient 
LDFLAGS= $(LIBDIRS)
CFLAGS= -std=c++0x -DMYSQL_CLIENT_NO_THREADS -Wall $(INCDIRS)
SOURCES=Database.cpp Connection.cpp Listener.cpp Sender.cpp Core.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=./SEServer

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

Connection.o: Connection.cpp Connection.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

Listener.o: Listener.cpp Listener.h Connection.h 
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

Sender.o: Sender.cpp Sender.h 
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

Database.o: Database.cpp Database.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

Core.o: Core.cpp Listener.h Sender.h Connection.h Database.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS)

clean:
	rm -f *.o
