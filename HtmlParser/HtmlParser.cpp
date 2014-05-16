#include "HtmlParser.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

HtmlParser::HtmlParser(std::string url)
{
}

int HtmlParser::getValueOf(std::string url, std::vector<std::string> keywords)
{
	std::string query = "wget " + url;
	system(query.c_str());
	std::ifstream file("index.html");
	if (!file) return -1;
	std::string line;
	int mark = 0;
	while (std::getline(file, line))
	{
		for (int i = 0; i < keywords.size(); ++i)
		{
			std::string word = keywords[i];
			if (line.find(word) < word.size())
				continue;
			int substring(0);
			while ((substring = line.find(keywords[i])) != std::string::npos)
			{
				mark += 5;
				line = line.substr(++substring);
			}
		}
		if (line.size() < 3) continue;
		for (int i = 0; i < line.size() - 3; i++)
		{
			if (line.substr(i, i + 3) == "<p>")
				mark += 3;
		}
		if (line.size() < 4) continue;
		for (int i = 0; i < line.size() - 4; i++)
		{
			if (line.substr(i, 4) == "<h1>")
				mark += 5;
			if (line.substr(i, 4) == "<h2>")
				mark += 2;
			if (line.substr(i, 4) == "<h3>"
				|| line.substr(i, 4) == "<h4>"
				|| line.substr(i, 4) == "<h5>"
				|| line.substr(i, 4) == "<h6>")
				mark++;
		}
	}
	system("rm index.html");
	return mark;
}
