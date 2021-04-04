#include "InvoiceClass.h"

using namespace std;

Invoice::Invoice(string name, string adress, vector <Item> items)
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

vector <Item> Invoice::getItems() const
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

void Invoice::setItems(vector <Item> const items)
{
	this->items = items;
}

void Invoice::addItem(Item const& item)
{
	items.push_back(item);
}

void Invoice::removeItem(Item const& item)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] == item)
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

Invoice Invoice::operator+(Item const& item) const
{
	Invoice invoice = Invoice(getName(), getAdress(), getItems());
	invoice.addItem(item);
	return invoice;
}

Invoice Invoice::operator-(Item const& item) const
{
	Invoice invoice = Invoice(getName(), getAdress(), getItems());
	invoice.removeItem(item);
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

void Invoice::operator+=(Item const& item)
{
	addItem(item);
}

void Invoice::operator-=(Item const& item)
{
	removeItem(item);
}

ostream& operator<< (ostream& os, const Invoice& invoice)
{
	string const name = invoice.getName();
	string const adress = invoice.getAdress();
	const vector <Item> items = invoice.getItems();
	os << name << " " << adress << endl;
	for (int i = 0; i < items.size(); i++)
	{
		os << items[i].getName() << endl;
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
	string item_name;
	is >> item_name;
	while (item_name != "end")
	{
		invoice.addItem(Item(item_name));
		is >> item_name;
	}
	return is;
}