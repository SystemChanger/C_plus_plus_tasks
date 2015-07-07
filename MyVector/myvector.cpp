#include "myvector.h"

#include <iostream>
using namespace std;

MyVector::MyVector(int size)
{
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
    return sizeof(array)/sizeof(int); //Не работает
}

void MyVector::deleteArray()
{
    delete [] array;
}
