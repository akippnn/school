#include <coroutine>
#include <ncurses.h>
#include <vector>
#include <functional>
#include "generator.h"

const int HOW_MANY_NUMBERS = 20;
const int MIN_VALUE = 1;
const int MAX_VALUE = 100;
const int CHECK_DIVISIBILITY[] = {3, 5, 7};

Generator<int> check_if_divisible(std::vector<int> &arr, int n)
{
  co_yield 1;
}

template <typename T>
void print_sort(int y, int x, const std::vector<T> &arr, std::function<bool(int)> should_underline)
{
  int n = arr.size();

  move(y, x);
  clrtoeol();

  for (int k = 0; k < n; k++) {
    if (should_underline(k)) {
      attron(A_UNDERLINE);
    }
    printw("%\t", arr[k]);
    attroff(A_UNDERLINE);
  }

  refresh();
}

T animated_partition(int y, int x, const std::vector<T> &arr, int start, int end)
{
  int pivot = arr[end];
  int count = 0;
  int i, j, pivot_index;

  auto underline = [&i, &j](int k) {
    return k == i || k == j;
  }

  for (int i = start; i < end; i++) {
    if (arr[i] <= pivot) {
      count++;
    }
  }
  pivot_index = start + count;
  swap(arr[pivot_index], arr[end]);

  i = start, j = end;
  while (i < pivot_index && j > pivot_index) {
    while (arr[i] <= pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i < pivot_index && j > pivot_index) {
      print_int_sort(y, x, arr, underline);
      swap(arr[i++], arr[j--]);
    }
  }

  print_int_sort(y, x, arr, underline);
  return pivot_index;
}

void animated_quick_sort(int y, int x, std::vector<int> &arr, int start, int end)
{
  if (start >= end) {
    return; // base case
  }
  int p = partition(arr, start, end);
  quick_sort(arr, start, p - 1);
  quick_sort(arr, p + 1, end);
}

int main()
{
  initscr();
  srand(time(nullptr));

  std::vector<int> numbers;

  for (int i = 0; i < HOW_MANY_NUMBERS; i++) {
    numbers.push_back(rand() % MAX_VALUE + MIN_VALUE);
  }

  mvprintw(0, 0, "%i random numbers from %i to %i:", HOW_MANY_NUMBERS, MIN_VALUE, MAX_VALUE);
  for (int number : numbers) {
    mvwprintw(1, 5 + (i * 5), "%3d", number);
  }

}