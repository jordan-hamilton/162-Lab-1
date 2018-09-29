#include "readMatrix.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::stoi;
using std::string;

/*********************************************************************
** Description: This function accepts a pointer to a 2D array that
** represents a matrix, and an integer equal to the size of that
** array. It then loops through the array, prompting the user to
** enter integer values into each element into the array until it is
** completely filled.
*********************************************************************/
void readMatrix(int** matrix, int size) {
  string value;

  // Populate one complete row with integer values on the inner loop.
  // The outer loop continues to the next row if one exists.
  for (int j = 0; j < size; j++) {

    for (int i = 0; i < size; i++) {
      do {
        cout << "Please enter an integer to insert into row " << j+1 << ", column " << i+1 << ":" << endl;
        getline(cin, value);
      } while(!validateInput(value));
      matrix[i][j] = stoi(value);
    }

  }

}
