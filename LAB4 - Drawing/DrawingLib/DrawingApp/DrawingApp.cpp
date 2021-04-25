#include <iostream>
#include "../Drawing/DrawingClass.h"
#include "../Drawing/DrawingClass.cpp"
#include "../Drawing/Rectangle.h"
#include "../Drawing/Circle.h"
#include "../Drawing/Line.h"
#include "../Drawing/IFigure.h"
#include "../Drawing/IFigure.cpp"
#include "../Drawing/Rectangle.cpp"
#include "../Drawing/Circle.cpp"
#include "../Drawing/Line.cpp"

using namespace std;

int main()
{
	Rectangle rec(100, 100, 100, 100);
	cout << rec.svgText();
}
