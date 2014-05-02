#ifndef HTMLPARSER
#define HTMLPARSER

#include <map>
#include <string>
#include <vector>

#include "WebPage.h"

namespace {
	std::map keywords = {};
}

class HtmlParser
{
public:
	HtmlParser(std::string url);
	HtmlParser() : HtmlParser("") {}
	int getValueOf(std::string url);
private:
};

#endif
