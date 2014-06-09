#ifndef SERIALIZABLE
#define SERIALIZABLE

#include <string>

class Serializable
{
public:
	virtual std::string serialize() = 0;
	virtual void deserialize(std::string serialized) = 0;
};

#endif
