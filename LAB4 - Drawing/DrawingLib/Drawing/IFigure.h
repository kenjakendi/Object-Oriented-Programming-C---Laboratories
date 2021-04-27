#pragma once
#include <string>
#include <iostream>

class IFigure
{
public:
	virtual ~IFigure() = 0;
	virtual std::string svgText() const = 0;
	virtual std::string* getId() const = 0;
	friend std::ostream& operator<< (std::ostream& os, const IFigure& ifigure);
};
