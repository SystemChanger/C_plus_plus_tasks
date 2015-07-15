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
        int *previousField;
        int value;
        int *nextField;

        Field(int *previousField, int value, int *nextField)
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

public:
    LinkedList()
    {
        header = new Field(NULL, NULL, NULL);
        size = 0;
    }
    ~LinkedList()
    {
        delete this;
    }

    void add(int value)
    {
        Field *newField = new Field(NULL, value, header);
        size++;
    }

    int getCellValue(int fieldNum)
    {
    }
};

#endif // LINKEDLIST

