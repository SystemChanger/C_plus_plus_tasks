#ifndef MYVECTOR
#define MYVECTOR


class MyVector
{
private:
    int *array;
    int size;
    int memCap;
    float k;
public:
    MyVector(int);
    ~MyVector();

    void setCellValue(int, int);
    int getCellValue(int);

    int getSize();

    void expandArray();
    void pushBack(int);
    void freeMemory();
};


#endif // MYVECTOR

