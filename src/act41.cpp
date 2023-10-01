#include <iostream>
#include <ncurses.h>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

struct Date {
    int day, month, year;
};

struct Student {
    char name[50];
    char address[100];
    Date dob;
    char program[50];
    int age;
};

vector<int> colorPairs;

void initializeColorPairs() {
    start_color();
    for (int i = 1; i <= 6; ++i) {
        init_pair(i, i, COLOR_BLACK);
        colorPairs.push_back(COLOR_PAIR(i));
    }
}

int calculateAge(const Date& dob) {
    time_t now = time(0);
    tm currentDate;
    localtime_r(&now, &currentDate);

    int age = currentDate.tm_year + 1900 - dob.year;
    if (currentDate.tm_mon < dob.month || (currentDate.tm_mon == dob.month && currentDate.tm_mday < dob.day)) {
        age--;
    }

    return age;
}

int main() {
    initscr();
    keypad(stdscr, TRUE);
    initializeColorPairs();

    WINDOW *win = newwin(14, 50, 5, 10);
    wbkgd(win, COLOR_PAIR(1));
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    attron(A_BOLD);
    mvwprintw(win, 1, 1, "Enter Student Information:");
    attroff(A_BOLD);

    mvwprintw(win, 2, 1, "Name: ");
    wrefresh(win);

    char name[50];
    wgetnstr(win, name, sizeof(name));
    wbkgd(win, COLOR_PAIR(2));

    mvwprintw(win, 3, 1, "Address: ");
    wrefresh(win);

    char address[100];
    wgetnstr(win, address, sizeof(address));
    wbkgd(win, COLOR_PAIR(3));

    mvwprintw(win, 4, 1, "Date of Birth (dd/mm/yyyy): ");
    wrefresh(win);

    Date dob;
    mvwscanw(win, 4, 30, "%d/%d/%d", &dob.day, &dob.month, &dob.year);

    int age = calculateAge(dob);

    mvwprintw(win, 5, 1, "Program/Course: ");
    wrefresh(win);

    char program[50];
    attron(A_UNDERLINE);
    wgetnstr(win, program, sizeof(program));
    attroff(A_UNDERLINE);
    wbkgd(win, COLOR_PAIR(4));

    attron(A_UNDERLINE);
    mvwprintw(win, 1, 1, "Here is your Student Information:");
    attroff(A_UNDERLINE);
    mvwprintw(win, 3, 1, "Name: %s", name);
    mvwprintw(win, 4, 1, "Address: %s", address);
    mvwprintw(win, 5, 1, "Date of Birth: %02d/%02d/%04d", dob.day, dob.month, dob.year);
    mvwprintw(win, 6, 1, "Program/Course: %s", program);
    mvwprintw(win, 7, 1, "Age: %d", age);
    mvwprintw(win, 12, 1, "Press any key to exit...");
    wrefresh(win);

    int colorIndex = 0;

    while (true) {
        int ch = getch();
        if (ch == '\n') {
            colorIndex = (colorIndex + 1) % colorPairs.size();
            wbkgd(win, colorPairs[colorIndex]);
            wclear(win);
            wrefresh(win);
        } else {
            break;
        }
    }

    wrefresh(win);
    getch();

    delwin(win);
    endwin();
    refresh();

    system("reset");

    return 0;
}
