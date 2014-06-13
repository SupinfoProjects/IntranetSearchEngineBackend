#include "HtmlCrawler.h"

HtmlCrawler::HtmlCrawler(std::string url)
{
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
        urls.clear();
        for (auto page : pages)
        {
             for (auto url : page.urls)
             {
                 bool alreadyChecked = false;
                 for (int i{}; i < pages.size(); i++)
                 {
                     if (pages[i].url == url)
                     {
                         alreadyChecked = true;
                     }
                 }
                 if (!alreadyChecked)
                 {
                     urls.push_back(url);
                 }
             }
        }
    }
}
