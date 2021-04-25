#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(float x, float y, float width, float height, string style)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->style = style;
}

string Rectangle::svgText() const
{
	string str_x = " x=\"" + to_string(x) + "\"";
	string str_y = " y=\"" + to_string(y) + "\"";
	string str_width = " width=\"" + to_string(width) + "\"";
	string str_height = " height=\"" + to_string(height) + "\"";
	string svg_text = "<rect" + str_x + str_y + str_width + str_height;
	if (style=="")
	{
		svg_text += " />";
	}
	else
	{
		string str_style = " style=\"" + style + "\"";
		svg_text += str_style + " />";
	}
	return svg_text;
}

Rectangle::~Rectangle()
{}