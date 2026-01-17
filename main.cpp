#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>  
#include "components/start/start.hpp"
#include "components/used_choice.hpp"
#include "components/exit_program.hpp"
#include "components/add.hpp"

using namespace std;    

void start_test(const vector<string>& voc_german, const vector<string>& voc_english, bool& exit) {
	cout << "You chose to start the test.\n";
	cout << "Test is starting...\n";
	while (!exit) {
		int random = rand() % voc_german.size();
		string selected_element = voc_german[random];
		cout << "What is the English translation of the German word: " + selected_element + "?\n";
		cout << "Your answer: ";
		string user_answer;
		cin >> user_answer;
		if (user_answer == voc_english[random]) {
			cout << "Correct! Well done. All right!\n";
		} else {
			cout << "Incorrect. The correct translation is: " + voc_english[random] + "\n";
		}
		exit = exit_program(exit);
	}
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
		add(voc_german, voc_english, exit);

	} else if (choice == "2") {
		start_test(voc_german, voc_english, exit);

	} else {
		cout << "Invalid choice. Please restart the program and enter 1 or 2.\n";
	}
	return 0;
}
