#pragma warning(disable : 4996)
#include "DrawingClass.h"
#include <fstream>
#include <ctime>
#include <chrono>
using namespace std;

Drawing::Drawing(string name, float width, float height, vector <IFigure*> collection)
{
	this->name = name;
	this->width = width;
	this->height = height;
	this->collection = collection;
	string message = "Object named " + name + " has been created.";
	saveChange(message);
}

string Drawing::getName() const
{
	return name;
}

void Drawing::setName(string const new_name)
{
	string message = name + ": " + "Name has been changed from: " + name + " to: " + new_name;
	saveChange(message);
	this->name = new_name;
}

float Drawing::getWidth() const
{
	return width;
}

void Drawing::setWidth(float const new_width)
{
	string message = name + ": " + "Width has been changed from: " + to_string(width) + " to: " + to_string(new_width);
	saveChange(message);
	this->width = new_width;
}

float Drawing::getHeight() const
{
	return height;
}

void Drawing::setHeight(float const new_height)
{
	string message = name + ": " + "Height has been changed from: " + to_string(height) + " to: " + to_string(new_height);
	saveChange(message);
	this->width = new_height;
}

vector <IFigure*> Drawing::getCollection() const
{
	return collection;
}

void Drawing::setCollection(vector <IFigure*> const new_collection)
{
	string message = name + ": " + "Collection has been changed";
	saveChange(message);
	this->collection = new_collection;
}

void Drawing::saveChange(string const message) const
{
	const time_t time = getTime();
	fstream file;
	file.open("logs.txt", ios::app);
	file << ctime(&time) << endl;
	file << message << endl << endl;
	file.close();
}

string Drawing::svgText() const
{
	string svg_text = "<!DOCTYPE html>\n<html>\n<body>\n";
	string const str_width = " width=\"" + to_string(width) + "\"";
	string const str_height = " height=\"" + to_string(height) + "\"";
	string const str_svg = "<svg" + str_width + str_height + ">\n";
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

time_t Drawing::getTime() const
{
	chrono::system_clock::time_point ch_time = chrono::system_clock::now();
	const time_t time = chrono::system_clock::to_time_t(ch_time);
	return time;
}

void Drawing::clearLog() const
{
	fstream file;
	file.open("logs.txt", ios::out);
	file.close();
}

ostream& operator<<(std::ostream& os, const Drawing& drawing)
{
	os << drawing.svgText();
	return os;
}