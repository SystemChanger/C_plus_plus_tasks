#include "linkedlist.h"


#include <iostream>

using namespace std;

int main()
{
    LinkedList list;
    list.add(3);
    list.add(5);
    list.add(8);

    for (int i = 0; i <= list.end(); i++)
        cout << list.getCellValue(i)<< endl;

    return 0;
}

