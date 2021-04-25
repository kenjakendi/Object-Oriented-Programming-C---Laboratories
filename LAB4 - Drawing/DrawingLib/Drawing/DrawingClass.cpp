#include "DrawingClass.h"
#include <fstream>
#include <chrono>
using namespace std;

Drawing::Drawing(vector <IFigure*> collection)
{
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