#pragma once
#include "IFigure.h"
#include <string>

class Circle :public IFigure
{
	float cx, cy, r;
	std::string style;
public:
	Circle(float cx, float cy, float r, std::string style = "");
	virtual std::string svgText() const;
	virtual std::string* getId() const;
	~Circle();
};