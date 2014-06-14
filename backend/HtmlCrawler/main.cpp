#include <iostream>
#include "HtmlCrawler.h"

int main(int argc, char *argv[])
{
	HtmlCrawler p("begeekeveryday.fr");
	for (auto u : p.getPages())
	{
		std::cout << u.url << std::endl;
		std::string mk = "";
		for (auto m : u.metaKeywords)
		{
			mk += m + " ";
		}
		//std::cout << "META - " << mk << std::endl;
	}
	return 0;
}
