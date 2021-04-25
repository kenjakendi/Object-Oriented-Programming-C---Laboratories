#pragma once
#include "IFigure.h"
#include <string>

class Rectangle :public IFigure
{
	float x, y, width, height;
	std::string style;
public:
	virtual std::string svgText() const;
};