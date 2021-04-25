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
	cout << rec << endl;
	Circle c(100, 100, 100);
	cout << c << endl;
	Line l(10, 10, 100, 100);
	cout << l << endl;
	float w = 500;
	float h = 500;
	vector <IFigure> v = { rec,c,l };
	Drawing draw(w, h, v);
}
