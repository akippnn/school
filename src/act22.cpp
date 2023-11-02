#include <iostream>
#include <ncurses.h>

using std::cout;
using std::cin;

int main() {
  int num[5][5] = {
    10,  12,  14, 16, 18,
    20,  55,  75, 65, 85,
    95, 200, 150, 65, 34,
    90,  91,  87, 60, 63,
    23,  19,  11, 34, 54
  };
  int row, column;
  char input;
  cout << "These are the numbers in the table:\n\t1.\t2.\t3.\t4.\t5.\tcolumn\n";
  for (int y = 0; y < 5; y++) {
    cout << y + 1 << ".";
    for (int x = 0; x < 5; x++) {
      cout << "\t" << num[x][y];
    };
    cout << "\n";
  };
  cout << "row\n";

  cout << "Row []";
  input = getch();
  row = int(input) - 48;
  cout << "\b" << row << "] ";

  cout << "Column []";
  input = getch();
  column = int(input) - 48;
  cout << "\b" << column << "] ";
  
  cout << "\nThe value in the field you selected (" << row << ", " << column << ") is: " << num[column - 1][row - 1];

  return 0;
};
