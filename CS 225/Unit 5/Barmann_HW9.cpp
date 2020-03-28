// Barmann_HW9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "listType.h"
#include <iostream>
#include <array>
#include <assert.h>

int main()
{
    listType list1(2); //create first list
    list1.insert(10); //put 10 in list
    list1.insert(20); //put 20 in list
    std::cout << "List 1: " << list1;
    std::cout << "Is 40 in list 1? Answer (-1 means no):" << list1.search(40) << std::endl;
    std::cout << "Is 10 in list 1? Answer (-1 means no):" << list1.search(10) << std::endl;

    listType list2(4); //create second list
    list2.insert(100); //initilize values
    list2.insert(1000);
    list2.insert(20);
    list2.insert(10);
    std::cout << "List 2: " << list2;
    list2.remove(0); //remove value in first index
    std::cout << "List 2 after removing [0]: " << list2;
    list2.insert(0, 400); //insert 400 in index 0
    std::cout << "List 2 after inserting 400 in [0]: " << list2;

    listType list3 = list1 + list2; //concatenate first and second lists
    std::cout << "List one after + list two: " << list3;
}

