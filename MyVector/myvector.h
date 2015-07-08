#ifndef MYVECTOR
#define MYVECTOR


class MyVector
{
private:
    int *array;
    int size;
    int memCap;
    float k;

    void expandArray();
    void freeMemory();
public:
    MyVector(int);
    ~MyVector();

    void setCellValue(int, int);
    int getCellValue(int);

    int getSize();

    void pushBack(int);
};


#endif // MYVECTOR

