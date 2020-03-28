#include "dynlistType.h"
#include <iostream>
#include <array>
#include <assert.h>

dynlistType::dynlistType(int maxSize) { //constructor
    if (maxSize < 5) { // invalid value
        this->maxSize = 5;
    }
    else {
        this->maxSize = maxSize;
    }

    dataPtr = new int[this->maxSize];
    size = 0;
}

dynlistType::dynlistType(const dynlistType& list) { //copy constructor
    size = list.size;
    maxSize = list.maxSize;
    dataPtr = new int[size];

    for (int i = 0; i < this->size; i++) {
        this->dataPtr[i] = list.dataPtr[i];
    }
}

dynlistType::~dynlistType() { //destructor
    if (dataPtr != NULL) {
        delete[] dataPtr;
    }
}



//search for element in array
int dynlistType::search(int element /*IN*/) const {
    for (int i = 0; i < size; i++) { //iterate through array until element is found
        if (dataPtr[i] == element) {
            return i;
        }
    }
    return -1; //if not found return -1
}
//Pre: element to search for and valid index
//Post: index of element

//find element at certain index
int dynlistType::at(int index/*IN*/) const {
    assert(index >= 0 && index < size); //assert index is valid
    return dataPtr[index]; //return array value at index
}
//Pre: valid index value
//Post: element at index

//append item to end of array
//double maxSize if size is equal or bigger
void dynlistType::insert(int element/*IN*/) {
    if (size < maxSize) { //check if array has room
        dataPtr[size] = element; //put element at end
    }
    else {
        maxSize = 2 * maxSize; //double maxSize
        int* newPtr = new int[maxSize]; //create temp ptr
        for (int i = 0; i < size; i++) {
            newPtr[i] = dataPtr[i];//copy values in dataPtr to newPtr
        }
        newPtr[size] = element; //insert new element at end
        delete[] dataPtr; //remove old memory in dataPtr
        dataPtr = newPtr; //set empty dataPtr equal to temp ptr
    }
    size++;
}
//Pre: element to append at end of array with room
//Post: array with new value at end, does not return bool anymore

//insert value and shift values down
//double maxSize if size is equal or bigger
bool dynlistType::insert(int index/*IN*/, int element/*IN*/) {
    if (index >= 0 && index <= size) { //check if index is valid
        if (size >= maxSize) { //check if maxSize needs to be doubled
            maxSize = 2 * maxSize; //double maxSize
            int* newPtr = new int[maxSize]; //create temp ptr
            for (int i = 0; i < size; i++) {
                newPtr[i] = dataPtr[i]; //copy values in dataPtr to newPtr
            }
            delete[] dataPtr; //remove old memory in dataPtr
            dataPtr = newPtr; //set empty dataPtr equal to temp ptr
        }
        for (int i = size; i > index; i--) { //start at end and work until index is reached
                dataPtr[i] = dataPtr[i - 1]; //move values to the right
            }
        dataPtr[index] = element; //put new value in newly created spot
        size++; //increase size by one for new inserted value
        return true;
    }
    else {
        return false; //return false if index is invalid
    }
}
//Pre: valid index to insert new element in
//Post: array with new value at index and rest of values shifted down one, still returns bool

//deletes ite in array
bool dynlistType::remove(int index/*IN*/) {
    if (index >= 0 && index < size) { //check if index is valid
        if (index == size - 1) {
            size--; //if index is at end don't worry about moving anything except size
            //when print is called it won't hit that value now
            return true;
        }
        else {
            for (int i = index; i < size - 1; i++) {
                dataPtr[i] = dataPtr[i + 1]; //move vlaues to the left
            }
            size--; //decrease size so empty value won't be hit
            return true;
        }
    }
    else {
        return false; //if index is not valid then return false
    }
}
//Pre: index to remove value in array
//Post: array with value removed and rest of values shifted up one

//concatenate arrays
dynlistType dynlistType::operator+(const dynlistType& list/*IN*/) {
    dynlistType concatList(size + list.size);

    for (int i = 0; i < size; i++) { //iterate through first array and put values in the beggining of new array
        concatList.insert(dataPtr[i]);
    }

    for (int i = 0; i < list.size; i++) { //iterate through second array and place though values after the values from the first array
        concatList.insert(list.dataPtr[i]);
    }
    return concatList;
}
//Pre: two lists
//Post: third array with values from first and second arrays

//overload and print out lists
std::ostream& operator<<(std::ostream& out/*INOUT*/, const dynlistType& list /*IN*/) {
    int size = list.getSize(); //size is used to go through the array

    out << "[";
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            out << list.at(i); //print each value
        }
        else {
            out << ", " << list.at(i); //print each value
        }
    }
    out << "]" << "\n";
    return out;
}
//Pre: out stream and list to print
//Post: out with value of entire array

//overload assignment operator
dynlistType& dynlistType::operator= (const dynlistType& list) {
    if (this == &list) { return *this; } //make sure you aren't self-assigning
    if (dataPtr != NULL) { delete dataPtr; } // get rid of the old data

    size = list.size;
    maxSize = list.maxSize;
    dataPtr = new int[size];
    for (int i = 0; i < size; ++i) {
        dataPtr[i] = list.dataPtr[i];
    }
    return *this;
}

//overload comparison (==) operator
bool operator== (const dynlistType& list1, const dynlistType& list2) {
    int size1 = list1.getSize();
    int size2 = list2.getSize();
    
    if (size1 != size2) { //both contains unequal number of elements
        return false;
    }

    for (int i = 0; i < size1; i++) {
        if (list1.at(i) != list2.at(i))
            return false; //unequal values
    }
    return true; //both contains same values in order
}