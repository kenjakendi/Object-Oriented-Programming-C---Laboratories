#include <iostream>
#include "../InvoiceLib/InvoiceClass.h"
#include "../InvoiceLib/InvoiceClass.cpp"

using namespace std;

int main()
{
    Invoice inv = Invoice("Anna", "Warsaw", { "Apple","Banana","Mango" });
    cout << inv;
    Invoice inv2 = Invoice("Anna", "Warsaw");
    cin >> inv2;
    cout << inv2;
    return 0;
}
