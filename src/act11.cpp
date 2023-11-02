#include <iostream>

using std::cout;
using std::cin;

int main()
{
  int input;
  int num_limit;
  cout << "How many natural numbers to enter: ";
  cin >> num_limit;
  if (num_limit > 30) {
    cout << "Only 30 natural numbers are allowed.\n";
    return 1;
  }
  int numbers[num_limit];
  cout << "Enter your numbers (press enter to add new number): \n";
  for (int i = 1; i <= num_limit; i++) {
    cout << i << ". ";
    cin >> numbers[i];
  };

  cout << "Your numbers in reverse: ";
  for (int i = num_limit; i > 0; i--) {
    cout << numbers[i] << ", ";
  }
  cout << "\b\b \n";
  return 0;
}