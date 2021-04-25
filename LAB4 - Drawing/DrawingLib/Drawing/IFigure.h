#pragma once
#include <string>

class IFigure
{
public:
	virtual ~IFigure() = 0;
	virtual std::string svgText() const = 0;
};
