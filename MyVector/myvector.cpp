#include "myvector.h"

#include <iostream>
#include <cstring>

using namespace std;

MyVector::MyVector(int size)
{
    this->size = size;

    this->array = new int [size];
}

void MyVector::setCellValue(int cellNum, int value)
{
    this->array[cellNum] = value;
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
    this->new_array = new int [size + 1];

    memcpy(new_array, array, size);

    delete [] array;
    this->array = new_array;

    this->size = size + 1;
}

void MyVector::pushBack(int value)
{
    expandArray();
    setCellValue(size - 1, value);
}

void MyVector::freeMemory()
{
    delete [] array;
    delete [] new_array;
}
