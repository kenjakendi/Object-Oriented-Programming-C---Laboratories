#pragma once
#include <string>

class Item
{
private:
	std::string name; // Name of item
public:
	// Constructor
	Item(std::string name);

	// Returns name of item
	std::string getName() const;

	// Enables setting name of item
	void setName(std::string name);

	//Operators
	bool operator==(Item const& item) const;

	friend std::ostream& operator<<(std::ostream& os, const Item& item);
};