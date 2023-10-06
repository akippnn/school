#include <iostream>
#include <vector>
#include <curses.h>
#include <thread>
#include <ctime>

template <typename T>
void animateBubbleSort(std::vector<std::string>& arr, T sleep) {
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
            std::this_thread::sleep_for(sleep);


            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    initscr();

    auto sleep = std::chrono::milliseconds(200);
    int num = 10;

    std::vector<std::string> multichars;

    mvprintw(0, 0, "%s", "Bubble sort visualization using curses.");
    mvprintw(1, 0, "%s", "Animates the bubble sort process by underlining the multichar string being compared, and swapping them based on their order.");
    for (int i = 0; i < num; i++) {
        mvprintw(3 + i, 0, "%s %s %d: ", "Enter the name of your classmate", i + 1); // Input text
        refresh();
        char input[100]; // Assuming the input won't exceed 100 characters
        getstr(input);
        multichars.push_back(input);
    }

    mvprintw(9, 0, "Sorting multichars (slowed down to 200ms per execution):");
    animateBubbleSort(multichars, sleep);
    refresh();
    mvprintw(9, 0, "Sorted multichars:");
    for (int i = 0; i < num; i++) {
        mvprintw(10 + i, 0, "%s", multichars[i].c_str());
    } // Display again just in case

    getch();
    return 0;
}
