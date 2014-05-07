#ifndef HTMLPARSER
#define HTMLPARSER

#include <map>
#include <string>
#include <vector>

namespace {
	//std::map<std::string, int> keywords = {};
}

class HtmlParser
{
public:
	HtmlParser(std::string url = "");
	int getValueOf(std::string url);
private:
	//std::vector<WebPage> pages;
};

#endif
