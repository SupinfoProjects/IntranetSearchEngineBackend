#ifndef HTML_CRAWLER
#define HTML_CRAWLER

#include <string>
#include <vector>

<<<<<<< HEAD
//#include "../XmlParser/Tag.h"
#include "../XmlParser/XmlParser.h"
=======
#include "XmlParser.h"
>>>>>>> 5eac75be250c8059f7fb3355acd3f0adcf259af8
#include "HtmlPage.h"

class HtmlCrawler
{
public:
    HtmlCrawler(std::string url);
    void crawlWebSite(std::string url);
    // ajouter requête bdd
private:
    std::vector<HtmlPage> pages;
    std::vector<std::string> urls;
};

#endif
