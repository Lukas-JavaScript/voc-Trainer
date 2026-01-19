#include <iostream>
#include <string>
#include "exit_program.hpp"

using namespace std;

bool exit_program(bool exit) {
    cout << "Do you want to continue? (y/n)(default:y): ";
    string continue_choice;
    cin.ignore();
    getline(cin, continue_choice);
    
    if (continue_choice == "n" || continue_choice == "N") {
        exit = true;
        cout << "Exiting the program. Goodbye!\n";
    } 
    else if (continue_choice == "y" || continue_choice == "Y" || continue_choice == "") {
        exit = false;
    }
    else {
        cout << "Invalid choice. Continuing...\n";
        exit = false;
    }
    return exit;
}