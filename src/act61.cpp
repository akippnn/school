#include <iostream>
#include <vector>
#include <ncurses.h>
#include <thread>
#include <ctime>
#include <algorithm>
#include <functional> // for std::function

void printSort(int y, int x, const std::vector<int> &arr, std::function<bool(int)> shouldUnderline)
{
  int n = arr.size();
  for (int k = 0; k < n; k++) {
    if (shouldUnderline(k)) {
      attron(A_UNDERLINE);
    }
    move(y, x + k * 5);
    clrtoeol();
    printw("%3d ", arr[k]);
    attroff(A_UNDERLINE);
    refresh();
  }
}

void animateInsertionSort(int y, int x, int sleepms, std::vector<int> &arr, std::function<void(int, int)> callback)
{
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    auto shouldUnderline = [&i, &j](int k) {
      return k == i || k == j;
    };

    while (j >= 0 && arr[j] > key) {
      std::swap(arr[j + 1], arr[j]);
      callback(arr[j + 1], arr[j]); // Call the callback with swapped values
      printSort(y, x, arr, shouldUnderline);
      std::this_thread::sleep_for(std::chrono::milliseconds(sleepms));
      refresh();
      j--;
      i--; // Decrement i to keep track of the key's position
    }
  }
  printSort(y, x, arr, [](int, int) { return false; }); // Clear underlines at the end
}

int main()
{
  initscr();
  WINDOW *win = newwin(3, 31, 10, 10);

  // Callback function to print the current state
  std::function<void(int, int)> printCallback = [&win](int x, int y) {
    box(win, 0, 0);
    mvwprintw(win, 1, 1, "Comparing elements: %d and %d", x, y);
    wrefresh(win);
  };

  std::vector<int> numbers;
  srand(time(nullptr));
  for (int i = 0; i < 20; i++) {
    numbers.push_back(rand() % 100 + 1);
  }
  mvprintw(0, 0, "20 random numbers from 1 to 100:");
  for (int i = 0; i < numbers.size(); i++) {
    mvprintw(1, i * 5, "%3d ", numbers[i]);
  }

  mvprintw(2, 0, "Ascending Order Sort:");
  animateInsertionSort(3, 0, 100, numbers, printCallback);

  delwin(win);
  mvprintw(4, 0, "Descending Order Sort (reversed):");
  std::reverse(numbers.begin(), numbers.end());
  for (int i = 0; i < numbers.size(); i++) {
    mvprintw(5, i * 5, "%3d ", numbers[i]);
  }

  getch();
  endwin();
  return 0;
}
