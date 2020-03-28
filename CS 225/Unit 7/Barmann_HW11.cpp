// Barmann_HW11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "arrayListType.h"
#include "unorderedArrayListType.h"
#include "queue.h"

int main()
{
    queue my_queue(25);
    if (my_queue.isEmpty()) {
        std::cout << "The queue is empty" << std::endl;
    }
    else {
        std::cout << "The queue is not empty" << std::endl;
        std::cout << "The queue is: " << my_queue;
    }
    my_queue.enque(19);
    std::cout << "19 added to queue" << std::endl;
    my_queue.enque(13);
    std::cout << "13 added to queue" << std::endl;
    my_queue.enque(4);
    std::cout << "4 added to queue" << std::endl;
    my_queue.enque(64);
    std::cout << "64 added to queue" << std::endl;
    if (my_queue.isEmpty()) {
        std::cout << "The queue is empty" << std::endl;
    }
    else {
        std::cout << "The queue is not empty" << std::endl;
        std::cout << "The queue is: " << my_queue;
    }
    std::cout << "The firs element is: " << my_queue.front() << std::endl;
    std::cout << "The last element is: " << my_queue.back() << std::endl;
    my_queue.deque();
    std::cout << "The queue size is " << my_queue.size() << " after deque()" << std::endl;
    std::cout << "The queue is now: " << my_queue;

    return 0;
} // end main

