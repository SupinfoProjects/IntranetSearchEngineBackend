#ifndef HTML_PAGE
#define HTML_PAGE

#include <string>
#include <vector>

#define UNCHECKED -1

struct HtmlPage
{
    HtmlPage() : url(""), mark(-1) {}
    std::string url;
    std::vector<std::string> urls;
    std::vector<std::string> metaKeywords;
    int mark;
};

#endif
