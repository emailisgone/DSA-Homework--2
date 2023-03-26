#include "intcont.h"

IntCont::IntCont(){
    capacity = DEF_CAP;
    size = 0;
    values = new int[capacity];
}

IntCont::~IntCont(){
    delete[] values;
}

int IntCont::getSize() const{
    return size;
}

int IntCont::getMaxSize() const{
    return capacity;
}

void IntCont::resize(int newCapacity){
    int* newValues = new int[newCapacity];
    for(int i=0; i<size; ++i){
        newValues[i] = values[i];
    }
    delete[] values;
    values = newValues;
    capacity = newCapacity;
}

void IntCont::addAt(int pos, int val){
    if(pos<0 || pos>size) throw std::range_error("Out of bounds.");
    if(size == capacity){
        resize(capacity*2);
    }

    for(int i=size-1; i>=pos; --i){
        values[i] = values[i-1];
    }
    values[pos] = val;
    ++size;
}

void IntCont::addFirst(int val){
    addAt(0, val);
}

void IntCont::addLast(int val){
    addAt(size, val);
}

void IntCont::add(int val){
    addLast(val);
}

void IntCont::removeAt(int pos){
    if(pos<0 || pos>size) throw std::range_error("Out of bounds.");
    for(int i=pos; i<size-1; ++i){
        values[i] = values[i+1];
    }
    --size;
}

void IntCont::removeFirst(){
    removeAt(0);
}

void IntCont::removeLast(){
    removeAt(size-1);
}

void IntCont::removeAll(int val){
    for(int i=0; i<size; ++i){
        if(values[i] == val){
            removeAt(i);
            --i;
        }
    }
}

int IntCont::getAt(int pos) const{
    if(pos<0 || pos>size) throw std::range_error("Out of bounds.");
    return values[pos];
}

int IntCont::getFirst() const{
    return getAt(0);
}

int IntCont::getLast() const{
    return getAt(size-1);
}

IntCont IntCont::getAll(int val){
    IntCont result;
    for(int i=0; i<size; ++i){
        if(values[i] == val){
            result.add(i);
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const IntCont& container){
    for(int i=0; i<container.getSize(); ++i){
        os << container.getAt(i) << " ";
    }
    os << std::endl;
    return os;
}