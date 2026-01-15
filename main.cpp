#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>  

using namespace std;    

void start() {
	cout << "Welcome to the vocabulary learner!\n"; 
	cout << "This program helps you learn new words.\n";
	cout << "Let's get started!\n";
	cout << "Please enter 1 or 2\n";
	cout << "1. Add a new word\n";
	cout << "2. Start test\n";
	cout << "Your choice: ";
}
string used_choice() {
	string choice;
	cin >> choice;
	cout << "You entered: " + choice + "\n";
	return choice;
}
void add(vector<string>& voc_german, vector<string>& voc_english) {
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
}
int main() {
	bool exit = false;
	string choice;
	vector<string> voc_german;
	vector<string> voc_english;
	ifstream german_file("./vocabulary_german.txt");
	ifstream english_file("./vocabulary_english.txt");
	string line;
	while (getline(german_file, line)) {
			voc_german.push_back(line);
		}
		while (getline(english_file, line)) {
			voc_english.push_back(line);
		}
	start();
	choice = used_choice();
	if (choice == "1") {
		add(voc_german, voc_english);

	} else if (choice == "2") {
		
		while (!exit) {
			cout << "You chose to start the test.\n";
			cout << "Test is starting...\n";
			int random = rand() % voc_german.size();
			string selected_element = voc_german[random];
			cout << "What is the English translation of the German word: " + selected_element + "?\n";
			string user_answer;
			cin >> user_answer;
			if (user_answer == voc_english[random]) {
				cout << "Correct! Well done. All right!\n";
			} else {
				cout << "Incorrect. The correct translation is: " + voc_english[random] + "\n";
			}
			cout << "Do you want to continue? (y/n): ";
			string continue_choice;
			cin >> continue_choice;
			if (continue_choice == "n") {
				exit = true;
				cout << "Exiting the test. Goodbye!\n";
			} else if (continue_choice == "y") {
				cout << "Continuing the test...\n";
			} else {
				cout << "Invalid choice. Exiting the test. Goodbye!\n";
				exit = true;
			}
		}

	} else {
		cout << "Invalid choice. Please restart the program and enter 1 or 2.\n";
	}
	return 0;
}
