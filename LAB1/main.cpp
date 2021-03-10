#include <iostream>
#include "Box.h"
using namespace std;

void error_maker();

int main()
{
    //error_maker();
#ifdef _DEBUG
    string name;
    int width, length, height;
    cout << "Insert owner's name: ";
    cin >> name;
    cout << "Insert width: ";
    cin >> width;
    cout << "Insert length: ";
    cin >> length;
    cout << "Insert height: ";
    cin >> height;
    Box created_box(width, length, height, name);
    created_box.info();
#endif // _DEBUG
    Box box(1, 2, 3);
    box.info();
    Box owned_box(3, 14, 9, "Ala");
    owned_box.info();
    return 0;
}

void error_maker()
{
    int error;
    int destructor = 0;
    error = 1/destructor;
    //Integer division by zero. 
}
