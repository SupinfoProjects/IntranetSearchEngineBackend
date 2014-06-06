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

	// getters
	std::vector<std::string> get_keywords() const { return kwords; }
	std::vector<std::string> get_urls() const { return urls; }
	int get_mark() const { return mark; }

private:
	std::string filename;
	std::vector<std::string> kwords;
	std::vector<std::string> urls;
	int mark;

	//
	void parse_xml_file(const std::string& _filemane = "");
	void add_new_url(const std::string& line);
	void set_mark_of(const std::string& url);
};
