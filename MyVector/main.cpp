#include "myvector.h"
#include <iostream>

using namespace std;

int main()
{

    MyVector myVector(10);

    myVector.setCellValue(0, 25);
    myVector.pushBack(8);
    myVector.pushBack(9);


    cout<<myVector.getCellValue(0)<<endl<<myVector.getCellValue(2)<<endl<<myVector.getSize()<<endl;

    return 0;
}

