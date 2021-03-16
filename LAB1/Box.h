#include <iostream>

using namespace std;

class Box
{
    int width, length, height;
    string owner_name;

    public:
    Box(int width, int length, int height, string owner_name="");
    ~Box();
    void info(); // shows information about box;
};
