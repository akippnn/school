#include <iostream>
#include <vector>
#include <fmt/core.h>

int main() {
  std::vector<std::string> legal;
  std::vector<std::string> underage;
  int input;

  std::cout << "Enter the age of 10 persons:\n";
  for (int i = 0; i < 10; i++) {
    std::cout << " " << i+1 << ". ";
    std::cin >> input;
    if (input >= 18) {
      legal.push_back(fmt::format("{}. {}", i, input));
    } else {
      underage.push_back(fmt::format("{}. {}", i, input));
    }
  }

  std::cout << std::endl << "Students that are below 18 years old are:\n";
  for (std::string age : underage) {
    std::cout << " " << age << " " << std::endl;
  }
  std::cout << "\nStudents that are of legal age are:\n";
  for (std::string age : legal) {
    std::cout << " " << age << " " << std::endl;
  }

  return 0;
};
