#ifndef LINKEDLIST
#define LINKEDLIST

#define NULL 0


#include <iostream>

using namespace std;



class LinkedList
{
private:
    int size;

    class Field
    {
    private:

    public:
        Field *previousField;
        int value;
        Field *nextField;

        Field(Field *previousField, int value, Field *nextField)
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
        header = new Field(NULL, NULL, NULL);
        newField = new Field(header, NULL, header);

        header->previousField = newField;
        header->nextField = newField;

        size = 0;

        targetField = newField;
    }
    ~LinkedList()
    {
        delete this;
    }

    void add(int value)
    {
        if (size > 0)
        {
            newField = new Field(newField, value, header);
            newField->previousField->nextField = newField;
        }
        else
            newField->value = value;

        size++;
    }

    int getCellValue(int fieldNum)
    {
        if (fieldNum < 0 || fieldNum > size - 1)
        {
            cout<<"Error in getCellValue(). 'CellValue'' is out of list size!"<<endl;
            exit(1);
        }

        for (int i = 0; i < fieldNum; i++)
        {
            targetField = targetField->nextField;
        }

        int value = targetField->value;

        targetField = header->nextField;

        return value;
    }
};

#endif // LINKEDLIST

