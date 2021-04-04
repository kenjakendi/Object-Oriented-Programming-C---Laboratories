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

bool Invoice::sameData(Invoice const& invoice)const
{
	if ((getName() == invoice.getName()) && (getAdress() == invoice.getAdress()))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

Invoice Invoice::operator+(Invoice const& invoice) const
{
	Invoice sum = Invoice(getName(), getAdress(), getItems());
	if (sameData(invoice))
	{
		for (int i = 0; i < invoice.getItems().size(); i++)
		{
			sum.addItem(invoice.getItems()[i]);
		}
		return sum;
	}
	else
	{
		return sum;
	}
}

Invoice Invoice::operator-(Invoice const& invoice) const
{
	Invoice sub = Invoice(getName(), getAdress(), getItems());
	if (sameData(invoice))
	{
		for (int i = 0; i < invoice.getItems().size(); i++)
		{
			sub.removeItem(invoice.getItems()[i]);
		}
		return sub;
	}
	else 
	{
		return sub;
	}
}

Invoice Invoice::operator+(string const& item_name) const
{
	Invoice invoice = Invoice(getName(), getAdress(), getItems());
	invoice.addItem(item_name);
	return invoice;
}

Invoice Invoice::operator-(string const& item_name) const
{
	Invoice invoice = Invoice(getName(), getAdress(), getItems());
	invoice.removeItem(item_name);
	return invoice;
}

void Invoice::operator+=(Invoice const& invoice)
{
	if (sameData(invoice))
	{
		for (int i = 0; i < invoice.getItems().size(); i++)
		{
			addItem(invoice.getItems()[i]);
		}
	}
}

void Invoice::operator-=(Invoice const& invoice)
{
	if (sameData(invoice))
	{
		for (int i = 0; i < invoice.getItems().size(); i++)
		{
			removeItem(invoice.getItems()[i]);
		}
	}
}

void Invoice::operator+=(std::string const& item_name)
{
	addItem(item_name);
}

void Invoice::operator-=(std::string const& item_name)
{
	removeItem(item_name);
}

ostream& operator<< (ostream& os, const Invoice& invoice)
{
	string const name = invoice.getName();
	string const adress = invoice.getAdress();
	const vector <string> items = invoice.getItems();
	os << name << " " << adress << endl;
	for (int i = 0; i < items.size(); i++)
	{
		os << items[i] << endl;
	}
	os << "end" << endl;
	return os;
}

istream& operator>> (istream& is, Invoice& invoice)
{
	string name;
	string adress;
	is >> name >> adress;
	invoice.setName(name);
	invoice.setAdress(adress);
	string item;
	is >> item;
	while (item != "end")
	{
		invoice.addItem(item);
		is >> item;
	}
	return is;
}