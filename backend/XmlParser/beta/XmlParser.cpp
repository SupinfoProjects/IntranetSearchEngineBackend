#include "XmlParserh.h"
// std
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <regex>
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
		throw std::exception(std::string("Cannot open file " + filename).c_str());
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
				std::string sub = line.substr(first + tag.first().size(), second);
				std::string keyword;
				for (int i = 0; i < sub.size() - tag.second().size(); i++)
				{
					keyword += sub[i];
				}
				keywords.push_back(Tag(keyword, tag.getMark()));
				ks.push_back(keyword);
				mark += tag.getMark();
			}
		}
		if (line.find("<a href") != std::string::npos)
		{
			AddNewUrl(line);
		}
	}
	for (auto& k : keywords)
	{
		std::string tmp;
		for (int i = 1; i < k.first().size() - 1; i++)
		{
			tmp += k.first()[i];
		}
	}
}

void XmlParser::AddNewUrl(const std::string& line)
{
	// filtre les url pour respecter le format http://nomdedomaine.com/pages/page1.php
	std::regex regex("^(http|https)://[a-z0-9\-\_\\.]*.(com|fr|org|php|htm|html)(/*)[a-z0-9\-\_\\./]*$");
	std::string href = "<a href=\"";
	int startpos = line.find(href) + href.size();
	int endpos = line.find("\"");
	std::string sub = line.substr(endpos + 1);
	if ((endpos = sub.find("\"")) == std::string::npos)
	{
		return;
	}
	std::string url = line.substr(startpos, endpos);
	if (std::regex_match(url, regex))
	{
		urls.push_back(url);
	}
}
