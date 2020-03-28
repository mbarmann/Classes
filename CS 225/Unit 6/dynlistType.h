#pragma once

#ifndef DYNLISTTYPE_H
#define DYNLISTTYPE_H

#include <iostream>

class dynlistType
{
public:
    dynlistType(int max = 5); // constructor
    // Post: maxSize <-- max. if max is not specified or <=0, default value 5 will be used. if max > MAX, MAX will be used
    //       size <-- 0.

    dynlistType(const dynlistType& list); // copy constructor

    int getSize() const { return size; }            // return # of elements actually stored
    int getMaxSize() const { return maxSize; }      // return capacity
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == maxSize; }

    int search(int element) const;  // look for an item. return index of first occurrence
    int at(int index) const;        // return element at a specific location

    void insert(int element);             // append/insert an element at the end
    bool insert(int index, int element);
    // insert an element into location index
    // Shifts the element currently at that index (if any) and any subsequent elements to the right

    bool remove(int index);         // remove element at the specified location

    dynlistType operator+(const dynlistType& list); //override '+'
    dynlistType& operator= (const dynlistType& list); //overload assignment operator

    ~dynlistType(); // destructor

private:
    int* dataPtr; // static array storing data items
    int size;         // actual # of elements stored. size <= maxSize
    int maxSize;      // The capacity of this listType obj. 0 <= maxSize <= MAX.
};

std::ostream& operator<<(std::ostream& out, const dynlistType& list); //override "<<"
bool operator==(const dynlistType& list1, const dynlistType& list2);

#endif DYNLISTTYPE_H