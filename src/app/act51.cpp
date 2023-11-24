#include <iostream>
#include <curses.h>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>

template <typename T>
void animateSelectionSort(std::vector<int> &arr, T sleep)
{
  // Animate selection sort and update the line
  int n = arr.size();
  int i, j;

  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      // Print the array elements with underline for items being compared
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) {
          attron(A_UNDERLINE);
        }
        mvprintw(2, k * 5, "%2d ", arr[k]); // Spacing & formatting
        attroff(A_UNDERLINE);
      }

      refresh();
      std::this_thread::sleep_for(sleep);

      if (arr[j] < arr[i]) {
        mvprintw(3, 0, "%s", "Swapped");
        std::swap(arr[i], arr[j]); // Swap items (makes a better visualization + cleaner)
      }
      else {
        mvprintw(3, 0, "%s", "       ");
      }
    }
  }
}

int main()
{
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);

  int lowerBound = 0;
  int upperBound = 100;
  int randomNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;
  int maxTries = 14;
  auto sleep = std::chrono::milliseconds(200);

  int guess;
  std::vector<int> guesses;

  // Menu
  noecho();
  mvprintw(0, 0, "%s", "Welcome to the Divide and Conquer Game!");
  mvprintw(2, 4, "%s%i%s", "Easy Mode (Max Tries:", maxTries, ")");
  mvprintw(3, 4, "%s", "EZ Mode (Max Tries: 7)");

  int selectedMode = 1;
  while (true) {
    mvprintw(selectedMode + 1, 0, "%s", "->");
    int ch = getch();
    mvprintw(selectedMode + 1, 0, "%s", "  ");
    if (ch == KEY_DOWN || ch == 's' || ch == 'S' || ch == 'j') {
      selectedMode = 2;
    }
    else if (ch == KEY_UP || ch == 'w' || ch == 'W' || ch == 'k') {
      selectedMode = 1;
    }
    else if (ch == 10) { // Enter key
      if (selectedMode == 1)
        maxTries = 14;
      else
        maxTries = 7;
      break;
    }
  }

  // Game Start
  echo();
  clear();
  mvprintw(0, 0, "%s", "Welcome to the Divide and Conquer Game!");
  mvprintw(1, 0, "%s", "Try to guess the random number between 0 and 100.");
  mvprintw(2, 0, "%s %d %s", "You have", maxTries, "tries");

  for (int attempt = 1; attempt <= maxTries; attempt++) {
    // Game Logic
    printw("\nEnter your guess: ");
    refresh();
    scanw("%d", &guess);
    guesses.push_back(guess);

    clear();
    printw("Previous guesses: ");
    for (int i = 0; i < guesses.size(); i++)
      printw("%d ", guesses[i]);

    if (guess < randomNumber)
      printw("\nTOO LOW! Try a higher number.");
    else if (guess > randomNumber)
      printw("\nTOO HIGH! Try a lower number.");
    else {
      clear();
      mvprintw(0, 0, "%s: %d", "Congratulations! You guessed the correct number", randomNumber);
      break;
    }

    printw("\nTries remaining: %d", maxTries - attempt);

    if (attempt == maxTries) {
      clear();
      mvprintw(0, 0, "%s: %d", "Sorry, you've run out of tries. The correct number was", randomNumber);
    }

    refresh();
  }

  // Game Over
  int n = guesses.size();
  mvprintw(1, 0, "%s %i %s", "Sorting algorithm... (slowed down to", sleep, "per execution)");
  animateSelectionSort(guesses, sleep);
  move(1, 0);
  clrtoeol();
  printw("%s", "Press any key to exit the program.");

  getch();
  return 0;
}
