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
    };
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
        }
}

namespace LeapYearChecker {
    // Leap Year Checker
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
    return LeapYearChecker::main();
}
