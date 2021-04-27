#include "IFigure.h"
#include <iostream>
using namespace std;

IFigure::~IFigure()
{}

ostream& operator<< (ostream& os, const IFigure& ifigure)
{
	os << ifigure.svgText();
	return os;
}