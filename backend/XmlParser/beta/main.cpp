#include <fstream>
#include <iostream>
#include "XmlParserh.h"

int main(int argc, char *argv)
{
	XmlParser parser("oc.html");
	parser.ParseXmlFile();
	std::cout << parser.mark;
	std::cin.get();
	return 0;
}
