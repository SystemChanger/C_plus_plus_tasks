#ifndef LINKEDLIST
#define LINKEDLIST

#define NULL 0


#include <iostream>

using namespace std;


template <typename Type>
class LinkedList
{
private:
    int size;

    class Field
    {
    private:

    public:
        Field *previousField;
        Type value;
        Field *nextField;

        Field(Field *previousField, Type value, Field *nextField)
        {
            this->previousField = previousField;
            this->value = value;
            this->nextField = nextField;
        }
        ~Field()
        {
        }
    };

    Field *header;
      Field *newField;
      Field *targetField;
    Field *tail;

public:
    LinkedList()
    {
        header = new Field(NULL, 0, NULL);
        newField = header;

        tail = new Field(newField, 0, header);
        header->previousField = tail;
        header->nextField = newField;

        size = 0;

        targetField = newField;
    }
    ~LinkedList()
    {
        for (int i = 0; i <= end(); i++)
        {
            targetField = targetField->nextField;
            delete targetField;
        }

        delete header;
        delete tail;
    }

    void push_back(Type value)
    {
        newField = new Field(tail->previousField, value, tail);

        Field *previousField = newField->previousField;
        previousField->nextField = newField;
        tail->previousField = newField;

        size++;
    }

    void push_front(Type value)
    {
        newField = new Field(header, value, header->nextField);
        header->nextField = newField;

        Field *secondField = newField->nextField;
        secondField->previousField = newField;

        size++;
    }

    void insertCellValue(int fieldNum, Type value)
    {
        if (fieldNum < begin() || fieldNum > end())
        {
            cout<<"Error in insertCellValue(fieldNum, value). Cell is out of list size!"<<endl;
            exit(1);
        }

        for (int i = 0; i <= fieldNum; i++)
            targetField = targetField->nextField;

        newField = new Field(targetField->previousField, value, targetField);

        Field *previousField = newField->previousField;
        previousField->nextField = newField;

        Field *nextField = newField->nextField;
        nextField->previousField = newField;

        size++;

        targetField = header;
    }

    void erase(int fieldNum)
    {
        if (fieldNum < begin() || fieldNum > end())
        {
            cout<<"Error in erase(fieldNum). Cell is out of list size!"<<endl;
            exit(1);
        }

        for (int i = 0; i <= fieldNum; i++)
            targetField = targetField->nextField;

        Field *previousField = targetField->previousField;
        Field *nextField = targetField->nextField;

        previousField->nextField = nextField;
        nextField->previousField = previousField;

        size--;

        delete targetField;
        targetField = header;
    }

    void pop_front()
    {
        erase(begin());
    }

    void pop_back()
    {
        erase(end());
    }

    int getSize()
    {
        return size;
    }

    int begin()
    {
        return 0;
    }

    int end()
    {
        return size - 1;
    }

    Type getCellValue(int fieldNum)
    {
        if (fieldNum < begin() || fieldNum > end())
        {
            cout<<"Error in getCellValue(). 'CellValue'' is out of list size!"<<endl;
            exit(1);
        }

        for (int i = 0; i <= fieldNum; i++)
            targetField = targetField->nextField;

        Type value = targetField->value;

        targetField = header;

        return value;
    }

    Type operator [] (int fieldNum)
    {
        return getCellValue(fieldNum);
    }
};

#endif // LINKEDLIST

