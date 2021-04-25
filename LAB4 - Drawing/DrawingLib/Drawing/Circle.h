#pragma once
#include "IFigure.h"
#include <string>

class Circle :public IFigure
{
	float cx, cy, r;
	std::string style;
public:
	virtual std::string svgText() const;
};