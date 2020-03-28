// Barmann_HW10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "dynlistType.h"
#include <iostream>
#include <array>
#include <assert.h>

int main()
{
    //list1
    dynlistType list1(2); //create first list
    list1.insert(10); //put 10 in list
    list1.insert(20); //put 20 in list
    std::cout << "List 1: " << list1;
    std::cout << "Is 40 in list 1? Answer (-1 means no):" << list1.search(40) << std::endl;
    std::cout << "Is 10 in list 1? Answer (-1 means no):" << list1.search(10) << std::endl << std::endl;

    //list2
    dynlistType list2(4); //create second list
    list2.insert(100); //initilize values
    list2.insert(1000);
    list2.insert(20);
    std::cout << "List 2: " << list2;
    std::cout << "Value at [1] in list 2: " << list2.at(1) << std::endl; //find value at certain index
    list2.remove(0); //remove value in first index
    std::cout << "List 2 after removing [0]: " << list2;
    list2.insert(0, 400); //insert 400 in index 0
    std::cout << "List 2 after inserting 400 in [0]: " << list2;

    //list3
    dynlistType list3 = list1 + list2; //concatenate first and second lists
    std::cout << "List one after + list two: " << list3;
    if (list1 == list2) { //compare value in two lists
        std::cout << "one == two: 1" << std::endl;
    }
    else {
        std::cout << "one == two: 0" << std::endl;
    }
    list1 = list2; //set list 1 equal to list 2 so they should each have same values
    if (list1 == list2) {//compare value in two lists
        std::cout << "one == two after one = two: 1" << std::endl;
    }
    else {
        std::cout << "one == two after one = two: 0" << std::endl;
    }
    std::cout << "list one after one == two: " << list1 << std::endl; //print out new values in list1

    std::cout << "list three: " << "maxSize " << list3.getMaxSize() << ", " << list3;
    list3.remove(0);
    std::cout << "list three after remove [0]: " << "maxSize " << list3.getMaxSize() << ", " << list3;
    list3.insert(0);
    std::cout << "list three after append/insert:  " << "maxSize " << list3.getMaxSize() << ", " << list3;
    list3.insert(10); //insert 10 at end when size == maxSize
    std::cout << "list three after append/insert:  " << "maxSize " << list3.getMaxSize() << ", " << list3;
    list3.insert(20);
    std::cout << "list three after append/insert:  " << "maxSize " << list3.getMaxSize() << ", " << list3;
    list3.insert(30);
    std::cout << "list three after append/insert:  " << "maxSize " << list3.getMaxSize() << ", " << list3;
    list3.insert(40);
    std::cout << "list three after append/insert:  " << "maxSize " << list3.getMaxSize() << ", " << list3;
    list3.insert(0,0);
    std::cout << "list three after insert (0,0): " << "maxSize " << list3.getMaxSize() << ", " << list3;
    list3.insert(0, 10); //insert 10 at beginning when size == maxSize
    std::cout << "list three after insert (0,10): " << "maxSize " << list3.getMaxSize() << ", " << list3;
    list3.insert(0, 20);
    std::cout << "list three after insert (0,20): " << "maxSize " << list3.getMaxSize() << ", " << list3;
    list3.insert(0, 30);
    std::cout << "list three after insert (0,30): " << "maxSize " << list3.getMaxSize() << ", " << list3;

    return 0;
}