#include <ncurses.h>

const int HOW_MANY_PEOPLE = 10;
const int LEGAL_AGE = 18;

int main()
{
  int input[HOW_MANY_PEOPLE];

  initscr();
  mvprintw(0, 0, "Enter the age of %i people:", HOW_MANY_PEOPLE);
  for (int i = 0; i < HOW_MANY_PEOPLE; i++) {
    mvprintw(i + 1, 2, "%d. ", i + 1);
    refresh();
    scanw("%d", &input[i]);
  }

  mvprintw(0, 0, "Given your input, the following are:");
  for (int i = 0; i < HOW_MANY_PEOPLE; i++) {
    if (input[i] >= LEGAL_AGE)
      mvprintw(i + 1, 10, "- of legal age");
    else
      mvprintw(i + 1, 10, "- under %i", LEGAL_AGE);
  }

  mvprintw(5 + HOW_MANY_PEOPLE, 0, "Press any key to close...");
  refresh();
  getch();
  endwin();
  return 0;
};