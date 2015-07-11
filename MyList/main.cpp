#include "mylist.h"

#include <iostream>

using namespace std;

int main()
{
    MyList <int> myList;
    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushFront(8);
    myList.pushFront(4);
    myList.insert(3, 4);
    myList.insert(0, 3, 6);

    for (int i = 0; i < myList.getSize(); i++)
        cout<<myList.getCellValue(i)<<endl;
    return 0;
}

