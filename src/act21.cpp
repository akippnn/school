#include <iostream>

using std::cout;
using std::cin;

int main() {
  int num[5][5];
  int input;
  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 5; x++) {
      while(true) {
        cout << "Enter for (" << y << ", " << x << "): ";
        cin >> input;
        if (input > 100) {
          cout << "Please input a number less than 100.\n";
        } else {
          num[x][y] = input;
          break;
        }
      }
    }
  }

  cout << "Your newly created table:\n";
  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 5; x++) {
      cout << "\t" << num[x][y];
    }
    cout << "\n";
  }
}