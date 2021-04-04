#include <iostream>
#include "../InvoiceLib/InvoiceClass.h"
#include "../InvoiceLib/InvoiceClass.cpp"
#include "../InvoiceLib/ItemClass.h"
#include "../InvoiceLib/ItemClass.cpp"

using namespace std;

int main()
{
    Item c = Item("c");
    Item b = Item("b");
    Item a = Item("a");
    Invoice inv = Invoice("Anna", "Warsaw", { a,b,c });
    cout << inv;
    Invoice inv2 = Invoice("Anna", "Warsaw");
    cin >> inv2;
    cout << inv2;
    return 0;
}
