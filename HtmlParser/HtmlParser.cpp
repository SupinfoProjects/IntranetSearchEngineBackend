#include "HtmlParser.h"

#include <iostream>
#include <algorithm>    // std::count_if
#include <exception>
#include <fstream>
#include <string>

using namespace std;

HtmlParser::HtmlParser(string url)
{
}

int HtmlParser::getValueOf(string url)
{
	string query = "wget " + url;
	system(query.c_str());
	ifstream file("index.html");  //Ouverture d'un fichier en lecture
	if (!file)
		return -1;
	string line;
	int mark = 0;
	while (getline(file, line))
	{
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
				|| line.substr(i,4) == "<h4>"
				|| line.substr(i, 4) == "<h5>"
				|| line.substr(i, 4) == "<h6>")
				mark++;
		}
	}
	system("rm index.html");
	return mark;
}
