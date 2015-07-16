#include "linkedlist.h"


#include <iostream>

using namespace std;

int main()
{
    LinkedList<char> list;
    list.add('a');
    list.add('b');
    list.add('c');
    list.add('d');
    list.addFirst('e');
    list.insertCellValue(3, 'f');
    list.insertCellValue(0, 'g');
    list.deleteCell(list.begin());
    list.deleteCell(list.end());

    for (int i = 0; i <= list.end(); i++)
        cout << list[i]<< endl;

    return 0;
}

