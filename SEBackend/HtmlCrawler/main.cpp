#include <iostream>
#include "HtmlCrawler.h"
#include <new>

int main(int argc, char *argv[])
{
//	HtmlCrawler p;
//	try {
	HtmlCrawler p("begeekeveryday.fr");
//	//p.crawlWebSite("begeekeveryday.fr");
//	}
//	catch (std::exception& e)
//	{
		for (auto page : p.getPages())
		{
			std::string s="";
		
			std::cout << "==============================" 
				<< std::endl <<"title : " << page.title 
				<< std::endl << page.url << " mark : " << page.mark << std::endl;
		}
//		std::cout << e.what() << std::endl;
//	}
	//for (auto page : p.getPages())
	//	std::cout << page.url << std::endl;
	/*for (auto u : p.getPages())
	{
		std::cout << u.url << std::endl;
	}*/
	return 0;
}
