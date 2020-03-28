
// HW6_Barmann.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<string>

/*if string length is odd and if move is valid and not past the number of indexes then addmove amount to index
if string lenght is odd and move will make the index invalid then add 1 to move and then find the remainder of i%move
if string length is even and move is valid then add move
if string length is even and move will make index invalid just find i % move and don't add one to move

for each index in string
use ASCII values to find the characters compliment 
numbers add up to 105
so 105-48(0) = 57(9)
upper case letters add up to 155
155-65(A)=90(Z)
lower case letters add up to 219
219-97(a)=122(z)
*/

std::string encrypt(std::string /*IN*/);
//Pre: regulat text string in readable form
//Post: text string that has been shifted to the right by length/2 and each character has been swapped with it's compliment

std::string decrypt(std::string /*IN*/);
//Pre: encrypted text string
//Post: characters are shifted back and swapped back to original text

int main()
{
    std::string text = " ABCabc123!@# ";
    std::string encryptStr = encrypt(text);

    std::cout << "original:  " << text << '\n';
    std::cout << "encrypted: " << encryptStr << '\n';
    std::cout << "decrypted: " << decrypt(encryptStr) << '\n';

}

//function to encrypt
//encryption shifts everything to the right by length/2
//and then swicthes numbers and letters with it's compliment
std::string encrypt(std::string plain) {
    std::string encrypt = plain;
    int length = plain.length();
    int move = length / 2;

    for (int i = 0; i < length; i++) {
        if (length % 2 == 1) { //is string odd or even length
            if (i <= move) { //is the index close to the end of the string 
                encrypt[i + move] = plain[i];
            }
            else if (i > move) {
                encrypt[i % (move + 1)] = plain[i]; //wrap character back to the front of the string since it's too close to the end
            }
        }
        else { // same thing but for even length strings
            if (i < move) {
                encrypt[i + move] = plain[i];
            }
            else if (i >= move) {
                encrypt[i % move] = plain[i];
            }
        }
    }

    for (int i = 0; i < length; i++) {

        if (encrypt[i] > 47 && encrypt[i] < 58) {// numbers
            encrypt[i] = (105 - encrypt[i]); //subtract current ASCII value to find compliment
        }
        else if (encrypt[i] > 64 && encrypt[i] < 91) {//upper case letters
            encrypt[i] = (155 - encrypt[i]); //subtract current ASCII value to find compliment
        }
        else if(encrypt[i] > 96 && encrypt[i] < 123) {//lower case letters
            encrypt[i] = (219 - encrypt[i]); //subtract current ASCII value to find compliment
        }
        else {
            encrypt[i] = encrypt[i];
        }
    }

    return encrypt;
}

//function to decrypt
std::string decrypt(std::string encrypt) {
    std::string decrypt = encrypt;
    int length = encrypt.length();
    int move = length / 2;

    for (int i = 0; i < length; i++) { //same thing as the ecryption function but instead of adding to index it subtracts to move back
        if (length % 2 == 1) {
            if (i < move) {
                decrypt[i + (move + 1)] = encrypt[i];
            }
            else if (i >= move) {
                decrypt[i - move] = encrypt[i];
            }
        }
        else {
            if (i < move) {
                decrypt[i + move] = encrypt[i];
            }
            else if (i >= move) {
                decrypt[i - move] = encrypt[i];
            }
        }
    }

    for (int i = 0; i < length; i++) { //again it's the same thing as the encryption funciton since it doesn't matter what ncharacters are entered

        if (decrypt[i] > 47 && decrypt[i] < 58) {
            decrypt[i] = (105 - decrypt[i]);
        }
        else if (decrypt[i] > 64 && decrypt[i] < 91) {
            decrypt[i] = (155 - decrypt[i]);
        }
        else if (decrypt[i] > 96 && decrypt[i] < 123) {
            decrypt[i] = (219 - decrypt[i]);
        }
        else {
            decrypt[i] = decrypt[i];
        }
    }

    return decrypt;
}