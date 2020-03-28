#include "queue.h"



bool queue::isEmpty() const {
    if (length == 0) {
        return true; //return true if queue empty
    }
    else {
        return false; //return false if queue not empty
    }
}

int queue::size() const {
    return listSize(); //return current size of queue
}

int queue::front() const {
    return list[0]; //queue is not empty so return first element
}

int queue::back() const {
    return list[length - 1]; //queue is not empty so return last index
}

void queue::enque(int newItem) {
    if (isFull()) { //check to see if queue is full
        std::cout << "queue already full";
        return;
    }
    else {
        list[length] = newItem; //append new element to the end 
        length++; //increase size by one
        return;
    }
}

int queue::deque() {

    int item = front(); //store first item before it's overwritten

    for (int i = 0; i < length - 1; i++) {
        list[i] = list[i + 1]; //move vlaues to the left
    }
    length--; //decrease length by one

    return item;
}

queue::queue(int size) : unorderedArrayListType(size) {
    if (size <= 0) { 
        maxSize = 100; //default size is 100
    }
    else {
        maxSize = size; //masSize is set to whatever the user inputs
    }
    length = 0;
    list = new int[maxSize]; //create queue with set size
}

//overload and print out queue
std::ostream& operator<<(std::ostream& out, const queue& obj)
{
    for (int i = 0; i < obj.length; i++)
        out << obj.list[i] << " ";
    out << "\n";
    return out;
}
//Pre: out stream and list to print
//Post: out with value of entire array