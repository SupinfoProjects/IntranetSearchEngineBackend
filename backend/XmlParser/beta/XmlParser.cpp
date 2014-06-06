#include "XmlParserh.h"

// std
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

XmlParser::XmlParser(const std::string& _url) : url(_url)
{
	parse_xml_file(url);
}

void XmlParser::parse_xml_file(const std::string& _url)
{
	if (_url != "")
	{
		url = _url;
		//system("rm index.html");
		//system(std::string("wget " + filename).c_str());
	}
	std::ifstream stream("index.html");
	std::string line;
	if (!stream)
	{
		throw std::exception(std::string("Cannot open file " + url).c_str());
	}
	while (std::getline(stream, line))
	{
		if (line.size() < 8) // "<p> </p>"
		{
			continue;
		}
		if (line.find("<a href") != std::string::npos)
		{
			add_new_url(line);
		}
	}
	set_mark_of(url);
}

void XmlParser::set_mark_of(const std::string& url)
{
	std::ifstream stream("index.html");
	std::string line;
	if (!stream)
	{
		throw std::exception(std::string("Cannot open file " + url).c_str());
	}
	mark = 0;
	while (std::getline(stream, line))
	{
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
				kwords.push_back(keyword);
				mark += tag.getMark();
			}
		}
	}
}

void XmlParser::add_new_url(const std::string& line)
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
		std::string tmp;
		for (auto it = urls.begin(); it != urls.end(); it++)
		{
			if (tmp == *it)
			{
				return;
			}
		}
		urls.push_back(url);
	}
}
