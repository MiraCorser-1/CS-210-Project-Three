#ifndef GROCERYRECORDS_H
#define GROCERYRECORDS_H

#include <string>
#include <map>

class GroceryRecords {
public:
	GroceryRecords();//default constructor
	void CreateRecords();//Takes input file and builds the map with the frequency of each unique word(Called in constructor)
	void BackupRecords();//Creates a backup file with the data created from the records(Called in constructor)
	int SearchRecords(string searchTerm);//search map for user inputed word
	void PrintRecords();//Prints all unique items with there frequency
	void PrintHistogram();//Prints records but formats it in a histogram



private:
	map <string, int> frequencyRecords;//string for the item name and the int for the frequency
	string inputFileName;//file name for the input file
	string outputFileName;//file name for outputFile

};



#endif