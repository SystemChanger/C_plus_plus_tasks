#ifndef LINKEDLIST
#define LINKEDLIST

#define NULL 0


class LinkedList
{
private:
    int size;

    class Field
    {
    private:

    public:
        int value;
        int *nextField;
        int *previousField;

        Field(int value, int *nextField, int *previousField)
        {
            this->value = value;
            this->nextField = nextField;
            this->previousField = previousField;
        }
        ~Field()
        {
            delete this;
        }
    };

public:
    LinkedList()
    {
        Field header = new Field(NULL, &header, &header);
        size = 0;
    }
    ~LinkedList()
    {
        delete this;
    }

    void add(int value)
    {
        Field newField = new Field(value, header, newField.previousField);
        size++;
    }

    int getCellValue(int fieldNum)
    {
    }
};

#endif // LINKEDLIST

