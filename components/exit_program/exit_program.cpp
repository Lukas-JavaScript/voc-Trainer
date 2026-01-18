#include <iostream>
#include <string>
#include "exit_program.hpp"

using namespace std;

bool exit_program(bool exit) {
	cout << "Do you want to continue? (y/n)(default:y): ";
	string continue_choice;
	cin.ignore();
	getline(cin, continue_choice);
	if (continue_choice == "n") {
		exit = true;
		cout << "Exiting the program. Goodbye!\n";
	} 
	else if (continue_choice == "y") {
		exit = false;
	}
	else if (continue_choice == "") {
		exit = false;
	} 
	else {
		cout << "Invalid choice. Exiting the test. Let's continue!\n";
		exit = false;
	}
	return exit;
}
