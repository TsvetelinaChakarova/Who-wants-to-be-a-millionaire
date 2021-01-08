// header file containing the functions connected to the direct work with txt files

#ifndef _FileFunctions_
#define _FileFunctions_

#include <fstream>
#include <string.h>
#include <vector>

using namespace std; 

int FileLinesCount(string fileName) {
	int numLines = 0;
	ifstream in(fileName);
	string unused;
	while (getline(in, unused))
		++numLines;

	return numLines;
}

string GetLineFromFile(string fileName, int certainLine) {
	ifstream myFile;

	myFile.open(fileName, std::fstream::in);

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
vector<int> FindLinesEqualToString(string fileName, string searchedString) {

	vector<int> foundLines;
	ifstream myFile;
	myFile.open(fileName, std::fstream::in);
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


string FindFileContainingString(string searched) {
	ifstream myFile;
	string myFileName;
	bool isThere;
	int i;
	for (i = 1; i < 11; i++) {
		myFileName = "level" + to_string(i) + ".txt";
		myFile.open(myFileName, std::fstream::in);

		string line;

		while (getline(myFile, line)) {
			if (line == searched) {

				return ("level" + to_string(i) + ".txt");
			}
		}
		myFile.close();
	}

}
#endif