#include "myvector.h"

#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

MyVector::MyVector()
{
    array = new int [1];
    size = 1;
    k = (1+sqrt(5))/2;
}

MyVector::~MyVector()
{
    freeMemory();
}

void MyVector::setCellValue(int cellNum, int value)
{
    array[cellNum] = value;
}

int MyVector::getCellValue(int cellNum)
{
    return array[cellNum];
}

int MyVector::getSize()
{
    return size;
}

void MyVector::expandArray()
{
    size = size+1;
    int *new_array = new int [int(size*k)];

    memcpy(new_array, array, size-1);

    delete [] array;
    array = new_array;
}

void MyVector::pushBack(int value)
{
    expandArray();
    setCellValue(size - 1, value);
}

void MyVector::freeMemory()
{
    delete [] array;
}
