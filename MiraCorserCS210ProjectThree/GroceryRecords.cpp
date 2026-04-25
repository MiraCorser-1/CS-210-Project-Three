#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

#include "GroceryRecords.h"
//default constructor
GroceryRecords::GroceryRecords() {
	inputFileName = "CS210_Project_Three_Input_File.txt";
	outputFileName = "frequency.dat";
	CreateRecords();
	BackupRecords();

	
}
//Takes input file and builds the map with the frequency of each unique word(Called in constructor)
void GroceryRecords::CreateRecords() {
	//cout << "FIXME: Not implemented, GroceryRecords::CreateRecords";
	ifstream inFS;//filestream
	string inputData;//holds the current word
	int frequencyData;//holds current frequency


	inFS.open(inputFileName);//open file
	if (!inFS.is_open()) {//make sure the file opens
		cout << "No file named " << inputFileName << endl;
		return;
	}

	inFS >> inputData;
	//until end of file
	while (!inFS.fail()) {
		if (frequencyRecords.count(inputData) == 1) {//if the key exists increment value by one
			frequencyData = frequencyRecords.at(inputData);
			frequencyRecords.at(inputData) = frequencyData + 1;
		}
		else {
			frequencyRecords.emplace(inputData, 1);
		}

		inFS >> inputData;
	}
	inFS.close();//close file after use
	
	return;
}
//Creates a backup file with the data created from the records(Called in constructor)
void GroceryRecords::BackupRecords() {
	//cout << "FIXME: Not implemented, GroceryRecords::BackupRecords";
	ofstream outFS;
	
	outFS.open(outputFileName);//open output file

	if (!outFS.is_open()) {//check if file actually is open
		cout << "Couldn't open file " << outputFileName << endl;
		return;
	}
	
	//writes data to file
	for (map<string, int>::iterator it = frequencyRecords.begin(); it != frequencyRecords.end(); ++it) {
		outFS << it->first << ": " << it->second << endl;
	}

	//close file
	outFS.close();
	return;
}
//search map for user inputed word
int GroceryRecords::SearchRecords(string searchTerm) {
	//cout << "FIXME: Not implemented, GroceryRecords::SearchRecords";
	if (frequencyRecords.count(searchTerm) == 1) {//if search term is found return the frequency value
		return frequencyRecords.at(searchTerm);
	}
	return 0;
}
//Prints all unique items with there frequency
void GroceryRecords::PrintRecords() {
	//cout << "FIXME: Not implemented, GroceryRecords::PrintRecords";
	for (map<string, int>::iterator it = frequencyRecords.begin(); it != frequencyRecords.end(); ++it) {//iterate through the map
		cout << it->first << ": " << it->second << endl;//prints key, value
	}
	return;
}
//Prints records but formats it in a histogram
void GroceryRecords::PrintHistogram() {
	//cout << "FIXME: Not implemented, GroceryRecords::PrintHistogram";
	int i;

	for (map<string, int>::iterator it = frequencyRecords.begin(); it != frequencyRecords.end(); ++it) {//iterate through the map
		cout << it->first << ": ";//prints key
		for (i = 0; i < it->second; ++i) {
			cout << "*";
		}
		cout << endl;
	}
	return;

}