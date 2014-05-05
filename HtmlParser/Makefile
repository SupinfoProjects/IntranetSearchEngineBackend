# Compilation du programme : taper "make"
HtmlParser: main.o HtmlParser.o
	g++ -std=c++0x -o $@ $^

# Création de la lib statique : taper "make lib"
lib: main.o HtmlParser.o
	ar -q marine.a HtmlParser.o

# Création de main.o
main.o: main.cpp HtmlParser.h
	g++ -std=c++0x -o main.o -c main.cpp
	
# Création de HtmlParser.o
UserInfos.o: HtmlParser.cpp HtmlParser.h
	g++ -std=c++0x -o HtmlParser.o -c HtmlParser.cpp
	
# Lance le programme : taper "make run"
run: HtmlParser
	./HtmlParser
	
# Supprime tous les fichiers : tape "make clean"
clean:
	rm -f *.o *.h.gch
	rm -f HtmlParser
	rm -f HtmlParser.a

