# Compilation du programme : taper "make"
HtmlParser: main.o HtmlParser.o
	g++ -std=c++11 -o $@ $^

# Création de la lib statique : taper "make lib"
lib: main.o HtmlParser.o
	ar -q htmlparser.a HtmlParser.o

# Création de main.o
main.o: main.cpp HtmlParser.h
	g++ -std=c++11 -o main.o -c main.cpp
	
# Création de HtmlParser.o
UserInfos.o: HtmlParser.cpp HtmlParser.h
	g++ -std=c++11 -o HtmlParser.o -c HtmlParser.cpp
	
# Lance le programme : taper "make run"
run: HtmlParser
	./HtmlParser
	
# Supprime tous les fichiers : tape "make clean"
clean:
	rm -f *.o *.h.gch
	rm -f HtmlParser
	rm -f *.a
	rm -f *~
	rm -f *.out
