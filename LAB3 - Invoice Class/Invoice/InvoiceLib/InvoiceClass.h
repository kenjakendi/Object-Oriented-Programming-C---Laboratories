#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "ItemClass.h"

class Invoice
{
private:
	std::string name; // Name of person on invoice
	std::string adress; // Adress of peron on invoice
	std::vector <Item> items; // List of items on invoice
	bool sameData(Invoice const& invoice) const; // Checks if data on invoice is the same
public:
	// Constructor
	Invoice(std::string name, std::string adress, std::vector <Item> items = {});

	// Returns name, adress or list of items
	std::string getName() const; 
	std::string getAdress() const;
	std::vector <Item> getItems() const;

	// Enables setting new name, adress or new list of items
	void setName(std::string const name);
	void setAdress(std::string const adress);
	void setItems(std::vector <Item> const items);

	//Adds or removes an item from the list
	void addItem(Item const& item);
	void removeItem(Item const& item);

	//Operators
	Invoice operator+(Invoice const& invoice) const;
	Invoice operator-(Invoice const& invoice) const;
	Invoice operator+(Item const& item) const;
	Invoice operator-(Item const& item) const;

	void operator+=(Invoice const& invoice);
	void operator-=(Invoice const& invoice);
	void operator+=(Item const& item);
	void operator-=(Item const& item);

	// In and Out
	friend std::ostream& operator<< (std::ostream& os, const Invoice& invoice);
	friend std::istream& operator>> (std::istream& is, Invoice& invoice);
};


