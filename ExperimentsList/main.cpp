#include "linkedlist.h"


#include <iostream>

using namespace std;

int main()
{
    LinkedList list;
    list.add(3);
    list.add(5);
    cout << list.getCellValue(1)<< endl;
    return 0;
}

