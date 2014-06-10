#include "XmlParser.h"

// std
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

XmlParser::XmlParser(const std::string& _url) : url(_url)
{
	dname = "http://fr.openclassrooms.com";
	parse_xml_file(url);
}

void XmlParser::parse_xml_file(const std::string& _url)
{
	urls.clear();
	kwords.clear();
	if (_url != "")
	{
		//url = _url;
		// Décommenter pour Linux
		//system("rm index.html");
		//system(std::string("wget " + filename).c_str());
	}
	std::ifstream stream("index.html");
	std::string line;
	if (!stream)
	{
		std::cout << "Problème d'ouverture index.html";
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

void XmlParser::set_mark_of(const std::string& _url)
{
	std::ifstream stream("index.html");
	std::string line;
	if (!stream)
	{
		std::cout << "Problème d'ouverture index.html";
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
	std::string href = "<a href=\"";
	int startpos = line.find(href) + href.size();
	int endpos = line.find("\"");
	std::string sub = line.substr(endpos + 1);
	if ((endpos = sub.find("\"")) == std::string::npos)
	{
		return;
	}
	std::string _url = line.substr(startpos, endpos);
	while (_url[_url.size() - 1] == '/' || _url[_url.size() - 1] == '#')
	{
		std::string tmp = "";
		for (int i = 0; i < _url.size() - 1; i++)
		{
			tmp += _url[i];
		}
		_url = tmp;
	}
	for (auto u : urls)
	{
		if (_url == u)
		{
			return;
		}
	}
	if (_url.size() >= dname.size() && _url.find(dname) != std::string::npos)
	{
		urls.push_back(_url);
	}	
}
