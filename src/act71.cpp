#include <iostream>
#include <vector>

using std::cin;
using std::cout;

int main()
{
  int input;
  int num_limit;
  std::vector<int> numbers;

  cout << "How many natural numbers to enter: ";
  do {
    cout << "Only 30 natural numbers are allowed.\n";
    cin >> num_limit;
  } while (num_limit > 30);

  cout << "Enter your numbers (press enter to add new number): \n";
  for (int i = 0; i <= num_limit; i++) {
    cout << i << ". ";
    cin >> numbers[i];
  };

  cout << "Your numbers in reverse: " << std::endl;
  for (int i = num_limit; i > 0; i--) {
    cout << i << ". ";
    cout << numbers[i] << std::endl;
  }
  cout << "\b\b \n";
  return 0;
}
