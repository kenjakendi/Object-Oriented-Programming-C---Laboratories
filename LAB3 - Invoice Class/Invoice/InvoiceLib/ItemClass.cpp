#include "ItemClass.h"
#include <iostream>

using namespace std;

Item::Item(string name)
{
	this->name = name;
}

string Item::getName() const
{
	return name;
}

void Item::setName(string const name)
{
	this->name = name;
}

bool Item::operator==(Item const& item) const
{
	if (getName() == item.getName())
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& os, const Item& item)
{
	os << item.getName();
	return os;
}