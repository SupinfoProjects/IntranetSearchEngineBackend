#include "HtmlParser.h"
#include <iostream>

int main(int argc, char *argv[])
{
	HtmlParser parser;
	std::vector<std::string> keywords;
	for (int i(0); i < argc; i++)
	{
		keywords.push_back(argv[i]);
		std::cout << keywords[i] << std::endl;
	}
	std::cout << parser.getValueOf("fr.openclassrooms.com", keywords) << std::endl;
}
