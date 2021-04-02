#include "InvoiceClass.h"

using namespace std;

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

void Invoice::addItem(string const& item_name)
{
	items.push_back(item_name);
}

void Invoice::removeItem(string const& item_name)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] == item_name)
		{
			items.erase(items.begin() + i);
			i--;
		}
	}
}

Invoice Invoice::operator+(Invoice const& invoice) const
{
	if ((getName() == invoice.getName()) && (getAdress() == invoice.getAdress()))
	{
		vector <string> items = getItems();
		for (int i = 0; i < invoice.getItems().size(); i++)
		{
			items.push_back(invoice.getItems()[i]);
		}
		return Invoice(getName(), getAdress(), items);
	}
	else
	{
		return Invoice(getName(), getAdress(), getItems());
	}
}

Invoice Invoice::operator-(Invoice const& invoice) const
{
	if ((getName() == invoice.getName()) && (getAdress() == invoice.getAdress()))
	{
		vector <string> main_items = getItems();
		for (int i = 0; i < invoice.getItems().size(); i++)
		{
			string item_name = invoice.getItems()[i];
			for (int i = 0; i < main_items.size(); i++)
			{
				if (main_items[i] == item_name)
				{
					main_items.erase(main_items.begin() + i);
					i--;
				}
			}
		}
		return Invoice(getName(), getAdress(), main_items);
	}
	else 
	{
		return Invoice(getName(), getAdress(), getItems());
	}
}
/*
ostream& operator<< (ostream& os, const Invoice& invoice)
{
	string const name = invoice.getName();
	string const adress = invoice.getAdress();
	const vector <string> items = invoice.getItems();
	os << name << "/t" << adress << endl;
	for (int i = 0; i < items.size(); i++)
	{
		os << items[i] << endl;
	}
	return os;
}
*/