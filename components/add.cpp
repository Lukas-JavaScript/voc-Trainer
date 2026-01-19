#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include "add.hpp"
#include "exit_program/exit_program.hpp"

using namespace std;

void add(vector<string>& voc_german, vector<string>& voc_english, bool& exit) {
    cout << "You chose to add a new word.\n";
    
    while(!exit) {
        string german_word;
        string english_word;
        cout << "Which word would you like to add? (german): ";
        cin.ignore();
        getline(cin, german_word);
        
        cout << "Enter the English translation: ";
        getline(cin, english_word);
        
        voc_german.push_back(german_word);
        voc_english.push_back(english_word);
        
        cout << "You added the word: " << german_word << " - " << english_word << "\n";
        cout << "Number of edited words: " << voc_german.size() << "\n";
        
        ofstream german_file("./vocabulary_german.txt");
        ofstream english_file("./vocabulary_english.txt");
        ostream_iterator<string> german_out_it(german_file, "\n");
        copy(voc_german.begin(), voc_german.end(), german_out_it);
        ostream_iterator<string> english_out_it(english_file, "\n");
        copy(voc_english.begin(), voc_english.end(), english_out_it);
        
        exit = exit_program(exit);
    }
}
