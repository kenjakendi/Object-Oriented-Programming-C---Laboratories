#pragma once
#include "IFigure.h"
#include <string>

class Line :public IFigure
{
	float x1, y1, x2, y2;
	std::string style;
public:
	Line(float x1, float y1, float x2, float y2, std::string style = "");
	virtual std::string svgText() const;
};