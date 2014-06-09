#pragma once

#include <string>
#include <vector>

#include "Serializable.h"

struct HtmlPage : Serializable
{
	std::string serialize() override;
	void deserialize(std::string serialized) override;

	std::vector<std::string> keywords;
	std::vector<std::string> urls;
	int mark;
};
