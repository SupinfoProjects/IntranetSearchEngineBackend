#include "HtmlCrawler.h"
#include <thread>

HtmlCrawler::HtmlCrawler(std::string url)
{
	host = url;
	//urls = std::vector<std::string>();
	//pages = std::vector<HtmlPages>();
	//std::thread thread(crawlWebSite(url));
	crawlWebSite(url);
}

void HtmlCrawler::crawlWebSite(std::string url)
{
   	XmlParser p(url);
	urls = p.getUrls();
    while (urls.size() > 0)
    {
        for (auto url : urls)
        {
            XmlParser parser(url);
            HtmlPage page;
            page.url = url;
			checkedUrls.push_back(url);
			page.title = parser.getTitle();
            page.mark = parser.getMark();
            page.urls = parser.getUrls();
            page.metaKeywords = parser.getMetaKeywords();
            pages.push_back(page);
			//urls.push_back(url);
        }
        urls.clear();
        for (auto page : pages)
        {
             for (auto url : page.urls)
             {
				bool checked = false;
                for (int i{}; i < checkedUrls.size(); i++)
				{
					if (url == checkedUrls[i])
					{
						checked = true;
					}
/*					else if (url.find(host) == std::string::npos)
					{
						checked = true;
						checkedUrls.push_back(url);
					}*/
				}	 
				if (url.find(host) == std::string::npos)
				{
					checked = true;
					checkedUrls.push_back(url);
				}
				if (!checked)
				{
					urls.push_back(url);
				}
             }
        }
	}
}
