/**
*
* Solution to course project #1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Tsvetelina Chakarova
* @idnumber 62553
* @compiler VC
*
* .cpp  file with definitions for the functions in FileFunctions.h
*
*/

#include <fstream>
#include <cstring>
#include <vector>

#include "FileFunctions.h"
using namespace std;

int FileLinesCount(const string& fileName) {
	int numLines = 0;
	ifstream in(fileName);
	string unused;
	while (getline(in, unused)) {
		++numLines;
	}
	return numLines;
}

string GetLineFromFile(const string& fileName, const int& certainLine) {
	ifstream myFile;

	myFile.open(fileName, ios::in);

	string line;
	int countLines = 1;
	while (getline(myFile, line)) {
		if (countLines == certainLine) {
			return line;
		}
		countLines++;
	}

	myFile.close();
}

//the lines from a specific file that are equal to a specific string are saved in a vector
vector<int> FindLinesEqualToString(const string& fileName, const string& searchedString) {
	vector<int> foundLines;
	ifstream myFile;
	myFile.open(fileName, ios::in);
	string line;
	int countLines = 1;
	while (getline(myFile, line)) {
		if (line == searchedString) {
			foundLines.push_back(countLines);
		}
		countLines++;
	}
	myFile.close();

	return foundLines;
}

string FindFileContainingString(const string& searched) {
	ifstream myFile;
	string myFileName;
	int i;
	for (i = 1; i < 11; i++) {
		myFileName = "level" + to_string(i) + ".txt";
		myFile.open(myFileName, ios::in);

		string line;

		while (getline(myFile, line)) {
			if (line == searched) {
				return ("level" + to_string(i) + ".txt");
			}
		}
		myFile.close();
	}
}