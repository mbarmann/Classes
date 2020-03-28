// HW5_image_shell.cpp (shell code. ADD CODE #1 and #2)
// by Bin "Crystal" Peng, CS225
// image processing
// blur an image. print it on screen

#include <iostream>
#include <iomanip> // std::setw()


//----------------------------------------------
// global declarations
//----------------------------------------------

// max dimension of 2D array
const int MAX_ROW = 100;
const int MAX_COL = 100;


//----------------------------------------------
// function declarations
//----------------------------------------------


// blur an image
// Pre: pic filled with height x width numbers
// Post: pic is blurred using a 3 x 3 predefined weight mask

// ADD CODE #1: function declaration

// END ADD CODE #1


// print an image on screen
void printImage(const int pic[][MAX_COL]/*IN*/, int height/*IN*/, int width/*IN*/);
// Pre: pic filled with height x width numbers
// Post: image printed to screen. The height and width are printed first and then the image file data is printed

//blur pixels of image
void blur(int pic[][MAX_COL] /*INOUT*/, int height /*IN*/, int width /*IN*/);
//Pre: image array non-blurred 
//    { 10, 100, 10, 100, 10, 100 },
//    { 10, 300, 10, 300, 10, 300 },
//    { 100, 10, 100, 10, 100, 10 },
//    { 300, 10, 300, 10, 300, 10 } }
//Post: pixels without 8 neighbors remain the same but pixels with 8 neighbors will be changed
//weight will be 1 2 1
//               2 2 2
//               1 2 1


//----------------------------------------------

int main()
{
    // one image
    int image[MAX_ROW][MAX_COL] = {
      { 10, 100, 10, 100, 10, 100 },
      { 10, 300, 10, 300, 10, 300 },
      { 100, 10, 100, 10, 100, 10 },
      { 300, 10, 300, 10, 300, 10 } };

    int imgHeight = 4; // height of image
    int imgWidth = 6;  // width of image

    // process the image
    blur(image, imgHeight, imgWidth);
    printImage(image, imgHeight, imgWidth);

    return 0;
} // end main


//----------------------------------------------
// Function Implementation
//----------------------------------------------


// blur an image
// Pre: pic filled with height x width numbers
// Post: pic is blurred using a 3 x 3 predefined weight mask

// ADD CODE #2: implementation of function blur
void blur(int pic[][MAX_COL] /*INOUT*/, int height /*IN*/, int width /*IN*/) {

    int new_pic[MAX_ROW][MAX_COL]; //create new array to hold new values so new values don't mess up the calculations for the pixels around it

    for (int row = 1; row < height - 1; row++) { //skip the two extremes since they won't have 8 neighbors
        for (int col = 1; col < width - 1; col++) { //skip the two extremes since they won't have 8 neighbors
            new_pic[row][col] = ((pic[row - 1][col - 1] * 1) + (pic[row - 1][col] * 2) + (pic[row - 1][col + 1] * 1) + (pic[row][col - 1] * 2) + (pic[row][col] * 2) + (pic[row][col + 1] * 2)
                + (pic[row + 1][col - 1] * 1) + (pic[row + 1][col] * 2) + (pic[row + 1][col + 1] * 1)) / 14; //multiply each pixel by it's designated weight and then divide
        }
    }

    for (int row = 1; row < height - 1; row++) {
        for (int col = 1; col < width - 1; col++) {
            pic[row][col] = new_pic[row][col]; //put new values in the original array, values were passed by reference 
        }
    }

}
// END ADD CODE #2


// print an image to output stream obj out
void printImage(const int pic[][MAX_COL]/*IN*/, int height/*IN*/, int width/*IN*/)
{
    std::cout << height << ' ' << width << '\n';
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            std::cout << std::setw(4) << pic[row][col];
        }
        std::cout << '\n';
    }

} // end printImage
