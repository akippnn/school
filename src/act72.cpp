#include <iostream>
#include <vector>
#include <fmt/core.h>

using std::cout;
using std::cin;
using std::vector;

int main() {
  vector<int> legal;
  vector<int> underage;
  int input;

  cout << "Enter the age of 10 persons:\n";
  for (int i = 0; i < 10; i++) {
    cout << " " << i+1 << ". ";
    cin >> input;
    if (input >= 18) {
      legal.push_back(fmt::format("{}. {}", i, input);
    } else {
      underage.push_back(fmt::format("{}. {}", i, input);
    }
  }

  cout << "Students that are below 18 years old are:\n";
  for (int age : underage) {
    cout << age << " ";
  }
  cout << "\nStudents that are of legal age are:\n";
  for (int age : legal) {
    cout << age << " ";
  }
};
