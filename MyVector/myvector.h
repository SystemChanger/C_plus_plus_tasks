#ifndef MYVECTOR
#define MYVECTOR


class MyVector
{
private:
    int *array;
    int size;
    int memCap;

    void expandArray();
    void freeMemory();
public:
    MyVector(int);
    ~MyVector();

    static const float k = 1.618;

    void setCellValue(int, int);
    int getCellValue(int);

    int getSize();

    void insert(int, int);
    void pushBack(int);
};


#endif // MYVECTOR

