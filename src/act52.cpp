#include <iostream>
#include <vector>
#include <ncurses.h>
#include <thread>
#include <ctime>

using namespace std;

// Function to animate bubble sort for multichars and display the process
void animateBubbleSort(vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            // Display the array elements with underline for items being compared
            for (int k = 0; k < n; k++) {
                if (k == j || k == j + 1) {
                    attron(A_UNDERLINE);
                }
		move(10 + k, 0);
		clrtoeol();
                mvprintw(10 + k, 0, "%s", arr[k].c_str()); // Display multichars
                attroff(A_UNDERLINE);
                mvprintw(10 + k, arr[k].size() * 2, " "); // Clear extra space
            }

            refresh();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));


            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // Initialize Ncurses
    initscr();
    curs_set(FALSE);

    // Input five multichars
    mvprintw(0, 0, "%s", "Bubble sort visualization using ncurses.");
    mvprintw(1, 0, "%s", "Animates the bubble sort process by underlining the multichar string being compared, and swapping them based on their order.");
    vector<string> multichars;
    for (int i = 0; i < 5; i++) {
        mvprintw(3 + i, 0, "%s %d: ", "Enter the name of your classmate", i + 1);
        refresh();
        char input[100]; // Assuming the input won't exceed 100 characters
        getstr(input);
        multichars.push_back(input);
    }

    // Sort the multichars using bubble sort and animate it
    mvprintw(9, 0, "Sorting multichars (slowed down to 200ms per execution):");
    animateBubbleSort(multichars);
    refresh();
    mvprintw(9, 0, "Sorted multichars:");
    for (int i = 0; i < 5; i++) {
        mvprintw(10 + i, 0, "%s", multichars[i].c_str());
    } // Display again just in case

    getch();
    endwin();
    return 0;
}
