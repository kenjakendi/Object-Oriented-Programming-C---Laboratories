#include <iostream>
#include <string>
#include "Box.h"
using namespace std;

Box::Box(int w, int l, int h, string n)
{
    width = w;
    length = l;
    height = h;
    owner_name = n;
}

Box::~Box()
{
}

void Box::info()
{
    string begining_text;
    string dimensions;
    begining_text = "It's nothing special, only simple box";
    dimensions = to_string(width)+"x"+to_string(length)+"x"+to_string(height);
    if(owner_name != "")
    {
        begining_text += " belonging to " + owner_name;
    }
    cout << begining_text << " with dimensions: " << dimensions << endl;
}
