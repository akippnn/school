#include <iostream>
#include <ncurses.h>

int main()
{
  int num[5][5] = {
    10,   12,   14,   16,   18,
    20,   55,   75,   65,   85,
    95,   200,  150,  65,   34,
    90,   91,   87,   60,   63,
    23,   19,   11,   34,   54
  };
  int row, column;
  char input;

  initscr();
  printw("These are the numbers in the table:");
  for (int y = 0; y < 5; y++) {
    mvprintw(y+2, 0, "%i", y);
    for (int x = 0; x < 5; x++) {
      mvprintw(y+2, 5*x, "%i", num[x][y]);
    };
  };
  refresh();

  move(10, 0);
  printw("Row [ Type number... ]");
  refresh();
  input = getch();
  row = int(input) - 48;
  clrtoeol();
  printw("Row [%i]", row);

  move(11, 0);
  printw("Column [ Type number... ]");
  refresh();
  input = getch();
  column = int(input) - 48;
  clrtoeol();
  printw("Column [%i]", column);

  mvprintw(10, 23, "Selected [%i]", num[column - 1][row - 1]);

  mvprintw(15, 0, "Press any key to close...");
  refresh();
  getch();
  endwin();
  return 0;
};
