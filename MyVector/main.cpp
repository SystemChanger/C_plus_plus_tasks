#include "myvector.h"
#include <iostream>

using namespace std;

int main()
{

    MyVector myVector(10);

    myVector.setCellValue(0, 25);

    cout<<myVector.getCellValue(0)<<endl<<myVector.getSize()<<endl;


    myVector.deleteArray();
    return 0;
}

