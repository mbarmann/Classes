
#include <iostream>
#include <sstream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <limits>
#include <ios>

std::string removeSpaces(std::string number);
int checkCharacters(std::string number, int n);
std::string convertNumber(std::string number, int n);

int main()
{
    bool repeat = true;
    char selection;
    int num_length;
    int num_characters;
    std::string number;

    while (repeat)
    {
        std::cout << "\nEnter phone number: \n"; //prompt user
        //std::cin >> number;
        std::getline(std::cin, number);
        
        number = removeSpaces(number); //take out spaces from string
        num_length = number.length(); //get length of string

        num_characters = checkCharacters(number, num_length); //check for valid characters
        while (num_characters < 7) { //loop until string is long enough
            num_characters = NULL; //reset characters variable
            std::cout << "\nInvalid Input\n";
            std::cout << "\nEnter phone number: \n";
            std::getline(std::cin, number); //get number
            number = removeSpaces(number); //remove spaces
            num_length = number.length(); //get length
            num_characters = checkCharacters(number, num_length); //check characters before checking again at top
        }

        number = convertNumber(number, num_length); //assign numbers 2-9 to letters
        for (int x = 0; x < 7; x++) { //print out first seven numbers
            if (x == 3) { //if it's the third digit print out hyphen
                std::cout << "-";
            }
            std::cout << number[x];
        }
        std::cout << "\n\n";

            std::cout << "Would you like to continue?\n'y': Yes\n Any other key: No\n"; //prompt user to continue or quit
        std::cin >> selection; //put answer in variable

        if (selection == 'y') { ///give user option to cancel by entering y or Y
            repeat = true; //repeat one more time through
        }
        else {
            repeat = false; //break out of loop when this run is completed and close out
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        selection = NULL;
        number.clear();
        num_length = NULL;
        num_characters = NULL;
    } //break out if user chooses to quit loop

    std::cout << "Quiting program..."; //tell user what's happening
    std::this_thread::sleep_for(std::chrono::seconds(1)); //give user time to glance at message

    return 0;
}

//removes spaces from string
std::string removeSpaces(std::string number) {
    int i = 0, j = 0;
    while (number[i]) //loop while still in string
    {
        if (number[i] != ' ') //if there's a space shift numbers down
            number[j++] = number[i];
        i++;
    }
    number[j] = '\0'; //add terminating character in old position
    return number;
}


//one function for special characters
int checkCharacters(std::string number, int n) {
    int ret_value = 0;
    for (int i = 0; i < n; i++) { //loop through string
        if ((number[i] >= 48 && number[i] <= 57) || (number[i] >= 65 && number[i] <= 90) || (number[i] >= 97 && number[i] <= 122)) { //if character is number or letter add to the total
            ret_value++;
        }
        else {
            if (number[i] != '\0') { //if special character is in string return error
                return -1;
            }
        }
    }
    return ret_value;
}
//one function to convert letters into numbers
//based off of T9 texting
std::string convertNumber(std::string number, int n) {
    for (int i = 0; i <= n; i++) { //assign letter to the appropirate number
        if (number[i] == 'A' || number[i] == 'a' || number[i] == 'B' || number[i] == 'b' || number[i] == 'C' || number[i] == 'c') {
            number[i] = '2';
        }
        else if (number[i] == 'D' || number[i] == 'd' || number[i] == 'E' || number[i] == 'e' || number[i] == 'F' || number[i] == 'f') {
            number[i] = '3';
        }
        else if (number[i] == 'G' || number[i] == 'g' || number[i] == 'H' || number[i] == 'h' || number[i] == 'I' || number[i] == 'i') {
            number[i] = '4';
        }
        else if (number[i] == 'J' || number[i] == 'j' || number[i] == 'K' || number[i] == 'k' || number[i] == 'L' || number[i] == 'l') {
            number[i] = '5';
        }
        else if (number[i] == 'M' || number[i] == 'm' || number[i] == 'N' || number[i] == 'n' || number[i] == 'O' || number[i] == 'o') {
            number[i] = '6';
        }
        else if (number[i] == 'P' || number[i] == 'p' || number[i] == 'Q' || number[i] == 'q' || number[i] == 'R' || number[i] == 'r' || number[i] == 'S' || number[i] == 's') {
            number[i] = '7';
        }
        else if (number[i] == 'T' || number[i] == 't' || number[i] == 'U' || number[i] == 'u' || number[i] == 'V' || number[i] == 'v') {
            number[i] = '8';
        }
        else if (number[i] == 'W' || number[i] == 'w' || number[i] == 'X' || number[i] == 'x' || number[i] == 'Y' || number[i] == 'y' || number[i] == 'Z' || number[i] == 'z') {
            number[i] = '9';
        }
    }
    return number;
}