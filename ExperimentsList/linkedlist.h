#ifndef LINKEDLIST
#define LINKEDLIST

#define NULL 0;


class LinkedList
{
private:
    int size;

    class Field
    {
    private:
        int value;
        int nextField;
        int previousField;

    public:
        Field(int value, int nextField, int previousField)
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
        Field header = new Field(NULL, NULL, NULL);
        size = 0;
    }
    ~LinkedList()
    {
        delete this;
    }

    void add(int value)
    {
        Field newField = new Field(value, header.nextField, header.previousField += 1);
        size++;
    }

    int getCellValue(int fieldNum)
    {

    }
};

#endif // LINKEDLIST

