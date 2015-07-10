#include "myvector.h"
#include <iostream>

using namespace std;

int main()
{

    MyVector myVector(10);

    myVector.pushBack(25);
    myVector.pushBack(8);
    myVector.pushBack(9);
    myVector.insert(2, 24);
    myVector.eraseFromTo(2, 3);
    myVector.pushBack(35);


    for (int i = 0; i < myVector.getSize(); i++)
        cout<<"vector["<<i<<"]: "<<myVector.getCellValue(i)<<endl;
    cout<<"\nvector size: "<<myVector.getSize();

    return 0;
}

