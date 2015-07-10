#include "myvector.h"

#include <iostream>
#include <cstring>


using namespace std;

template <typename Type>
MyVector<Type>::MyVector(int memCap)
{
    this->memCap = memCap;
    arrayPtr = new Type [memCap];
    size = 0;
}

template <typename Type>
MyVector<Type>::~MyVector()
{
    freeMemory();
}

template <typename Type>
void MyVector<Type>::setCellValue(int cellNum, Type value)
{
    if (cellNum < size && cellNum >= 0)
        arrayPtr[cellNum] = value;

    else
    {
        cout<<"Error in setCellValue(). cellNum is out of vector size!"<<endl;
        exit(1);
    }
}

template <typename Type>
Type MyVector<Type>::getCellValue(int cellNum)
{
    if (cellNum < size && cellNum >= 0)
        return arrayPtr[cellNum];

    else
    {
        cout<<"Error in getCellValue(). cellNum is out of vector size!"<<endl;
        exit(1);
    }
}

template <typename Type>
int MyVector<Type>::getSize()
{
    return size;
}

template <typename Type>
void MyVector<Type>::expandArray()
{
    Type *new_arrayPtr = new Type [int(size*k)];
    memCap = int(size*k);

    memcpy(new_arrayPtr, arrayPtr, (size-1)*sizeof(Type));

    delete [] arrayPtr;
    arrayPtr = new_arrayPtr;
}

template <typename Type>
void MyVector<Type>::insert(int cellNum, Type value)
{
    if (cellNum >= size || cellNum < 0)
    {
        cout<<"Error in insert(). cellNum if out of vector size!"<<endl;
        exit(1);
    }

    pushBack(value);

    Type switchA, switchB;
    for (int i = size - 1; i > cellNum; i--)
    {
        switchA = arrayPtr[i - 1];
        switchB = arrayPtr[i];

        arrayPtr[i - 1] = switchB;
        arrayPtr[i] = switchA;
    }
}

template <typename Type>
void MyVector<Type>::eraseFromTo(int from, int to)
{
    if (from > size - 1 || to > size - 1)
    {
        cout<<"Error in eraseFromTo(). From/To is out of vector size!"<<endl;
        exit(1);
    }

    if (from < 0 || to < 0)
    {
        cout<<"Error in eraseFromTo(). From/To is out of vector size!"<<endl;
        exit(1);
    }

    if (from > to)
    {
        cout<<"Error in eraseFromTo(). From can't be bigger than To!"<<endl;
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

template <typename Type>
void MyVector<Type>::pushBack(Type value)
{

    if (memCap < size*sizeof(Type))
    {
        expandArray();
    }

    setCellValue(size++, value);
}

template <typename Type>
void MyVector<Type>::freeMemory()
{
    delete [] arrayPtr;
}
