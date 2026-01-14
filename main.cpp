#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>  

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
		string german_word;
		string english_word;
		cin >> german_word;
		cout << "Enter the English translation: ";
		cin >> english_word;
		voc_german.push_back(german_word);
		voc_english.push_back(english_word);
		cout << "You added the word: " + german_word + " - " + english_word + "\n";
		cout << "Number of edited words: " << to_string(voc_german.size()) << "\n";
		ofstream german_file("./vocabulary_german.txt");
		ofstream english_file("./vocabulary_english.txt");
		ostream_iterator<string> german_out_it(german_file, "\n");
		copy(voc_german.begin(), voc_german.end(), german_out_it);
		ostream_iterator<string> english_out_it(english_file, "\n");
		copy(voc_english.begin(), voc_english.end(), english_out_it);

	} else if (choice == "2") {
		cout << "You chose to start the test.\n";
		cout << "Test is starting...\n";
	} else {
		cout << "Invalid choice. Please restart the program and enter 1 or 2.\n";
	}
	return 0;
}
