#include <iostream>
using namespace std;

#include "GroceryRecords.h"

void RecordMenu() {
	GroceryRecords frequencyGroceryRecords;
	string menuOption;
	string searchTerm;

	menuOption = "";
	while (menuOption != "4") {//loops until 4 is entered
		//menu options
		cout << "\nType the number to select an option:\n" << "1: Search the frequency of an item\n";
		cout << "2: Print list of all frequencies of items\n" << "3: Print histogram of all frequencies of items\n";
		cout << "4: Exit program" << endl;

		//user input
		cin >> menuOption;
		cin.ignore(1000, '\n');

		//check and call correct function
		if (menuOption == "1") {//search
			cout << "\n\nType in the word you wish to search for...\n";
			cin >> searchTerm;
			cin.ignore(1000, '\n');
			cout << endl << searchTerm << ": " << frequencyGroceryRecords.SearchRecords(searchTerm) << endl;
		}
		else if (menuOption == "2") {//print list
			frequencyGroceryRecords.PrintRecords();
		}
		else if (menuOption == "3") {//print histogram
			frequencyGroceryRecords.PrintHistogram();
		}
		else if (menuOption == "4") {//exit
			return;
		}
		else {//wrong input
			cout << "\nPlease type in only a valid number\n\n";
		}

		

	}
}

int main(){
	
	RecordMenu();

	cout << "\n\nThank you :)\nGoodbye" << endl;

	
	return 0;
}