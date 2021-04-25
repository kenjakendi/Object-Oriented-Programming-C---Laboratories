#pragma once
#include "IFigure.h"
#include <string>

class Line :public IFigure
{
	float x1, y1, x2, y2;
	std::string style;
public:
	virtual std::string svgText() const;
};