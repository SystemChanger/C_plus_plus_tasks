#ifndef MYVECTOR
#define MYVECTOR


class MyVector
{
private:
    int *array;
public:
    MyVector(int);

    void setCellValue(int, int);
    int getCellValue(int);

    int getSize();

    void deleteArray();
};


#endif // MYVECTOR

