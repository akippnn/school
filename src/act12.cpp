#include <curses.h>

const int MAX_INPUT = 10;
const int AGE_LEGAL = 18;

int main()
{
  int input[MAX_INPUT];

  initscr();
  mvprintw(0, 0, "Enter the age of %i people:", MAX_INPUT);
  for (int i = 0; i < MAX_INPUT; i++) {
    mvprintw(i + 1, 2, "%d. ", i + 1);
    refresh();
    scanw("%d", &input[i]);
  }

  mvprintw(0, 0, "Given your input, the following are:");
  for (int i = 0; i < MAX_INPUT; i++) {
    if (input[i] >= AGE_LEGAL)
      mvprintw(i + 1, 10, "- of legal age");
    else
      mvprintw(i + 1, 10, "- under %i", AGE_LEGAL);
  }
  refresh();

  return 0;
};