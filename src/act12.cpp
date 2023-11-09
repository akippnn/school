#include <curses.h>

int main()
{
  initscr();
  curs_set(0);

  int input[10];

  mvprintw(0, 0, "Enter the age of 10 people:");
  for (int i = 0; i < 10; i++) {
    mvprintw(i+1, 2, "%d%s", i+1, ". ");
    refresh();
    scanw("%d", &input[i]);
  }

  mvprintw(0, 0, "Given your input, the following are:");
  for (int i = 0; i < 10; i++) {
    if (input[i] >= 18)
      mvprintw(i+1, 10, "18+");
    else
      mvprintw(i+1, 10, "under 18");
  }
  refresh();

  return 0;
};