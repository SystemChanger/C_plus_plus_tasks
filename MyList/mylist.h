#ifndef MYLIST_H
#define MYLIST_H


#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


template <typename Type>
class MyList
{
private:
    Type *arrayPtr;
    int size;
    int memCap;
    static const float k = 1.618;

    void expandArray()
        {
            memCap = ceil(size*k);
            Type *new_arrayPtr = new Type [memCap];

            memcpy(new_arrayPtr, arrayPtr, size*sizeof(Type));

            delete [] arrayPtr;
            arrayPtr = new_arrayPtr;
        }

public:
    MyList()
    {
        size = 0;
        memCap = 0;
        arrayPtr = new Type [memCap];
    }

    ~MyList()
    {
        delete [] arrayPtr;
    }

    int begin()
    {
        return 0;
    }

    int end()
    {
        return size - 1;
    }

    int getSize()
    {
        return size;
    }

    Type getCellValue(int cellNum)
    {
        return arrayPtr[cellNum];
    }

    void pushBack(Type value)
    {
        size++;
        if (memCap < size)
        {
            expandArray();
        }

        arrayPtr[end()] = value;
    }

    void pushFront(Type value)
    {
        if (memCap < size*sizeof(Type))
        {
            expandArray();
        }

        arrayPtr[size++] = value;

        Type swapA, swapB;
        for (int i = end(); i > 0; i--)
        {
            swapA = arrayPtr[i - 1];
            swapB = arrayPtr[i];

            arrayPtr[i - 1] = swapB;
            arrayPtr[i] = swap;
        }

    }

    void insert (int cellToInsertBefore, Type value)
    {
        if (memCap < size*sizeof(Type))
        {
            expandArray();
        }

        arrayPtr[size++] = value;

        Type swapA, swapB;
        for (int i = end(); i > cellToInsertBefore; i--)
        {
            swapA = arrayPtr[i - 1];
            swapB = arrayPtr[i];

            arrayPtr[i - 1] = swapB;
            arrayPtr[i] = swapA;
        }

    }

    void insert (int cellToInsertBefore, int amount, Type value)
    {

        int oldsize = size;

        for (int i = 0; i < amount; i++)
        {
            if (memCap < size)
            {
                expandArray();
            }

        arrayPtr[size++] = value;
        }



        int difference = size - oldsize;
        int newCellToInsertBefore = cellToInsertBefore + difference;


        Type *new_arrayPtr = new Type [memCap];
        memcpy(new_arrayPtr, arrayPtr, size*sizeof(Type));

        for (int i = 0; i < size; i++)
            new_arrayPtr[newCellToInsertBefore + i] = arrayPtr[cellToInsertBefore + i];
        for (int i = 1; i <= difference; i++)
            new_arrayPtr[newCellToInsertBefore - i] = value;

        delete [] arrayPtr;
        arrayPtr = new_arrayPtr;

    }

};



#endif // MYLIST_H
