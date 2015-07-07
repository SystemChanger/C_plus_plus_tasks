#ifndef MYVECTOR
#define MYVECTOR


class MyVector
{
private:
    int *array;
    int *new_array;
    int size;
public:
    MyVector(int);

    void setCellValue(int, int);
    int getCellValue(int);

    int getSize();

    void expandArray();
    void pushBack(int);
    void freeMemory();
};


#endif // MYVECTOR

