#include <curses.h>
#include <iostream>
#include <string>

namespace Problem1 {
	// Problem No.1
	// Location : Bacolod City, Negros Occidental Philippines
	// Website  : https://www.jakerpomperada.com
	// Email    : jakerpomperada@jakerpomperada.com and jakerpomperada@gmail.com
	// Tool     : Dev C++ Version 5.11
	//
	using namespace std;

	struct add {
		int x, y;
		int addition()
		{
			return(x+y);
		};
	};

	int main() {
		add math;
		char reply;

		return 0;
	}
}

namespace YearLevelChecker {
	// Year Level Checker
	// Location : Bacolod City, Negros Occidental Philippines
	// Website  : https://www.jakerpomperada.com
	// Email    : jakerpomperada@jakerpomperada.com and jakerpomperada@gmail.com
	// Tool     : Dev C++ Version 5.11
	//
	using namespace std;

	struct check_year_level {
		int year_level;
	};

	int main()
	{
		check_year_level *ptr, a;
		ptr = &a;
		system("COLOR F0");
		cout << "\n\n";
		cout << "\tYear Level Checker Using Structure and Pointers";
		cout << "\n\n";
		cout << "\tEnter year Level:";
		cin >> (*ptr).year_level;
		cout << "\n\n";
		if ((*ptr).year_level==1) {
			// All your base are belong to us.
			cout << "\tYou are belong to Freshmen.";
		}
		if ((*ptr).year_level==2) {
			// All your base are belong to us.
			cout << "\tYou are belong to Sophomore.";
		}
		if ((*ptr).year_level==3) {
			// All your base are belong to us.
			cout << "\tYou are belong to Juniors.";
		}
		if ((*ptr).year_level==4) {
			// All your base are belong to us.
			cout << "\tYou are belong to Seniors.";
		}
		else {
			cout << "\tInvalid Option Try Again";
		}
		cout << "\n\n";
		cout << "\tEND OF PROGRAM";
		cout << "\n\n";
		system("pause");

		return 0;
	}
}

namespace LeapYearChecker {
	// Leap Year Checker
	// Modified by @akippnn
	// Location : Bacolod City, Negros Occidental Philippines
	// Website  : https://www.jakerpomperada.com
	// Email    : jakerpomperada@jakerpomperada.com and jakerpomperada@gmail.com
	// Tool     : Dev C++ Version 5.11
	//
	using namespace std;

	struct LeapYear {
		int year;

		LeapYear(int inputYear) : year(inputYear) {}

		bool isLeapYear() const {
			if (year % 4 == 0) {
				if (year % 100 == 0) {
					if (year % 400 == 0) {
						return true;
					} else {
						return false;
					}
				} else {
					return true;
				}
			} else {
				return false;
			}
		}
	};

	int main() {
		system("COLOR F0");
		cout << "\n\n";
		cout << "\tLeap Year Checker Using Structure";
		cout << "\n\n";

		int inputYear;
		cout << "\tEnter Year: ";
		cin >> inputYear;
		cout << "\n";

		LeapYear yearChecker(inputYear);

		if (yearChecker.isLeapYear()) {
			cout << "\tThe Given Year " << inputYear << " is a Leap Year." << endl;
		} else {
			cout << "\tThe Given Year " << inputYear << " is not a Leap Year." << endl;
		}

		return 0;
	}
}

int main() {
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);

	start_color();
	init_pair(2, 2, COLOR_BLACK);

	// Menu
	WINDOW *win = newwin(7, 55, 5, 10);
	wbkgd(win, COLOR_PAIR(2));
	box(win, 0, 0);
	refresh();
	mvwprintw(win, 1, 2, "%s", "Structures on C++ (see namespaces on /src)");
	mvwprintw(win, 3, 3, "%s", "Accessing Structure Members (modified)");
	mvwprintw(win, 4, 3, "%s", "Program of struct Access using Pointer to a member");
	mvwprintw(win, 5, 3, "%s", "Problem 1");
	wrefresh(win);

	int selectedMode = 0, ch;

	for (bool x=true; x!=false;) {
		box(win, 0, 0);
		mvwprintw(win, 0, 1, "%s", " Activity 4.2 ");
		mvwprintw(win, 6, 31, "%s", " Inspired by Fallout 4 ");

		mvwprintw(win, 3 + selectedMode % 3, 0, "%s", "->");
		wrefresh(win);
		ch = getch();
		mvwprintw(win, 3 + selectedMode % 3, 0, "%s", "  ");
		switch (ch) { 
			case KEY_DOWN:
			case 's':
			case 'S':
			case 'j':
				selectedMode = abs(selectedMode + 1);
				break;
			case KEY_UP:
			case 'w':
			case 'W':
			case 'k':
				selectedMode = abs(selectedMode - 1);
				break;
			case 10:
			case KEY_ENTER:
				selectedMode = selectedMode % 3;
				x = false;
				break;
		}
	}

#ifdef WINDOWS
	system("cls");
#else
	system("clear");
#endif

	if (selectedMode == 0)
		return LeapYearChecker::main();
	else if (selectedMode == 1)
		return YearLevelChecker::main();
	else if (selectedMode == 2)
		return Problem1::main();
}
