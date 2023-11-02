#include <iostream>

using std::cout, std::endl, std::string;
string yellow = "\033[30;103m";
string reset = "\033[0m";

int arraysize(auto array[]) {
  return *(&array + 1) - array;
  /*
    How this works is that when referencing array without accessing its' elements, we can get the pointer of the 0th element of the array and the pointer of the whole array when using the & operator. Then we can leverage the pointer subtraction (the '-' operator is used) to find the distance between the two elements.
    *(&rates) - *(&rates - 1)
    sizeof(array)/sizeof(array[0])
  */
}

int main() {
  string rates[] = {"6.25", "6.50", "6.8", "7.2", "7.35", "7.5", "7.65", "7.8", "8.2", "8.4", "8.6", "8.8", "9.0"};
  int elements = *(&rates + 1) - rates;
  cout << "Displaying items stored in the following memory addresses..." << endl;
  cout << "Starting with the address of rates[0] ";
  for (string *dispPt = rates; dispPt < *(&rates + 1); dispPt++) {
    cout << dispPt << endl;
    cout << yellow << "Value of " << dispPt << " is " << *dispPt << reset << endl;
    if (dispPt + 1 < *(&rates + 1)) {
      cout << "The increment of " << dispPt << " is ";
    };
  };
  return 0;
};