#include <iostream>

// another way to use "using" directive
using std::cout, std::cin, std::endl;

int main()
{
  double* pt_numbers;
  int pt_Sum, limit;
  double pt_Ave;

  cout << "How many numbers to enter?: ";
  cin >> limit;
  pt_numbers = new double[limit];

  for (int i = 0; i < limit; i++) {
    cout << "Enter number " << i + 1 << ": ";
    cin >> pt_numbers[i];

    if (pt_numbers[i] > 100) {
      cout
        << "Please enter less than 100. Going back to number "
        << i--  // postfix decrement here, for demonstration
        << "." << endl;
    } else {
      pt_Sum += pt_numbers[i];
    }
  };

  pt_Ave = pt_Sum / limit;
  cout << "The average of the " << limit << " numbers is " << pt_Ave << "\n";

  for (int i = 0; i < limit; i++) {
    cout << "Number " << i + 1 << " address is: " << &pt_numbers[i] << "\n";
  }

  cout << "Average address is: " << &pt_Ave << "\n";
  return 0;
};