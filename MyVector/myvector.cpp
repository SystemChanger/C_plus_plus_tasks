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
    {
        cout<<"cellNum is out of vector size!"<<endl;
        exit(1);
    }
}

int MyVector::getCellValue(int cellNum)
{
    if (cellNum < size && cellNum >= 0)
        return array[cellNum];

    else
    {
        cout<<"cellNum is out of vector size!"<<endl;
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

void MyVector::pushBack(int value)
{
    size++;

    if (memCap < size)
    {
        expandArray();
    }

    setCellValue(size-1, value);
}

void MyVector::freeMemory()
{
    delete [] array;
}
