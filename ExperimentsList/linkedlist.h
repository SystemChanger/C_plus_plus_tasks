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

    void add(int value)
    {
        newField = new Field(newField, value, header);
        newField->previousField->nextField = newField;

        header->previousField = newField;

        size++;
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

    int getCellValue(int fieldNum)
    {
        if (fieldNum < 0 || fieldNum > size - 1)
        {
            cout<<"Error in getCellValue(). 'CellValue'' is out of list size!"<<endl;
            exit(1);
        }

        for (int i = 0; i <= fieldNum; i++)
        {
            targetField = targetField->nextField;
        }

        int value = targetField->value;

        targetField = header;

        return value;
    }
};

#endif // LINKEDLIST

