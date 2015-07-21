#include "linkedlist.h"


#include <iostream>

using namespace std;

int main()
{
    LinkedList<char> list;

    list.add('b');
    list.add('c');
    list.addFirst('a');
    list.add('e');
    list.insertCellValue(list.end()-1, 'd');
    list.add('f');
    list.addFirst('#');
    list.pop_front();
    list.add('$');
    list.pop_back();


    for (int i = 0; i <= list.end(); i++)
        cout << list[i]<< endl;

    return 0;
}

