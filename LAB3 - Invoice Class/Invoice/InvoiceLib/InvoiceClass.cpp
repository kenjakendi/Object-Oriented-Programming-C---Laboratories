#include "InvoiceClass.h"

using namespace std;

Invoice::Invoice(string name, string adress)
{
	this->name = name;
	this->adress = adress;
	this->items = {};
}

Invoice::Invoice(string name, string adress, vector <string> items)
{
	this->name = name;
	this->adress = adress;
	this->items = items;
}

string Invoice::getName() const 
{
	return name;
}

string Invoice::getAdress() const
{
	return adress;
}

vector <string> Invoice::getItems() const
{
	return items;
}

void Invoice::setName(string const name)
{
	this->name = name;
}

void Invoice::setAdress(string const adress)
{
	this->adress = adress;
}

void Invoice::setItems(vector <string> const items)
{
	this->items = items;
}

void Invoice::addItem(string const item_name)
{
	vector <string> items = this->getItems();
	items.push_back(item_name);
	this->setItems(items);
}

void Invoice::removeItem(string item_name)
{
	vector <string> items = this->getItems();
	for (int i = 0; i <= items.size(); i++)
	{
		if (items[i] == item_name)
		{
			items.erase(items.begin() + i);
			i--;
		}
	}
	this->setItems(items);
}