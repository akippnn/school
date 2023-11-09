#include <curses.h>

const int MAX_INPUT = 10;

int main()
{
  int input[MAX_INPUT];

  initscr();
  mvprintw(0, 0, "Enter the age of %i people:", MAX_INPUT);
  for (int i = 0; i < MAX_INPUT; i++) {
    mvprintw(i+1, 2, "%d%s", i+1, ". ");
    refresh();
    scanw("%d", &input[i]);
  }

  mvprintw(0, 0, "Given your input, the following are:");
  for (int i = 0; i < MAX_INPUT; i++) {
    if (input[i] >= 18)
      mvprintw(i+1, 10, "18+");
    else
      mvprintw(i+1, 10, "under 18");
  }
  refresh();

  return 0;
};