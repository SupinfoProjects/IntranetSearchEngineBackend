#ifndef HTML_CRAWLER
#define HTML_CRAWLER

#include <string>
#include <vector>

#include "Tag.h"
#include "XmlParser.h"
#include "HtmlPage.h"

class HtmlCrawler
{
public:
	HtmlCrawler() {}
    HtmlCrawler(std::string url);
    void crawlWebSite(std::string url);
    std::vector<std::string> getUrls() const { return urls; }
    std::vector<HtmlPage> getPages() const { return pages; }
    // ajouter requête bdd
private:
	std::string host;
    std::vector<HtmlPage> pages;
    std::vector<std::string> urls, checkedUrls;
};

#endif
