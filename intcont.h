#ifndef INTCONT_H
#define INTCONT_H

#include <iostream>
#include <stdexcept>

#define DEF_CAP 10

class IntCont{
    private:
    int* values;
    int size;
    int capacity;

    void resize(int newCapacity);

    public:
    IntCont();
    ~IntCont();

    int getSize() const;
    int getMaxSize() const;

    void addAt(int pos, int val);
    void addFirst(int val);
    void addLast(int val);
    void add(int val);

    void removeAt(int pos);
    void removeFirst();
    void removeLast();
    void removeAll(int val);

    int getAt(int pos) const;
    int getFirst() const;
    int getLast() const;
    IntCont getAll(int val);

    friend std::ostream& operator<<(std::ostream& os, const IntCont& container);
};



#endif