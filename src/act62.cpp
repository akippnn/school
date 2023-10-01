#include <iostream>
#include <vector>
#include <ncurses.h>
#include <thread>
#include <ctime>
#include <algorithm>
#include <string>

void animateInsertionSort(int y, int x, int sleep, std::vector<std::string>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        std::string key = arr[i];
        int j = i - 1;

        // Display the array elements with underline for items being compared
        for (int k = 0; k < n; k++) {
            if (k == j || k == j + 1) {
                attron(A_UNDERLINE);
            }
            move(y + k, x);
            clrtoeol();
            printw("%s", arr[k].c_str()); // Display multichars
            attroff(A_UNDERLINE);
        }

        refresh();

        while (j >= 0 && arr[j] > key) {
            for (int k = 0; k < n; k++) {
                if (k == j || k == j + 1) {
                    attron(A_UNDERLINE);
                }
                move(y + k, x);
                clrtoeol();
                printw("%s", arr[k].c_str()); // Display multichars
                attroff(A_UNDERLINE);
            }
            refresh();
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
            std::swap(arr[j + 1], arr[j]);
            j--;
        }
    }
    for (int k = 0; k < n; k++) {
        move(3, k * 5);
        clrtoeol();
        printw("%s ", arr[k].c_str());
        attroff(A_UNDERLINE);
    }
}

int main() {
    // Initialize Ncurses
    initscr();
    curs_set(FALSE);

    mvprintw(0, 0, "%s", "Insertion sort visualization using ncurses.");
    mvprintw(1, 0, "%s", "Animates the insertion sort process by underlining the multichar string being compared, and swapping them based on their order.");
    std::vector<std::string> multichars;
    for (int i = 0; i < 5; i++) {
        mvprintw(3 + i, 0, "%s %d: ", "Enter the name of your classmate", i + 1);
        refresh();
        char input[100]; // Assuming the input won't exceed 100 characters
        getstr(input);
        multichars.push_back(input);
    }

    // Sort the multichars using insertion sort and animate it
    move(3, 0);
    clrtoeol();
    printw("Sorting multichars (slowed down to 250ms):");
    animateInsertionSort(4, 0, 250, multichars);
    refresh();
    move(3, 0);
    clrtoeol();
    printw("Sorted multichars:");
    for (int i = 0; i < 5; i++) {
        mvprintw(4 + i, 0, "%s", multichars[i].c_str());
    } // Display again just in case

    getch();
    endwin();
    return 0;
}
