#include "myvector.h"

#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

MyVector::MyVector(int memCap)
{
    this->memCap = memCap;
    array = new int [memCap];
    size = 1;
    k = (1+sqrt(5))/2;
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
        cout<<"cellNum is out of vector size!"<<endl;
}

int MyVector::getCellValue(int cellNum)
{
    if (cellNum < size && cellNum >= 0)
        return array[cellNum];

    else
    {
        cout<<"cellNum is out of vector size!"<<endl;
        return 0;
    }
}

int MyVector::getSize()
{
    return size;
}

void MyVector::expandArray()
{
    size++;
    int *new_array = new int [int(size*k)];
    memCap++;

    memcpy(new_array, array, (size-1)*sizeof(int));

    delete [] array;
    array = new_array;
}

void MyVector::pushBack(int value)
{
    if (memCap < size)
    {
        expandArray();
        setCellValue(size - 1, value);
    }

    else
    {
        size++;
        setCellValue(size-1, value);
    }
}

void MyVector::freeMemory()
{
    delete [] array;
}
