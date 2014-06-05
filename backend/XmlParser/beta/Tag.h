#pragma once

#include <map>
#include <string>

class Tag
{
public:
	Tag(std::string _tag, int _mark);
	std::string first() const;
	std::string second() const;
	int getMark() const;

private:
	std::string tag;
	int mark;
};
