#include "Tag.h"

Tag::Tag(std::string _tag, int _mark) : tag(_tag), mark(_mark)
{
}

std::string Tag::first() const
{
	return "<" + tag + ">";
}

std::string Tag::second() const
{
	return "</" + tag + ">";
}

int Tag::getMark() const
{
	return mark;
}
*/
