# Compilation du programme : taper "make"
HtmlCrawler: main.o  HtmlCrawler.o Tag.o XmlParser.o
	g++ -std=c++0x -o $@ $^

# Création de la lib statique : taper "make lib"
lib: main.o XmlParser.o Tag.o
	ar -q XmlParser.a XmlParser.o Tag.o

# Création de main.o
main.o: main.cpp XmlParser.h
	g++ -std=c++0x -o main.o -c main.cpp

# Création de  HtmlCrawler.o
HtmlCrawler.o:  HtmlCrawler.cpp  HtmlCrawler.h
	g++ -std=c++0x -o  HtmlCrawler.o -c  HtmlCrawler.cpp

# Création de  XmlParser.o
XmlParser.o:  XmlParser.cpp  XmlParser.h
	g++ -std=c++0x -o  XmlParser.o -c  XmlParser.cpp

# Création de Tag.o
Tag.o: Tag.cpp Tag.h
	g++ -std=c++0x -o Tag.o -c Tag.cpp

# Lance le programme : taper "make run"
run: HtmlCrawler
	./HtmlCrawler
	
# Supprime tous les fichiers : tape "make clean"
clean:
	rm -f *.o *.h.gch
	rm -f XmlParser
	rm -f *.a
	rm -f *~
	rm -f *.out
	rm -f index.html
