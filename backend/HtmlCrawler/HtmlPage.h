#ifndef HTML_PAGE
#define HTML_PAGE

#include <string>
#include <vector>

struct HtmlPage
{
    HtmlPage() : url(""), mark(-1) {}
    std::string url;
    std::vector<std::string> metaKeywords;
    int mark;
};

#endif
