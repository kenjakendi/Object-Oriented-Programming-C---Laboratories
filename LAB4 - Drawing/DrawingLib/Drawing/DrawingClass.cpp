#include "DrawingClass.h"
#include <fstream>
#include <chrono>
using namespace std;

Drawing::Drawing(string name, float width, float height, vector <IFigure*> collection)
{
	this->name = name;
	this->width = width;
	this->height = height;
	this->collection = collection;
}

time_t Drawing::getTime() const
{
	chrono::system_clock::time_point ch_time = chrono::system_clock::now();
	time_t time = chrono::system_clock::to_time_t(ch_time);
	return time;
}

vector <IFigure*> Drawing::getCollection() const
{
	return collection;
}

void Drawing::setCollection(vector <IFigure*> const new_collection)
{
	this->collection = new_collection;
}

string Drawing::svgText() const
{
	string svg_text = "<!DOCTYPE html>\n<html>\n<body>\n";
	string str_width = " width=\"" + to_string(width) + "\"";
	string str_height = " height=\"" + to_string(height) + "\"";
	string str_svg = "<svg" + str_width + str_height + ">\n";
	svg_text += str_svg;
	for (int i = 0; i < collection.size(); i++)
	{
		svg_text += collection[i]->svgText() + "\n";
	}
	svg_text += "</svg>\n</body>\n</html>";
	return svg_text;
}

void Drawing::saveSvg(string const file_name) const
{
	fstream file;
	file.open(file_name, ios::out);
	file << *this;
	file.close();
}

ostream& operator<<(std::ostream& os, const Drawing& drawing)
{
	os << drawing.svgText();
	return os;
}