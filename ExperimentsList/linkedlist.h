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
            delete this;
        }
    };

    Field *header;
    Field *newField;
    Field *targetField;

public:
    LinkedList()
    {
        header = new Field(NULL, 0, NULL);
        newField = header;

        header->previousField = newField;
        header->nextField = newField;

        size = 0;

        targetField = newField;
    }
    ~LinkedList()
    {
        delete this;
    }

    void push_back(Type value)
    {
        newField = new Field(header->previousField, value, header);
        newField->previousField->nextField = newField;

        header->previousField = newField;

        size++;
    }

    void push_front(Type value)
    {
        newField = new Field(header, value, header->nextField);
        header->nextField = newField;
        newField->nextField->previousField = newField;

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
        newField->previousField->nextField = newField;
        newField->nextField->previousField = newField;

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

        targetField->previousField->nextField = targetField->nextField;
        targetField->nextField->previousField = targetField->previousField;

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

