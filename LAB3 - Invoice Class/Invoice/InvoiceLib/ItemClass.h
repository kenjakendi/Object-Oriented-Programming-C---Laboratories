#pragma once
#include <string>

class Item
{
private:
	std::string name;
public:
	Item(std::string name);
	std::string getName() const;
	void setName(std::string name);
};