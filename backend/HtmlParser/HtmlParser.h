#ifndef HTMLPARSER
#define HTMLPARSER

#include <map>
#include <string>
#include <vector>

class HtmlParser
{
public:
	HtmlParser(std::string url = "");
	int getValueOf(std::string url, std::vector<std::string> keywords);
private:

};

#endif
