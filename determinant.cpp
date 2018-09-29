#include "determinant.hpp"

/*********************************************************************
** Description: This function accepts a pointer to a 2D array that
** represents a matrix, and an integer equal to the size of that
** array. It then calculates the determinant of that array based on
** the possible sizes passed to our function. By nature, this is
** restricted to calculating 2x2 or 3x3 matrices.
** Source: https://www.mathsisfun.com/algebra/matrix-determinant.html
*********************************************************************/
int determinant(int** mat, int size){
  int determinant = 0;

  if (size == 2) {

    determinant = (mat[0][0]*mat[1][1]) - (mat[0][1]*mat[1][0]);

  } else if (size == 3) {

    determinant = mat[0][0]*(mat[1][1]*mat[2][2]-mat[1][2]*mat[2][1])
                  -mat[0][1]*(mat[1][0]*mat[2][2]-mat[1][2]*mat[2][0])
                  +mat[0][2]*(mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0]);

  }

  return determinant;
}
