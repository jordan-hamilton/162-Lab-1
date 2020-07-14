#include "helperFunctions.hpp"

using std::string;
using std::size_t;


/*********************************************************************
** Description: This function accepts a string, which is then
** looped through to search for non-digit characters. The return
** value is true is there are only digits in the string passed to the
** function, otherwise, the function returns false.
*********************************************************************/
bool validateInput(string inputStr) {
  bool isValid = true;

  for (size_t i = 0; i < inputStr.length(); i++) {
    if (!isdigit(inputStr[i])) {
      isValid = false;
    }
  }

  return isValid;
}
