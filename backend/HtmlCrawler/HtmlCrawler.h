#ifndef HTML_CRAWLER
#define HTML_CRAWLER

#include <string>
#include <vector>

#include "../XmlParser/XmlParser.h"

class HtmlCrawler
{
public:
    HtmlCrawler(std::string url);
    // ajouter requête bdd
private:
    std::vector<XmlParser> parsers;
    std::vector<std::pair<std::string, bool>> urls; // [url][matched?]
};

#endif
