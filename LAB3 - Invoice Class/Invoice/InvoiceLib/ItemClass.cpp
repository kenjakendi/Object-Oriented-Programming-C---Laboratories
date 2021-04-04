#include "ItemClass.h"

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