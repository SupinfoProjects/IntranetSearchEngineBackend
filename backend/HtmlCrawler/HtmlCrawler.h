#ifndef HTML_CRAWLER
#define HTML_CRAWLER

#include <string>
#include <vector>

#include "../XmlParser/XmlParser.h"
#include "HtmlPage.h"

class HtmlCrawler
{
public:
    HtmlCrawler(std::string url);
    void crawlWebSite(std::string url);
    // ajouter requête bdd
private:
    std::vector<XmlParser> parsers;
    std::vector<HtmlPage> pages;
};

#endif
