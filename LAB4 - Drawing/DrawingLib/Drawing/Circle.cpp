#include "Circle.h"
using namespace std;

Circle::Circle(float cx, float cy, float r, string style)
{
	this->cx = cx;
	this->cy = cy;
	this->r = r;
	this->style = style;
}

string Circle::svgText() const
{
	string str_cx = " cx=\"" + to_string(cx) + "\"";
	string str_cy = " cy=\"" + to_string(cy) + "\"";
	string str_r = " r=\"" + to_string(r) + "\"";
	string str_style = " style=\"" + style + "\"";
	string svg_text = "<circle" + str_cx + str_cy + str_r + str_style + " />";
	return svg_text;
}

Circle::~Circle()
{}