#include <iostream>
#include <vector>
#include <fmt/core.h>

const int HOW_MANY_PEOPLE = 10;
const int LEGAL_AGE = 18;
const int FORMAT_STRING = "{}. {}"

int main() {
  std::vector<std::string> legal, underage; // fmt formatted strings
  int input;

  std::cout << "Enter the age of "
    << HOW_MANY_PEOPLE << " people:"
    << std::endl;
  for (int i = 1; i <= HOW_MANY_PEOPLE; i++) {
    std::cout << " " << i << ". ";
    std::cin >> input;
    if (input >= 18) {
      legal.push_back( // so the inputted numbers are easier to track
        fmt::format(FORMAT_STRING, i, input));
    } else {
      underage.push_back(fmt::format(FORMAT_STRING, i, input));
    }
  }

  std::cout << std::endl
    << "Students that are below 18 years old are:\n";
  for (std::string age : underage) {
    std::cout << " " << age << std::endl;
  }
  std::cout << "\nStudents that are of legal age are:\n";
  for (std::string age : legal) {
    std::cout << " " << age << std::endl;
  }

  return 0;
};
