#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	std::vector<std::string> first_name;
	std::vector<std::string> last_name;
	std::string input;
	int i = 0;
	
	cout << "Enter first name or blank. If first name is entered, enter last name (required)." << endl;
	do {
		i++;
		cout << "1. ";
		std::getline(cin, input);
		if (input != "") {
			first_name.push_back(input);
			input = "";
			while (input == "") {
				std::getline(cin, input);
			};
			last_name.push_back(input);
		};
	} while (input != "");
	
	cout << "Printing" << endl;
	for (int i = 0; i < first_name.size(); i++) {
		cout << first_name[i] << " ";
		cout << last_name[i] << endl;
	};
}
