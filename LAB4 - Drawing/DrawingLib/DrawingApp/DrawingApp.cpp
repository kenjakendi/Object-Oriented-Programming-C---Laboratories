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
#include "../Drawing/MyIterator.cpp"
using namespace std;

int main()
{
	Rectangle rec(100, 100, 100, 100, "fill:red");
	//cout << rec << endl;
	Circle c(100, 100, 100);
	//cout << c << endl;
	Line l(10, 10, 100, 100, "stroke:rgb(0,0,255);stroke-width:5");
	//cout << l << endl;
	float const w = 500;
	float const h = 500;
	vector <IFigure*> v = { &l,&c,&rec,&l,&c,&rec,&c,&rec,&c,&l,&rec};
	Drawing draw("draw1",w, h, v);
	//cout << draw;
	//draw.saveSvg("svg_sample.txt");
	//draw.setHeight(600);
	FigureCollection<IFigure*, vector <IFigure*>, vector <IFigure*>::iterator> col;
	for (int i = 0; i < v.size(); ++i)
	{
		col.push_back(v[i]);
	}

	for (auto i = col.myBegin(); i != col.myEnd(); ++i)
	{
		cout << *i << endl;
	}
	return 0;
}
