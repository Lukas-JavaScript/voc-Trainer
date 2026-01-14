#include <iostream>
#include <string>

using namespace std;

int main() {
	string choice;
	cout << "Welcome to the vocabulary learner!\n";
	cout << "This program helps you learn new words.\n";
	cout << "Let's get started!\n";
	cout << "Please enter 1 or 2\n";
	cout << "1. Add a new word\n";
	cout << "2. Start test\n";
	cout << "Your choice: ";
	cin >> choice;
	cout << "You entered: " + choice + "\n";
	if (choice == "1") {
		cout << "You chose to add a new word.\n";
		cout << "Which word would you like to add? (german): ";
		string german;
		string english;
		cin >> german;
		cout << "Enter the English translation: ";
		cin >> english;
		cout << "You added the word: " + german + " - " + english + "\n";
		// Code to add a new word would go here
	} else if (choice == "2") {
		cout << "You chose to start the test.\n";
		// Code to start the test would go here
	} else {
		cout << "Invalid choice. Please restart the program and enter 1 or 2.\n";
	}
	return 0;
}
