// HW7_Barmann.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <new>

// read in a number
int* readNum(int& numOfDigits/*OUT*/);
//Pre: variable to hold pointer size
//Post: pointer with a number and its size

// add two numbers. Store result in third
//Pseudo code: 
// start at end of pointer and add each number of the pionters
// if the result is over 9 hold the 1 (ten's place) in a carry vale
// move through pointers until beginning of smallest pointer is reached
// then if larger pointer is not at beginnning add those in to result pointer
// if both pointers are the same size and they add up to mor than 10 put the extra one in fornt of the current first digit
int* sumNum(const int* pointer1/*IN*/, int numOfDigits1/*IN*/, const int* pointer2/*IN*/, int numOfDigits2/*IN*/, int& numOfDigitsResult/*OUT*/);
// Pre: pointers 1 + 2 wiht numbers and their sizes then result pointer with nothing in it and not initialized with a size
// Post: pointers 1 + 2 along with their sizes are untouched while the result pointer has the sum and the size of the pointer

// print a number stored in int array
void print(const int* sum/*IN*/, int numOfDigits/*IN*/);
//Pre: sum pointer with sum od pointer 1 + 2 and the size of the sum pointer
//Post: nothing is changed since pointer size is copied and not passed by reference 

int main()
{
    //initialize first pointer variables
    int numOfDigits1 = 0;
    int* pointer1 = readNum(numOfDigits1);

    //initialize second pointer variables
    int numOfDigits2 = 0 ;
    int* pointer2 = readNum(numOfDigits2);

    //initialize sum pointer variables
    int numOfDigitsResult = 0;
    int* sum = sumNum(pointer1, numOfDigits1, pointer2, numOfDigits2, numOfDigitsResult);
    
    //print out results
    print(sum, numOfDigitsResult);

    //clear memory
    delete[] pointer1;
    delete[] pointer2;
    delete[] sum;

    return 0;
}

int* readNum(int& numOfDigits/*OUT*/) {
    int num;
    int* value;

    std::cout << std::endl << "How many digits? ";
    std::cin >> numOfDigits;

    value = new (std::nothrow) int[numOfDigits];

    //scan in each digit to pointer 
    for (int i = 0; i < numOfDigits; i++) {
        std::cout << "Enter a positive integer: ";
        std::cin >> value[i];
        if (value[i] >= 0 && value[i] <= 9) {

        }
        else {
            i--;
            std::cout << "Number must be 0-9" << std::endl;
        }
    }
    return value;
}

int* sumNum(const int* pointer1/*IN*/, int numOfDigits1/*IN*/, const int* pointer2/*IN*/, int numOfDigits2/*IN*/, int& numOfDigitsResult/*OUT*/) {
    int carry = 0;
    int s;
    int* sum;
    
    if (numOfDigits1 >= numOfDigits2) {
        numOfDigitsResult = numOfDigits1;
        int numResultHold = numOfDigitsResult;

        //initialize sum pointer with size
        sum = new (std::nothrow) int[numOfDigitsResult];
        //move through smallest array until at beginning
        while (numOfDigits2 > 0) {
            s = pointer1[numOfDigits1 - 1] + pointer2[numOfDigits2 - 1] + carry;
            sum[numResultHold - 1] = (s % 10);
            carry = s / 10;
            numOfDigits1--;
            numOfDigits2--;
            numResultHold--;
        }
        //if one pointer is bigger then finish moving variables into sum
        while (numOfDigits1 > 1) {
            s = pointer1[numOfDigits1 - 1] + carry;
            sum[numResultHold - 1] = (s % 10);
            carry = s / 10;

            numOfDigits1--;
            numResultHold--;
        }

        //if there is a value in carry put it at the beginning
        if (numOfDigits1 > 0) {
            s = pointer1[numOfDigits1 - 1] + carry;
            sum[numResultHold - 1] = s;
        }
        else {
            sum[numResultHold] = s;
        }

    }
    else {
        numOfDigitsResult = numOfDigits2;
        int numResultHold = numOfDigitsResult;

        sum = new (std::nothrow) int[numOfDigitsResult];
        //move through smallest array until at beginning
        while (numOfDigits1 > 0) {
            s = pointer1[numOfDigits1 - 1] + pointer2[numOfDigits2 - 1] + carry;
            sum[numResultHold - 1] = (s % 10);
            carry = s / 10;
            numOfDigits1--;
            numOfDigits2--;
            numResultHold--;
        }
        //if one pointer is bigger then finish moving variables into sum
        while (numOfDigits2 > 1) {
            s = pointer2[numOfDigits2 - 1] + carry;
            sum[numResultHold - 1] = (s % 10);
            carry = s / 10;

            numOfDigits2--;
            numResultHold--;
        }
        //if there is a value in carry put it at the beginning
        if (numOfDigits2 > 0) {
            s = pointer1[numOfDigits2 - 1] + carry;
            sum[numResultHold - 1] = s;
        }
        else {
            sum[numResultHold] = s;
        }
    }
    return sum;
}

void print(const int* sum/*IN*/, int numOfDigits/*IN*/) {
    std::cout << "Sum: ";
    for (int i = 0; i < numOfDigits; i++) {
        std::cout << sum[i];
    }
}