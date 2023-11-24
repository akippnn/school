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

void print_row(int y, bool selectedRow, const int* selectedItem)
{
  mvprintw(y + 2, 0, "%i.", y + 1);
  if (selectedRow) {
    attron(A_STANDOUT);
  }
  for (int x = 1; x <= COLUMNS; x++) {
    if (&NUM[y][x - 1] == selectedItem) {
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
  printw("Numbers in the table:");
  for (int y = 0; y < ROWS; y++) {
    print_row(y, false, nullptr);
  };
  refresh();

  mvprintw(10, 0, "Row [ Type number... ]");
  refresh();
  for (;;) {
    input = getch();
    if (row) {
      print_row(row - 1, false, nullptr); 
    };
    row = int(input) - 48;
    move(10, 0);
    clrtoeol();
    printw("Row [%i]", row);
    print_row(row - 1, true, nullptr);

    mvprintw(10, 10, "Column [ Type number... ]");
    refresh();
    input = getch();
    column = int(input) - 48;
    move(10, 10);
    clrtoeol();
    printw("Column [%i]", column);
    print_row(row - 1, false, &NUM[row - 1][column - 1]);

    mvprintw(10, 23, "Selected [%i]", NUM[row - 1][column - 1]);
    refresh();
  }
};
