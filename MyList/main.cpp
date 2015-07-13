#include "mylist.h"

#include <iostream>

using namespace std;

int main()
{
    MyList <char> myList;
    myList.pushBack('a');
    myList.pushBack('b');
    myList.pushBack('c');
    myList.pushFront('d');
    myList.pushFront('e');
    myList.insert(3, 'X');
    myList.insert(0, 3, 'X');
    myList.erase(myList.begin()+3, myList.end()-2);
    myList.erase(myList.end());
    myList.erase(myList.end());
    myList - 1;
    myList + 'L';


    for (int i = 0; i < myList.getSize(); i++)
        cout<<myList[i]<<endl;

    return 0;
}

