#ifndef WEBPAGE
#define WEBPAGE

#include <string>
#include <vector>

struct WebPage {
	std::string url;
	std::string lastUpdate;
	std::vector<std::string> keywords;
	int value;
};

#endif
