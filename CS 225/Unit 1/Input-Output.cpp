#include <iostream> // std::cerr, std::cout, std::endl
#include <fstream>  // std::ifstream 
                    // 1. include <fstream>
#include <string>

int main {
    std::ifstream inFile;  // 2. declare ifstream var

      inFile.open("data.txt"); // 3. open file: must already in project folder
        if (inFile.fail()) // !!! 3.5 check if successful
        { 
          std::cerr << "can't open input file. Abort. \n"; // report to cerr
          return 1;                                        // and terminate now
        }        

          std::string str; // one string from the file
          while (inFile >> str) // read one string; >> will return true if the reading was successful, otherwise return false
          { 
                // process the string just read out
                std::cout << str << std::endl; // print the str on screen
          }
          inFile.close();             // 5. close file
          return 0;
} end main                    