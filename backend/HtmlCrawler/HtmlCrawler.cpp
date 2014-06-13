#include "HtmlCrawler.h"

HtmlCrawler::HtmlCrawler(std::string url)
{
    pages.push_back(page);
    crawlWebSite(url); 
}

void HtmlCrawler::crawlWebSite(std::string url)
{
    XmlParser parser(url);
    urls = parser.getUrls();
    HtmlPage page;
    page.url = url;
    page.mark = parser.getMark();
    page.urls = parser.getUrls();
    page.metaKeywords = parser.getMetaKeywords();
    pages.push_back(page);
    while (true)
    {
        bool areAllUrlsChecked = true;
        for (auto page : pages)
        {
            if (page.mark == UNCHECKED)
            {
                areAllUrlsChecked = false;
            }
        }
        if (areAllUrlsChecked)
        {
            break;
        }
        for (auto url : urls)
        {
            if (url.mark == UNCHECKED)
            {
                parser.parseXmlFile(url);
                HtmlPage page;
                page.url = url;
                page.mark = parser.getMark();
                page.urls = parser.getUrls();
                page.metaKeywords = parser.getMetaKeywords();
                pages.push_back(page);
            }
        }
        urls.clear();
        for (auto page : pages)
        {
            for (auto url : page.urls)
            {
                 if (std::find(urls.begin(), urls.end(), url) != v.end())
                 {
                     continue;
                 }
                 urls.push_back(url);
            }
        }
    }
}
