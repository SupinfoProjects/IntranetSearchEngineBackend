Marine : main.o UserInfos.o
		g++ -std=c++0x -o $@ $^
main.o: main.cpp UserInfos.h
		g++ -std=c++0x -o main.o -c main.cpp
UserInfos.o : UserInfos.cpp UserInfos.h
		g++ -std=c++0x -o UserInfos.o -c UserInfos.cpp

run: Marine
		./Marine

clean:
		rm -f *.o *.h.gch
		rm -f Marine

build: clean Marine
		%.o: %.cpp
		g++ -std=c++0x -c $<

