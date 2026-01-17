#include <iostream>
#include <string>
#include "used_choice.hpp"

using namespace std;

string used_choice() {
	string choice;
	cin >> choice;
	cout << "You entered: " + choice + "\n";
	return choice;
}
