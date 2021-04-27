#include "Circle.h"
using namespace std;

Circle::Circle(float cx, float cy, float r, string style)
{
	this->cx = cx;
	this->cy = cy;
	this->r = r;
	this->style = style;
	this->possition_in_collection = 2;
}

string Circle::svgText() const
{
	string str_cx = " cx=\"" + to_string(cx) + "\"";
	string str_cy = " cy=\"" + to_string(cy) + "\"";
	string str_r = " r=\"" + to_string(r) + "\"";
	string svg_text = "<circle" + str_cx + str_cy + str_r;
	if (style == "")
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

string* Circle::getId() const
{
	string number_of_figure = to_string(possition_in_collection);
	string description = "Circle, point = (" + to_string(cx) + "," + to_string(cy) + ") radius: " + to_string(r);
	static string id[3] = { number_of_figure, description };
	return id;
}

Circle::~Circle()
{}