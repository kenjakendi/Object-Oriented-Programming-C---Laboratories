#include "CppUnitTest.h"
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
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DrawingUnitTest
{
	TEST_CLASS(DrawingUnitTest)
	{
	public:
		TEST_METHOD(DrawingGetName)
		{
			float w = 500;
			float h = 500;
			std::string name = "draw1";
			Drawing draw(name, w, h);
			Assert::AreEqual(name, draw.getName());
		}

		TEST_METHOD(DrawingSetName)
		{
			float w = 500;
			float h = 500;
			std::string name = "draw1";
			std::string name2 = "draw2";
			Drawing draw(name, w, h);
			draw.setName(name2);
			Assert::AreEqual(name2, draw.getName());
		}

		TEST_METHOD(DrawingGetWidth)
		{
			float w = 500;
			float h = 500;
			std::string name = "draw1";
			Drawing draw(name, w, h);
			Assert::AreEqual(w, draw.getWidth());
		}

		TEST_METHOD(DrawingSetWidth)
		{
			float w = 500;
			float h = 500;
			std::string name = "draw1";
			Drawing draw(name, w, h);
			float w2 = 600;
			draw.setWidth(w2);
			Assert::AreEqual(w2, draw.getWidth());
		}

		TEST_METHOD(DrawingGetHeight)
		{
			float w = 500;
			float h = 500;
			std::string name = "draw1";
			Drawing draw(name, w, h);
			Assert::AreEqual(h, draw.getHeight());
		}

		TEST_METHOD(DrawingSetHeight)
		{
			float w = 500;
			float h = 500;
			std::string name = "draw1";
			Drawing draw(name, w, h);
			float h2 = 600;
			draw.setHeight(h2);
			Assert::AreEqual(h2, draw.getHeight());
		}

		TEST_METHOD(DrawingGetCollection)
		{
			float w = 500;
			float h = 500;
			Rectangle rec(100, 100, 100, 100, "fill:red");
			Circle c(100, 100, 100);
			Line l(10, 10, 100, 100, "stroke:rgb(0,0,255);stroke-width:5");
			std::vector <IFigure*> v = { &rec,&c,&l };
			std::string name = "draw1";
			Drawing draw(name, w, h, v);
			size_t col_size = draw.getCollection().size();
			Assert::AreEqual(size_t(3), col_size);
		}

		TEST_METHOD(DrawingSetCollection)
		{
			float w = 500;
			float h = 500;
			Rectangle rec(100, 100, 100, 100, "fill:red");
			Circle c(100, 100, 100);
			Line l(10, 10, 100, 100, "stroke:rgb(0,0,255);stroke-width:5");
			std::vector <IFigure*> v = { &rec,&c,&l };
			std::string name = "draw1";
			Drawing draw(name, w, h, v);
			std::vector <IFigure*> v2 = { &l };
			draw.setCollection(v2);
			int col_size = draw.getCollection().size();
			Assert::AreEqual(1, col_size);
		}

		TEST_METHOD(DrawingConstructor)
		{
			Rectangle rec(100, 100, 100, 100, "fill:red");
			Circle c(100, 100, 100);
			Line l(10, 10, 100, 100, "stroke:rgb(0,0,255);stroke-width:5");
			float w = 500;
			float h = 500;
			std::string name = "draw1";
			std::vector <IFigure*> v = { &rec,&c,&l };
			Drawing draw(name, w, h, v);
			Assert::AreEqual(name, draw.getName());
			Assert::AreEqual(w, draw.getWidth());
			Assert::AreEqual(h, draw.getHeight());
		}

		TEST_METHOD(DrawingConstructorNoCollection)
		{
			float w = 500;
			float h = 500;
			std::string name = "draw1";
			Drawing draw(name, w, h);
			Assert::AreEqual(name, draw.getName());
			Assert::AreEqual(w, draw.getWidth());
			Assert::AreEqual(h, draw.getHeight());
			int col_size = draw.getCollection().size();
			Assert::AreEqual(0, col_size);
		}

		TEST_METHOD(DrawingSvgText)
		{
			Rectangle rec(100, 100, 100, 100, "fill:red");
			float w = 500;
			float h = 500;
			std::string name = "draw1";
			std::vector <IFigure*> v = { &rec };
			Drawing draw(name, w, h, v);
			std::string expected_text = "<!DOCTYPE html>\n<html>\n<body>\n<svg width=\"500.000000\" height=\"500.000000\">\n<rect x=\"100.000000\" y=\"100.000000\" width=\"100.000000\" height=\"100.000000\" style=\"fill:red\" />\n</svg>\n</body>\n</html>";
			std::string real_text = draw.svgText();
			Assert::AreEqual(expected_text, real_text);
		}
	};
}
