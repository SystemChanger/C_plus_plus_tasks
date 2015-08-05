#include "linkedlist.h"


#include <iostream>

using namespace std;

int main()
{
    LinkedList<char> list;

    list.push_back('b');
    list.push_back('c');
    list.push_front('a');
    list.push_back('e');
    list.insertCellValue(list.end(), 'd');
    list.push_back('f');
    list.push_front('#');
    list.pop_front();
    list.push_back('$');
    list.pop_back();
    list.push_back('g');


    for (int i = 0; i <= list.end(); i++)
        cout << list[i]<< endl;

    return 0;
}

