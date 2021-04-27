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
	string svg_text = "<line" + str_x1 + str_y1 + str_x2 + str_y2;
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

string* Line::getId() const
{
	string number_of_figure = "3";
	string description = "Line, point1 = (" + to_string(x1) + "," + to_string(y1) + ") point2 = (" + to_string(x2) + "," + to_string(y2) + ")";
	static string id[3] = { number_of_figure, description };
	return id;
}

Line::~Line()
{}