#ifndef MYVECTOR
#define MYVECTOR

template <typename Type>
class MyVector
{
private:
    Type *arrayPtr;
    int size;
    int memCap;

    void expandArray();
    void freeMemory();
public:
    MyVector(int);
    ~MyVector();

    static const float k = 1.618;

    void setCellValue(int, Type);
    Type getCellValue(int);

    int getSize();

    void insert(int, Type);
    void eraseFromTo(int, int);
    void pushBack(Type);
};


#endif // MYVECTOR

