#pragma once
#include "IFigure.h"
#include <string>

class Rectangle :public IFigure
{
	float x, y, width, height;
	std::string style;
public:
	Rectangle(float x, float y, float width, float height, std::string style = "");
	virtual std::string svgText() const;
	virtual std::string* getId() const;
	~Rectangle();
};