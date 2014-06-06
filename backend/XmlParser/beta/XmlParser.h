#pragma once

#include <initializer_list>
#include <string>
#include <vector>

#include "Tag.h"
#include "Url.h"

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
		Tag("p", 3)
	};
}

class XmlParser
{
public:
	XmlParser(const std::string& _filename);
	void ParseXmlFile();
	void AddNewUrl(const std::string& line);
	int SetMarkOf(const std::string& url);
	int mark;
	std::vector<std::string> keywords;
	/*std::vector<std::string> ks;
	std::vector<std::string> urls;*/
	std::vector<Url> urls;

private:
	std::string filename;
};
