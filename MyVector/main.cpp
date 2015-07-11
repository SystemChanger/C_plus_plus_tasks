#include "myvector.h"
#include <iostream>

using namespace std;

int main()
{

    MyVector <char> myVector(1);

    myVector.pushBack('a');
    myVector.pushBack('b');
    myVector.pushBack('c');
    myVector.insert(2, 'd');
    myVector.eraseFromTo(2, 3);
    myVector.pushBack('e');


    for (int i = 0; i < myVector.getSize(); i++)
        cout<<"vector["<<i<<"]: "<<myVector.getCellValue(i)<<endl;
    cout<<"\nvector size: "<<myVector.getSize();

    return 0;
}

