#include <curses.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>
#include <string>

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

std::vector<int> colorPairs;

void initializeColorPairs() {
	start_color();
	for (int i = 1; i <= 6; ++i) {
		init_pair(i, i, COLOR_BLACK);
		colorPairs.push_back(COLOR_PAIR(i));
	}
}

int calculateAge(const Date& dob) {
    std::time_t now = std::time(nullptr);
    std::tm currentDate;
    std::tm* currentTm = std::localtime(&now);
    if (currentTm) {
        currentDate = *currentTm;
    } else {
        // Handle error if std::localtime fails
        return -1; // Return a sentinel value or handle it accordingly
    }

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

	// Get ready to encounter lazy code :')
	//
	WINDOW *win = newwin(8, 50, 5, 10);
	box(win, 0, 0);
	refresh();
	wrefresh(win);

	attron(A_BOLD);
	wbkgd(win, COLOR_PAIR(1));
	mvwprintw(win, 0, 2, " Enter Student Information: ");
	attroff(A_BOLD);

	mvwprintw(win, 2, 2, "Name: ");
	wrefresh(win);

	char name[50];
	wgetnstr(win, name, sizeof(name));

	wbkgd(win, COLOR_PAIR(2));
	mvwprintw(win, 3, 2, "Address: ");
	wrefresh(win);

	char address[100];
	wgetnstr(win, address, sizeof(address));
	
	wbkgd(win, COLOR_PAIR(3));
	mvwprintw(win, 4, 2, "Date of Birth (dd/mm/yyyy): ");
	wrefresh(win);

	Date dob;
	mvwscanw(win, 4, 30, "%d/%d/%d", &dob.day, &dob.month, &dob.year);

	int age = calculateAge(dob);

	wbkgd(win, COLOR_PAIR(4));
	mvwprintw(win, 5, 2, "Program/Course: ");
	wrefresh(win);

	char program[50];
	wgetnstr(win, program, sizeof(program));

	wbkgd(win, COLOR_PAIR(5));

	// Animated transition illusion with window resize + text move
	for (int i = 1; i < 6; i++) {
		wresize(win, (i*3)-1, 50);
		wclear(win);
		box(win, 0, 0);
		mvwprintw(win, 0, 2, " Student Information ");
		mvwprintw(win, 2, i-1, "Name: %s", name);
		mvwprintw(win, 4, i-1, "Address: %s", address);
		mvwprintw(win, 6, i-1, "Date of Birth: %02d/%02d/%04d", dob.day, dob.month, dob.year);
		mvwprintw(win, 8, i-1, "Program/Course: %s", program);
		mvwprintw(win, 10,i-1, "Age: %d", age);
		wrefresh(win);
		std::this_thread::sleep_for(std::chrono::milliseconds(8*i));
	}
	mvwprintw(win, 12, 3, "Press any key to exit...");

	int colorIndex = 0;
	int ch;
	nodelay(stdscr, 1);
	while (ch != '\n') {
		ch = getch();
		colorIndex = (colorIndex + 1) % colorPairs.size();
		wbkgd(win, colorPairs[colorIndex]);
		wrefresh(win);
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}

	getch();

	// Make sure to use endwin()
	delwin(win);
	return 0;
}
