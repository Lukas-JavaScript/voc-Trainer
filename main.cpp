#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>  
#include "components/start/start.hpp"
#include "components/used_choice/used_choice.hpp"
#include "components/add.hpp" 
#include "components/start_test.hpp"

using namespace std;    

int main() {
	bool exit = false;
	string choice;
	vector<string> voc_german;
	vector<string> voc_english;
	ifstream german_file("./vocabulary_german.txt");
	ifstream english_file("./vocabulary_english.txt");
    if (!german_file.is_open() || !english_file.is_open()) {
        cerr << "Error: Could not open vocabulary files.\n";
        return 1;
    }
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
