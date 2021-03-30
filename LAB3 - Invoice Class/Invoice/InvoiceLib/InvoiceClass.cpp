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