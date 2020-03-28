// HW3_Barmann.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>


void ShowMenu();
void ShowResults(int, int, char);
void GetInput12(int&, int&, char&);
void GetInput24(int&, int&);
void ConvertTo12(int&, char&);
void ConvertTo24(int&, char&);

int main()
{
    bool repeat = true; //set repeat to true so it runs until user tells it to stop
    char choice; //user's choice on the menu screens
    struct time {
        int hour;
        int minute;
        char meridiem; //meridiem is what the 'am' and 'pm' things are called
    };

    time time; //initialize struct to hold time variables

    do {

        ShowMenu(); //display menu to user
        std::cin >> choice; // read in variable to determine what user wants to do

        switch (choice) {
        case '0':
            std::cout << "Quiting program..."; //tell user what's happening
            std::this_thread::sleep_for(std::chrono::seconds(1)); //give user time to glance at message
            repeat = false; //tell loop to terminate at the end
            break;

        case '1': //12 --> 24
            GetInput12(time.hour, time.minute, time.meridiem); //pass the get input function a reference to the variables so it can change each one
            ConvertTo24(time.hour, time.meridiem); //send only the two variables needed to be converted and pass by reference 
            ShowResults(time.hour, time.minute, time.meridiem); //ShowResults needs each function but not reference so only a copy is sent
            break;

        case '2': // 24 --> 12
            GetInput24(time.hour, time.minute);//pass the get input function a reference to the variables so it can change each one
            ConvertTo12(time.hour, time.meridiem); // send only the two variables needed to be convertedand pass by reference
            ShowResults(time.hour, time.minute, time.meridiem);//ShowResults needs each function but not reference so only a copy is sent
            break;

        default:
            std::cout << "Invalid choice. Try again\n"; //tell user choice was invalid and repeat loop
            break;
        }
    } while (repeat == true);

    return 0;
}

//displays the option menu for the user
//does not change any variables
void ShowMenu() {
    std::cout << "\nOptions --'\n";
    std::cout << "1: To convert time from 12-hour notation to 24-hour notation.\n";
    std::cout << "2: To convert time from 24-hour notation to 12-hour notation.\n";
    std::cout << "0: To quit program.\n";
    std::cout << "Choose: ";
}

//program to display results
//again it doesn't change any variables just reads them
//just a bunch of if statements to try and find the right combonation for formatting
//there's so many if's because there needed to be padding when the hour or minute is only one digit
void ShowResults(int hour /*IN*/, int minute /*IN*/, char meridiem /*IN*/) {
    if (meridiem == NULL && hour < 10 && minute >= 10) {
        std::cout << "The time is: " << std::setfill('0') << std::setw(2) << hour << ":" << minute << std::endl;
    }
    else if (meridiem == NULL && hour >= 10 && minute < 10) {
        std::cout << "The time is: " << hour << ":" << std::setfill('0') << std::setw(2) << minute << std::endl;
    }
    else if (meridiem == NULL && hour < 10 && minute < 10) {
        std::cout << "The time is: " << std::setfill('0') << std::setw(2) << hour << ":" << std::setfill('0') << std::setw(2) << minute << std::endl;
    }
    else if (meridiem == NULL) {
        std::cout << "The time is: " << hour << ":" << minute << std::endl;
    }
    else if (meridiem == 'a' && hour < 10 && minute >= 10) {
        std::cout << "The time is: " << std::setfill('0') << std::setw(2) << hour << ":" << minute << " am" << std::endl;
    }
    else if (meridiem == 'a' && hour >= 10 && minute < 10) {
        std::cout << "The time is: " << hour << ":" << std::setfill('0') << std::setw(2) << minute << " am" << std::endl;
    }
    else if (meridiem == 'a' && hour < 10 && minute < 10) {
        std::cout << "The time is: " << std::setfill('0') << std::setw(2) << hour << ":" << std::setfill('0') << std::setw(2) << minute << " am" << std::endl;
    }
    else if (meridiem == 'a') {
        std::cout << "The time is: " << hour << ":" << minute << " am" << std::endl;
    }
    else if (meridiem == 'p' && hour < 10 && minute >= 10) {
        std::cout << "The time is: " << std::setfill('0') << std::setw(2) << hour << ":" << minute << " pm" << std::endl;
    }
    else if (meridiem == 'p' && hour >= 10 && minute < 10) {
        std::cout << "The time is: " << hour << ":" << std::setfill('0') << std::setw(2) << minute << " pm" << std::endl;
    }
    else if (meridiem == 'p' && hour < 10 && minute < 10) {
        std::cout << "The time is: " << std::setfill('0') << std::setw(2) << hour << ":" << std::setfill('0') << std::setw(2) << minute << " pm" << std::endl;
    }
    else if (meridiem == 'p') {
        std::cout << "The time is: " << hour << ":" << minute << " pm" << std::endl;
    }
    else {
        std::cout << "Time was not converted" << std::endl;
    }
}

//program to get input in 24 hour format
//function is passed all three time variables and modifies each one
//24 hour format doesn't use the meridiem so no need to pass it
void GetInput24(int& hour /*INOUT*/, int& minute /*INOUT*/) {
    std::cout << "\nEnter hours: ";
    std::cin >> hour; //get hour 
    while (!std::cin || (hour > 23 || hour < 0)) { //check that hour is int and falls within a valid time
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect format" << std::endl;
        std::cout << "Enter hours: ";
        std::cin >> hour;
    }
    std::cout << "Enter minutes: ";
    std::cin >> minute;
    while (!std::cin || (minute > 60 || minute < 0)) { //check that minute is int and falls within a valid time
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect format" << std::endl;
        std::cout << "Enter minutes: ";
        std::cin >> minute;
    }
}

//get input in the 12 hour format
//funciton modifies each variables by reference so main function can access changes
void GetInput12(int& hour /*INOUT*/, int &minute /*INOUT*/, char& meridiem /*INOUT*/) {
    std::cout << "\nEnter hours: ";
    std::cin >> hour;
    while (!std::cin || (hour > 12 || hour < 0)) {//check that hour is int and falls within a valid time
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect format" << std::endl;
        std::cout << "Enter hours: ";
        std::cin >> hour;
    }
    std::cout << "Enter minutes: ";
    std::cin >> minute;
    while (!std::cin || (minute > 60 || minute < 0)) { //check that minute is int and falls within a valid time
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect format" << std::endl;
        std::cout << "Enter minutes: ";
        std::cin >> minute;
    }
    std::cout << "Enter AM/PM (A or P): ";
    std::cin >> meridiem;
    while (!std::cin || (meridiem != 'A' && meridiem != 'a' && meridiem != 'P' && meridiem != 'p')) { //check that meridiem is char and is correct choice to designate AM or PM
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect format" << std::endl;
        std::cout << "Enter AM/PM (A or P): ";
        std::cin >> meridiem;
    }
}

//convert Input from 24 to 12
//funciton modifies hour variables and meridiem and not minute
//the minute variable is not changed depeding on the format so no need to pass it
void ConvertTo12(int& hour /*INOUT*/, char& meridiem /*INOUT*/) {
    if (hour > 12) {//determine if 24 hour input is morning or evening
        hour = hour % 12; //get remainder if past twelve
        meridiem = 'p'; //set merididem to pm
    }
    else {
        meridiem = 'a'; //set meridiem to am
    }
}

//convert input from 12 to 24
//again funciton modifies only hour and meridiem variable
//minute does not need to be converted in any way
void ConvertTo24(int& hour /*INOUT*/, char& meridiem /*INOUT*/) {
    if ((meridiem == 'p' || meridiem == 'P') && hour < 12) { //determine if 12 hour format is past twelve or before
        hour += 12; //if past twelve then shift time 12 hours
    }
    else if ((meridiem == 'a' || meridiem == 'A') && hour == 12) { //if hour is 12 and in the morning then set hour to 0 (12 hour format doesn't have 0)
        hour = 0;
    }
    meridiem = NULL; //24 hour format doesn't use the meridiem
}