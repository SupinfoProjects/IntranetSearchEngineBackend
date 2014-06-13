#include "HtmlCrawler.h"

HtmlCrawler::HtmlCrawler(std::string url)
{
    pages.push_back(page);
    crawlWebSite(url); 
}

void HtmlCrawler::crawlWebSite(std::string url)
{
    urls.push_back(url);
    while (urls.size() > 0)
    {
        for (auto url : urls)
        {
            XmlParser parser(url);
            HtmlPage page;
            page.url = url;
            page.mark = parser.getMark();
            page.urls = parser.getUrls();
            page.metaKeywords = parser.getMetaKeywords();
            pages.push_back(page);
        }
        //urls.clear();
        for (auto page : pages)
        {
             if (std::find(urls.begin(), urls.end(), page.url) != v.end())
             {
                 continue;
             }
             urls.push_back(page.url);
        }
    }
}
