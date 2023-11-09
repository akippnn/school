#include <iostream>

using std::cin;
using std::cout;

const int NUM_LIMIT = 100;
const int X_SIZE = 5;
const int Y_SIZE = 5;

int main()
{
  int num[X_SIZE][Y_SIZE];
  int input;

  for (int y = 0; y < Y_SIZE; y++) {
    for (int x = 0; x < X_SIZE; x++) {
      cout << "Enter for (" << y << ", " << x << "): ";

      cin >> input;
      if (input > NUM_LIMIT) {
        cout << "Please input a number less than 100.\n";
        x--;
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

  cout << "Your newly created table:\n";
  for (int y = 0; y < Y_SIZE; y++) {
    for (int x = 0; x < X_SIZE; x++) {
      cout << "\t" << num[x][y];
    }
    cout << "\n";
  }
  
  return 0;
}