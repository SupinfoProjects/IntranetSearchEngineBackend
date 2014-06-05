#include "XmlParserh.h"
// std
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

XmlParser::XmlParser(const std::string& _filename) : filename(_filename)
{
	mark = 0;
}

void XmlParser::ParseXmlFile()
{
	std::ifstream stream(filename);
	std::string line;
	if (!stream)
	{
		throw std::exception(std::string(std::string("Cannot open file ") + filename).c_str());
	}
	while (std::getline(stream, line))
	{
		if (line.size() < 8) // "<p> </p>"
		{
			continue;
		}
		for (auto tag : tags)
		{
			int first{}, second{};
			if ((first = line.find(tag.first())) != std::string::npos
				&& (second = line.find(tag.second())) != std::string::npos)
			{
				std::string keyword = line.substr(first + tag.first().size(), second);
				keywords.push_back(Tag(keyword, tag.getMark()));
				mark += tag.getMark();
			}
		}
	}
}
 
