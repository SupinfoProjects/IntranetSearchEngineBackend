#include <fstream>
#include <iostream>
#include <regex>
#include "XmlParser.h"

int main(int argc, char **argv)
{
	XmlParser parser("oc.html");
	//std::cout << parser.mark;
	for (auto k : parser.get_urls())
	{
		std::cout << k << std::endl;
	}
	std::cout << parser.get_mark();
	/*
	std::regex r("^(http|https)://[a-z0-9\-\_\\.]*.(com|fr|org|php|htm|html)(/*)[a-z0-9\-\_\\./]*$");
	std::string s = "https://site-du_zero.com/zboub/aga";
	if (std::regex_match(s, r))
	{
		std::cout << "aga";
	}*/
	std::cin.get();
	return 0;
}
