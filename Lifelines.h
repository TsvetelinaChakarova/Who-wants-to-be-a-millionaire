// header file containing the functions connected to the lifelines

#ifndef _Lifelines_
#define _Lifelines_

#include <string.h>
#include <vector>
#include <ctime>

#include "FileFunctions.h"

void LifeLine50_50(string fileName, string rightAnswer, int numberQuestion, int random) {

	vector<string> options = { "A", "B", "C", "D" };
	options.erase(remove(options.begin(), options.end(), rightAnswer), options.end());  //removing the correct answer from the vector with options, because we do not want to choose it randomly for elimination
	srand(time(0));

	//randomly choosing two of the remaining wrong options to eliminate 
	int removeIndex1 = rand() % options.size();
	string remove1 = options[removeIndex1];
	options.erase(remove(options.begin(), options.end(), remove1), options.end());
	int removeIndex2 = rand() % options.size();
	string remove2 = options[removeIndex2];

	//index1 and index2 are used to know how many lines below the line with the questiopn is the options we need to eliminate
	int index1, index2;
	if (remove1 == "A") index1 = 1;
	else if (remove1 == "B") index1 = 2;
	else if (remove1 == "C") index1 = 3;
	else index1 = 4;

	if (remove2 == "A") index2 = 1;
	else if (remove2 == "B") index2 = 2;
	else if (remove2 == "C") index2 = 3;
	else index2 = 4;

	system("cls");
	string line;
	cout << "========================================================================" << endl;
	cout << numberQuestion << ".";
	for (int i = random + 1; i < random + 6; i++)
	{
		if (GetLineFromFile(fileName, i) == GetLineFromFile(fileName, random + 1 + index1)) { cout << endl; continue; }
		if (GetLineFromFile(fileName, i) == GetLineFromFile(fileName, random + 1 + index2)) { cout << endl; continue; }
		cout << GetLineFromFile(fileName, i) << endl;
	}
	cout << endl;
	cout << "Question code: "; cout << GetLineFromFile(fileName, random - 1) << endl;

	cout << "========================================================================" << endl;
}



void LifelinePhoneAFriendSpecific(string fileName, string rightAnswer, int numberQuestion, int random, int percantage) {
	bool TrueFalse;
	srand(time(0));
	TrueFalse = (rand() % 100) < percantage;  //generating a random number between  0 and 99. If the number is < percantage TrueFalse = 1. Otherwise it equals 0.

	// if (TrueFalse == 1) the friend gives a correct answer. if (TrueFalse == 0) the friend gives a wrong answer
	cout << "I think the right answer is ";
	if (TrueFalse == 1) {
		cout << rightAnswer << endl;
	}
	else {
		vector<string> options = { "A", "B", "C", "D" };
		options.erase(remove(options.begin(), options.end(), rightAnswer), options.end());  //removing the correct answer from the vector with options, because we do not want to choose it randomly for elimination
		srand(time(0));
		int wrongOutputIndex = rand() % options.size();
		cout << options[wrongOutputIndex] << endl;
	}
}
void LifelinePhoneAFriendOverall(string fileName, string rightAnswer, int numberQuestion, int random) {
	if (fileName == "level1.txt" || fileName == "level2.txt" || fileName == "level3.txt") {
		LifelinePhoneAFriendSpecific(fileName, rightAnswer, numberQuestion, random, 70);  // for level of difficulty between 1 and 3 the friend has 70% chance to give right answer
	}
	else if (fileName == "level4.txt" || fileName == "level5.txt" || fileName == "level6.txt") {
		LifelinePhoneAFriendSpecific(fileName, rightAnswer, numberQuestion, random, 40);  // for level of difficulty between 4 and 6 the friend 40% chance for right answer
	}
	else {
		LifelinePhoneAFriendSpecific(fileName, rightAnswer, numberQuestion, random, 20); // for level of difficulty between 7 and 10 the friend 20% chance for right answer
	}
}

#endif