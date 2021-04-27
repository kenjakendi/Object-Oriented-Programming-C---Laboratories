#pragma once
#include <string>
#include <iostream>

class IFigure
{
protected:
	int possition_in_collection;

public:
	virtual ~IFigure() = 0;
	virtual std::string svgText() const = 0;
	virtual std::string* getId() const = 0;
	friend std::ostream& operator<< (std::ostream& os, const IFigure& ifigure);
};
