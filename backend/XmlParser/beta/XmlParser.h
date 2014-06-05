#pragma once

#include <initializer_list>
#include <string>
#include <vector>

#include "Tag.h"

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
	int mark;

private:
	std::string filename;
	std::vector<Tag> keywords;
};
