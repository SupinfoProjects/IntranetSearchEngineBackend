#include <iostream>
#include "HtmlCrawler.h"

int main(int argc, char *argv[])
{
	XmlParser p("begeekeveryday.fr");
	for (auto u : p.getUrls())
	{
		std::cout << u << std::endl;
	}
	return 0;
}
