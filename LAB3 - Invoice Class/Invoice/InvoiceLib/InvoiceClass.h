#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "ItemClass.h"

class Invoice
{
private:
	std::string name;
	std::string adress;
	std::vector <Item> items;
	bool sameData(Invoice const& invoice) const;
public:
	Invoice(std::string name, std::string adress, std::vector <Item> items = {});
	std::string getName() const;
	std::string getAdress() const;
	std::vector <Item> getItems() const;
	void setName(std::string const name);
	void setAdress(std::string const adress);
	void setItems(std::vector <Item> const items);

	void addItem(Item const& item);
	void removeItem(Item const& item);

	Invoice operator+(Invoice const& invoice) const;
	Invoice operator-(Invoice const& invoice) const;
	Invoice operator+(Item const& item) const;
	Invoice operator-(Item const& item) const;

	void operator+=(Invoice const& invoice);
	void operator-=(Invoice const& invoice);
	void operator+=(Item const& item);
	void operator-=(Item const& item);

	friend std::ostream& operator<< (std::ostream& os, const Invoice& invoice);
	friend std::istream& operator>> (std::istream& is, Invoice& invoice);
};


