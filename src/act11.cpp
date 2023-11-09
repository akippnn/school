#include <iostream>

using std::cout;
using std::cin;

const int MAX_NUMBERS = 30;

int main()
{
  int num_limit;
  int numbers[MAX_NUMBERS];

  cout << "How many natural numbers to enter (max " << MAX_NUMBERS << "):";
  cin >> num_limit;
  while (num_limit < 1 || num_limit > 30) {
    cout << std::endl << "Try again: ";
    cin >> num_limit;
  }

  cout << "Enter your numbers (press enter to add new number): \n";
  for (int i = 0; i < num_limit; i++) {
    cout << i + 1 << ". ";
    cin >> numbers[i];
  }

  cout << "Your numbers in reverse: ";
  for (int i = num_limit; i > 0; i--) {
    cout << numbers[i] << ", ";
  }
  cout << "\b\b \n";

  return 0;
}
