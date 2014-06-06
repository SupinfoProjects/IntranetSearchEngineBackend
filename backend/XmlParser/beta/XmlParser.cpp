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
		if (line.find("<a href") != std::string::npos)
		{
			AddNewUrl(line);
		}
	}
}

int XmlParser::SetMarkOf(const std::string& url)
{
	std::ifstream stream(filename);
	std::string line;
	Url url;
	if (!stream)
	{
		throw std::exception(std::string("Cannot open file " + filename).c_str());
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
			//keywords.push_back(Tag(keyword, tag.getMark()));
			keywords.push_back(keyword);
			mark += tag.getMark();
		}
	}
}

void XmlParser::AddNewUrl(const std::string& line)
{
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
	while (url[url.size() - 1] == '/')
	{
		std::string tmp;
		for (int i = 0; i < url.size() - 1; i++)
		{
			tmp += url[i];
		}
		url = tmp;
	}
	if (std::regex_match(url, regex))
	{
		Url tmp = { url, 0 };
		for (auto it = urls.begin(); it != urls.end(); it++)
		{
			if (tmp == *it)
			{
				return;
			}
		}
		urls.push_back(tmp);
	}
}
