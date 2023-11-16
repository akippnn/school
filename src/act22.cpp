#include <iostream>
#include <ncurses.h>

const int ROWS = 5;
const int COLUMNS = 5;
const int NUM[5][5] = {
  10,   12,   14,   16,   18,
  20,   55,   75,   65,   85,
  95,   200,  150,  65,   34,
  90,   91,   87,   60,   63,
  23,   19,   11,   34,   54
};

void printRow(int y, bool selectedRow, int* selectedItem)
{
  mvprintw(y + 2, 0, "%i.", y);
  if (selectedRow) {
    attron(A_STANDOUT);
  }
  for (int x = 1; x <= 5; x++) {
    if (&NUM[y][x] == selectedItem) {
      attron(A_STANDOUT);
      mvprintw(y + 2, 5 * x, "%i", NUM[y][x - 1]);
      attroff(A_STANDOUT);
    } else {
      mvprintw(y + 2, 5 * x, "%i", NUM[y][x - 1]);
    }
  };
  attroff(A_STANDOUT);
}

int main()
{
  int row, column;
  char input;

  initscr();
  printw("These are the numbers in the table:");
  for (int y = 0; y < 5; y++) {
    printRow(y, false, nullptr);
  };
  refresh();

  mvprintw(10, 0, "Row [ Type number... ]");
  refresh();
  input = getch();
  row = int(input) - 48;
  move(10, 0)
  clrtoeol();
  printRow(row - 1, true, nullptr);
  printw("Row [%i]", row);

  mvprintw(10, 10, "Column [ Type number... ]");
  refresh();
  input = getch();
  column = int(input) - 48;
  move(10, 10);
  clrtoeol();
  printRow(row - 1, false, &NUM[row - 1][column - 1]);
  printw("Column [%i]", column);

  mvprintw(10, 23, "Selected [%i]", NUM[row - 1][column - 1]);

  mvprintw(15, 0, "Press any key to close...");
  refresh();
  getch();
  endwin();
  return 0;
};
