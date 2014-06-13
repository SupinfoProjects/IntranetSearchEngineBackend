#ifndef XML_PARSER
#define XML_PARSER

#include <initializer_list>
#include <string>
#include <vector>

namespace
{
	const std::vector<Tag> tags =
	{
		Tag("h1", 5),
		Tag("h2", 2),
		Tag("h3", 1),
		Tag("h4", 1),
		Tag("h5", 1),
		Tag("h6", 1),
	};
}

class XmlParser
{
public:
	XmlParser(const std::string& _url, const std::string& _dname = "");

	// getters
	std::vector<std::string> getUrls()         const { return urls;   }
	int                      getMark()         const { return mark;   }
	std::string		 getDomainName()   const { return dname;  }
	std::vector<std::string> getKeywords()	   const { return kwords; }
	std::vector<std::string> getMetaKeywords() const { return metakwords; }

private:
	std::string url, dname;
	std::vector<std::string> kwords, metakwords;
	std::vector<std::string> urls;
	int mark;

	// Méthodes privées
	void parseXmlFile(const std::string& _filemane = "");
	void addNewUrl(const std::string& line);
	void setMarkOf(const std::string& _url);
};

#endif // XML_PARSER defined
