#include "Line.h"
using namespace std;

Line::Line(float x1, float y1, float x2, float y2, string style)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->style = style;
}

string Line::svgText() const
{
	string str_x1 = " x1=\"" + to_string(x1) + "\"";
	string str_y1 = " y1=\"" + to_string(y1) + "\"";
	string str_x2 = " x2=\"" + to_string(x2) + "\"";
	string str_y2 = " y2=\"" + to_string(y2) + "\"";
	string str_style = " style=\"" + style + "\"";
	string svg_text = "<line" + str_x1 + str_y1 + str_x2 + str_y2 + str_style + " />";
	return svg_text;
}

Line::~Line()
{}