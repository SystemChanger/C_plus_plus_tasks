#include "myvector.h"

#include <iostream>
#include <cstring>


using namespace std;

MyVector::MyVector(int memCap)
{
    this->memCap = memCap;
    array = new int [memCap];
    size = 0;
}

MyVector::~MyVector()
{
    freeMemory();
}

void MyVector::setCellValue(int cellNum, int value)
{
    if (cellNum < size && cellNum >= 0)
        array[cellNum] = value;

    else
    {
        cout<<"Error in setCellValue(). cellNum is out of vector size!"<<endl;
        exit(1);
    }
}

int MyVector::getCellValue(int cellNum)
{
    if (cellNum < size && cellNum >= 0)
        return array[cellNum];

    else
    {
        cout<<"Error in getCellValue(). cellNum is out of vector size!"<<endl;
        exit(1);
    }
}

int MyVector::getSize()
{
    return size;
}

void MyVector::expandArray()
{
    int *new_array = new int [int(size*k)];
    memCap = int(size*k);

    memcpy(new_array, array, (size-1)*sizeof(int));

    delete [] array;
    array = new_array;
}

void MyVector::insert(int cellNum, int value)
{
    if (cellNum >= size || cellNum < 0)
    {
        cout<<"Error in insert(). cellNum if out of vector size!"<<endl;
        exit(1);
    }

    pushBack(value);

    int switchA, switchB;
    for (int i = size - 1; i > cellNum; i--)
    {
        switchA = array[i - 1];
        switchB = array[i];

        array[i - 1] = switchB;
        array[i] = switchA;
    }
}

void MyVector::deleteFromTo(int from, int to)
{
    if (from > to)
    {
        cout<<"Error in deleteFromTo(). From can't be bigger than To!"<<endl;
        exit(1);
    }


    int oldsize = size;
    int difference = to - from + 1;
    size = (oldsize - difference);
    int *new_array = new int[int(size*k)];
    memCap = int(size*k);

    for (int i = 0; i < from; i++)
    {
        new_array[i] = array[i];
    }

    if (from < size)
        for (int i = difference - 1; i < size; i++)
        {
            new_array[i] = array[i + difference];
        }

    delete[] array;
    array = new_array;
}

void MyVector::pushBack(int value)
{

    if (memCap < size)
    {
        expandArray();
    }

    setCellValue(size++, value);
}

void MyVector::freeMemory()
{
    delete [] array;
}
