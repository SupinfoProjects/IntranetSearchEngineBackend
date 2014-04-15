
# Compilation du programme : taper "make"
Marine : main.o UserInfos.o
	g++ -std=c++0x -o $@ $^
# Création de main.o
main.o: main.cpp UserInfos.h
	g++ -std=c++0x -o main.o -c main.cpp
# Création de UserInfos.o
UserInfos.o : UserInfos.cpp UserInfos.h
	g++ -std=c++0x -o UserInfos.o -c UserInfos.cpp
# Lance le programme
run: Marine
	./Marine
# Supprime tous les fichiers
clean:
	rm -f *.o *.h.gch
	rm -f Marine

