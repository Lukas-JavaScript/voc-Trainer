#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	string choice;
	vector<string> voc_german;
	vector<string> voc_english;
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
		voc_german.push_back(german);
		voc_english.push_back(english);
		cout << "You added the word: " + german + " - " + english + "\n";

	} else if (choice == "2") {
		cout << "You chose to start the test.\n";
		cout << "Test is starting...\n";
	} else {
		cout << "Invalid choice. Please restart the program and enter 1 or 2.\n";
	}
	return 0;
}
