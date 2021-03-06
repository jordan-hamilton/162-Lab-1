/*********************************************************************
** Program name: Lab 1
** Author: Jordan Hamilton
** Date: 09/29/2018
** Description: This program prompts the user to select a size
** (2x2 or 3x3) from a menu, then dynamically allocates a 2D array of
** the selected size that represents a matrix. A pointer to the array
** and the array's size are passed to the readMatrix function to fill
** the array with integer values. The pointer and size are passed
** again the determinant function to calculate the determinant.
** A visual representation of the matrix as well as the calculated
** determinant are displayed to the user.
*********************************************************************/

#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

#include "determinant.hpp"
#include "helperFunctions.hpp"
#include "readMatrix.hpp"


using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::stoi;
using std::string;

void deleteMatrix(int** matrix, int size);
int** makeMatrix(int size);
void printMatrix(int** matrix, int size);

/***********************************************************************************************
** Description: This program can be run via the lab1 executable generated by make.
***********************************************************************************************/
int main() {
  string menuChoice;
  int** matrix;
  int matrixSize = 0;

  cout << endl << "Matrix Determinant Calculator" << endl;
  do {
    cout << "Select a valid matrix size to calculate the determinant:" << endl;
    cout << "1) 2x2" << endl;
    cout << "2) 3x3" << endl;
    getline(cin, menuChoice);
  } while(!validateInput(menuChoice));

  while (menuChoice != "1" && menuChoice != "2") {
    cout << "Please select a menu option to specify valid matrix size:" << endl;
    cout << "1) 2x2" << endl;
    cout << "2) 3x3" << endl;
    getline(cin, menuChoice);
  }

  matrixSize = stoi(menuChoice) + 1;

  matrix = makeMatrix(matrixSize);
  readMatrix(matrix, matrixSize);
  printMatrix(matrix, matrixSize);
  cout << "Determinant: " << determinant(matrix, matrixSize) << endl;
  deleteMatrix(matrix, matrixSize);
}


/***********************************************************************************************
** Description: Delete the 2D array dynamically created in the newMatrix function. Arguments
** are an address to a pointer to a 2D array and the size of that array as an integer.
** Source: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
***********************************************************************************************/
void deleteMatrix (int** matrix, int size) {

  for (int i = 0; i < size; ++i) {
    delete [] matrix[i];
  }
  delete [] matrix;

}


/************************************************************************************************
** Description: This function takes the size selected by the user as an argument, then
** dynamically creates a 2D array with the number of rows and columns equal to that size. The
** function then returns a pointer to the 2D array.
** Source: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
************************************************************************************************/
int** makeMatrix(int size) {
  int** newMatrix = new int*[size];

  for (int i = 0; i < size; i++) {
    newMatrix[i] = new int[size];
  }

  return newMatrix;
}


/*********************************************************************
** Description: This function accepts a pointer to a 2D array that
** represents a matrix, and an integer equal to the size of that
** array. It then prints out each element in the 2D array using an
** inner for loop to print all values in each row on one line before
** starting a new line and repeating until all elements have been
** printed.
*********************************************************************/
void printMatrix(int** matrix, int size) {
  for (int j = 0; j < size; j++) {
    cout << "| " ;
    for (int i = 0; i < size; i++) {
      cout << setw(6) << matrix[i][j] << "|";
    }
    cout << endl;
  }
}
