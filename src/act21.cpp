#include <iostream>

const int NUM_LIMIT = 100;
const int X_SIZE = 5;
const int Y_SIZE = 5;

int main()
{
  int num[X_SIZE][Y_SIZE];
  int input;

  for (int y = 0; y < Y_SIZE; y++) {
    for (int x = 0; x < X_SIZE; x++) {
      std::cout << "Enter for (" << y << ", " << x << "): ";

      std::cin >> input;
      if (input > NUM_LIMIT) {
        std::cout
          << "Please input a number less than 100 for number "
          << x-- // postfix decrement here, for demonstration
          << "." << std::endl;
      }
      else {
        num[x][y] = input;
      }

      if (x < 0) {
        y--;
        x++;
      }
    }
  }

  std::cout << "Your newly created table:\n";
  for (int y = 0; y < Y_SIZE; y++) {
    for (int x = 0; x < X_SIZE; x++) {
      std::cout << "\t" << num[x][y];
    }
    std::cout << "\n";
  }

  return 0;
}