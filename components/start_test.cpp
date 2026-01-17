#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>  
#include "exit_program.hpp"

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