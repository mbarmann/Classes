#include "listType.h"
#include <iostream>
#include <array>
#include <assert.h>

//constructor for class
listType::listType(int max) {
    if (max > 0) {
        maxSize = max;
    }
    else {
        maxSize = 5;
    }
    size = 0;
}

//search for element in array
int listType::search(int element /*IN*/) const {
    for (int i = 0; i < size; i++) { //iterate through array until element is found
        if (dataArr[i] == element) {
            return i;
        }
    }
    return -1; //if not found return -1
}
//Pre: element to search for and valid index
//Post: index of element

//find element at certain index
int listType::at(int index/*IN*/) const {
    assert(index >= 0 && index < size); //assert index is valid
    return dataArr[index]; //return array value at index
}
//Pre: valid index value
//Post: element at index

//append item to end of array
bool listType::insert(int element/*IN*/) {
    if (size < maxSize) { //check if array has room
        dataArr[size] = element; //put element at end
        size++; //increase array size by one
        return true;
    }
    else {
        return false; //if array full then return false
    }
}
//Pre: element to append at end of array with room
//Post: array with new value at end

//insert value and shift values down
bool listType::insert(int index/*IN*/, int element/*IN*/) {
    if (size < maxSize) { //check if array has room
        if (index == size) { //if given index is at the end call insert funciton that deals with appending values
            return(insert(element));
        }
        else if (index >= 0 && index < size) { //if index is within valid size
            for (int i = size; i > index; i--) { //start at end and work until index is reached
                dataArr[i] = dataArr[i - 1]; //move values to the right
            }
            dataArr[index] = element; //put new value in newly created spot
            size++; //increase array size
            return true;
        }
        else {
            return false; //if index is invalid return false
        }
    }
    else {
        return false; //if array full then return false
    }
}
//Pre: valid index to insert new element in
//Post: array with new value at index and rest of values shifted down one

//deletes ite in array
bool listType::remove(int index/*IN*/) {
    if (index >= 0 && index < size) { //check if index is valid
        if (index == size - 1) {
            size--; //if index is at end don't worry about moving anything except size
            //when print is called it won't hit that value now
            return true;
        }
        else {
            for (int i = index; i < size - 1; i++) {
                dataArr[i] = dataArr[i + 1]; //move vlaues to the left
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
listType listType::operator+(const listType& list/*IN*/) {
    listType concatList(size + list.size);

    for (int i = 0; i < size; i++) { //iterate through first array and put values in the beggining of new array
        concatList.insert(dataArr[i]);
    }

    for (int i = 0; i < list.size; i++) { //iterate through second array and place though values after the values from the first array
        concatList.insert(list.dataArr[i]);
    }
    return concatList;
}
//Pre: two lists
//Post: htird array with values from first and second arrays

//overload and print out lists
std::ostream& operator<<(std::ostream& out/*INOUT*/, const listType& list /*IN*/) {
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