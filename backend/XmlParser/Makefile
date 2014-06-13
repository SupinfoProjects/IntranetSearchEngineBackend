# Compilation du programme : taper "make"
XmlParser: main.o XmlParser.o Tag.o
	g++ -std=c++0x -o $@ $^

# Création de la lib statique : taper "make lib"
lib: main.o XmlParser.o Tag.o
	ar -q XmlParser.a XmlParser.o Tag.o

# Création de main.o
main.o: main.cpp XmlParser.h
	g++ -std=c++0x -o main.o -c main.cpp

# Création de XmlParser.o
XmlParser.o: XmlParser.cpp XmlParser.h
	g++ -std=c++0x -o XmlParser.o -c XmlParser.cpp

# Création de Tag.o
Tag.o: Tag.cpp Tag.h
	g++ -std=c++0x -o Tag.o -c Tag.cpp

# Lance le programme : taper "make run"
run: XmlParser
	./XmlParser
	
# Supprime tous les fichiers : tape "make clean"
clean:
	rm -f *.o *.h.gch
	rm -f XmlParser
	rm -f *.a
	rm -f *~
	rm -f *.out
