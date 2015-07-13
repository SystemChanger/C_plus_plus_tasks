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
        if (cellNum > end() || cellNum < begin())
        {
            cout<<"Error in getCellValue(). 'cellNum'' is out of list size!"<<endl;
            exit(1);
        }
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
        if (memCap < size)
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
            arrayPtr[i] = swapA;
        }

    }

    void insert (int cellToInsertBefore, Type value)
    {
        if (cellToInsertBefore > end() || cellToInsertBefore < begin())
        {
            cout<<"Error in insert(). 'cellToInsertBefore'' is out of list size!"<<endl;
            exit(1);
        }


        if (memCap < size)
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
        if (cellToInsertBefore > end() || cellToInsertBefore < 0)
        {
            cout<<"Error in insert(cellToInsertBefore, amount, value). 'cellToInsertBefore' is out of list size!"<<endl;
            exit(1);
        }

        if (amount > getSize() || amount < 0)
        {
            cout<<"Error in insert(cellToInsertBefore, amount, value). 'amount' can't be bigger than list size!"<<endl;
            exit(1);
        }

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

    void erase(int cellNum)
        {
            if (cellNum > end() || cellNum < 0)
            {
                cout<<"Error in erase(). 'cellNum'' is out of list size!"<<endl;
                exit(1);
            }

            for (int i = cellNum; i < end(); i++)
            {
                arrayPtr[i] = arrayPtr[i + 1];
            }

            size--;
        }

    void erase(int from, int to)
        {
            if (from > size - 1 || to > size - 1)
            {
                cout<<"Error in erase(from, to). 'from'/'to'' is out of list size!"<<endl;
                exit(1);
            }

            if (from < 0 || to < 0)
            {
                cout<<"Error in erase(from, to). 'from'/'to'' is out of list size!"<<endl;
                exit(1);
            }

            if (from > to)
            {
                cout<<"Error in erase(from, to). 'from' can't be bigger than 'to'!"<<endl;
                exit(1);
            }


            int oldsize = size;
            int difference = to - from + 1;
            size = (oldsize - difference);


            if (from < size)
                for (int i = difference - 1; i < size; i++)
                {
                    arrayPtr[i] = arrayPtr[i + difference];
                }
        }


    Type operator [](int cellNum)
    {
        return getCellValue(cellNum);
    }

    void operator - (int amount)
    {
        erase (end() - amount + 1, end());
    }

    void operator + (Type value)
    {
        pushBack(value);
    }

};



#endif // MYLIST_H
