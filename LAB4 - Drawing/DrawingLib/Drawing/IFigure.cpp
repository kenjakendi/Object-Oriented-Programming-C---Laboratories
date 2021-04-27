#include "IFigure.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const IFigure& ifigure)
{
	os << ifigure.svgText();
	return os;
}

IFigure::~IFigure()
{}