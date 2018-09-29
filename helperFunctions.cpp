#include "helperFunctions.hpp"

using std::string;

bool validateInput(string inputStr) {
  bool isValid = true;

  for (int i = 0; i < inputStr.length(); i++) {
    if (!isdigit(inputStr[i])) {
      isValid = false;
    }
  }

  return isValid;
}

bool promptForInput(string inputStr) {
  bool isValid = true;

  for (int i = 0; i < inputStr.length(); i++) {
    if (!isdigit(inputStr[i])) {
      isValid = false;
    }
  }

  return isValid;
}
