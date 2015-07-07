#include "myvector.h"
#include <iostream>

using namespace std;

int main()
{

    MyVector myVector(10);

    myVector.setCellValue(0, 25);
    myVector.pushBack(8);


    cout<<myVector.getCellValue(0)<<endl<<myVector.getCellValue(10)<<endl<<myVector.getSize()<<endl;


    myVector.freeMemory();
    return 0;
}

