#include <iostream>
#include <vector>

const int MAX_NUMBERS = 30;

int main()
{
  int input;
  int limit;
  std::vector<int> numbers;

  std::cout << "How many natural numbers to enter? ";
  do {
    std::cout << "Only " << MAX_NUMBERS
      << " natural numbers are allowed: ";
    std::cin >> limit;
  } while (limit > MAX_NUMBERS);

  std::cout
    << "Enter your numbers (press enter to add new number):"
    << std::endl;
  for (int i = 0; i <= limit; i++) {
    std::cout << i << ". ";
    std::cin >> numbers[i];
  };

  std::cout << "Your numbers in reverse: " << std::endl;
  for (int i = limit; i > 0; i--) {
    std::cout
      << i << ". "
      << numbers[i]
      << std::endl;
  }
  std::cout << "\b\b \n";
  return 0;
}
