#pragma once
#include <string>
#include <vector>
#include <iostream>

class Invoice
{
private:
	std::string name;
	std::string adress;
	std::vector <std::string> items;
	bool sameData(Invoice const& invoice) const;
public:
	Invoice(std::string name, std::string adress, std::vector <std::string> items = {});
	std::string getName() const;
	std::string getAdress() const;
	std::vector <std::string> getItems() const;
	void setName(std::string const name);
	void setAdress(std::string const adress);
	void setItems(std::vector <std::string> const items);

	void addItem(std::string const& item_name);
	void removeItem(std::string const& item_name);

	Invoice operator+(Invoice const& invoice) const;
	Invoice operator-(Invoice const& invoice) const;
	Invoice operator+(std::string const& item_name) const;
	Invoice operator-(std::string const& item_name) const;

	void operator+=(Invoice const& invoice);
	void operator-=(Invoice const& invoice);
	void operator+=(std::string const& item_name);
	void operator-=(std::string const& item_name);

	friend
	std::ostream& operator<< (std::ostream& os, const Invoice& invoice);
};