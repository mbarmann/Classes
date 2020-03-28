// HW1_Barmann.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> 

int main()
{
	struct employee { //struct to store each entry's info
		std::string last_name;
		std::string first_name;
		float salary;
	};

	std::string last_name; //store just the last name of each line
	std::string first_name; //store just the first name of each line
	float salary; //store just the salary of each line
	float raise; //store just the raise of each line

	int i = 0; //stores how many entries there are
	std::ifstream inFile; //input file variable
	std::ofstream outFile; //output file variable
	std::vector<employee> person; //initialize employee struct

	inFile.open("data_in.txt"); //open input file

	if (inFile.fail()) {
		std::cerr << "can't open input file. Abort. \n"; //check to see if opening was successful
		return 1;
	}

	while (inFile >> last_name >> first_name >> salary >> raise){ //run loop until EOF is hit
		employee employee; //create instance of employee to store last name, first name, and salary
		employee.last_name = last_name;
		employee.first_name = first_name;
		raise = (raise / 100) + 1; //move decimal over 2 places and add 1 to make it ready to multiply salary
		employee.salary = salary * raise; //adjust salary
		person.push_back(employee); //add more space to vector and put entry information in
		i++; //keep track of number of entries
	}

	inFile.close(); //close input file
	outFile.open("result.txt"); //open output file

	if (outFile.fail()) {
		std::cerr << "can't create output file. Abort. \n";//check to see if opening was successfuls
		return 1;
	}

	for (int x = 0; x < i; x++) {
		/*std::cout << person[x].first_name;
		std::cout << " ";
		std::cout << person[x].last_name;
		std::cout << " ";
		std::cout << person[x].salary << std::endl;*/
		outFile << person[x].first_name; //write first name to file first
		outFile << " ";
		outFile << person[x].last_name; // followed by last name
		outFile << " ";
		outFile << std::setprecision(2) << std::fixed << person[x].salary << std::endl; //then the adjusted salary
	}

  std::cout << i << " records processed";

	outFile.close(); //finished writing to file so close it

	return 0;
}


