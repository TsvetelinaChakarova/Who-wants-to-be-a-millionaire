/*
* @author Tsvetelina Chakarova
* @compiler VC
* .cpp  file with definitions for the functions in LifelinesOutput.h
*
*/

#include <iostream>
#include <cstring>
#include <string>
#include <iostream>

#include "FileFunctions.h"
#include "Lifelines.h"
#include "LifelinesOutput.h"

bool LL1 = 1, LL2 = 1, LL3 = 1; //so that all lifelines are available at the begging

void UsedLifelines(const string& lifelineChoice, bool& LL1, bool& LL2, bool& LL3) {
	if (lifelineChoice == "1") {
		LL1 = 0;
	}
	else if (lifelineChoice == "2") {
		LL2 = 0;
	}
	else LL3 = 0;
}

//LL1 = 1 means 50/50 is not used. LL1 = 0 means 50/50 is used
//LL2 = 1 means Phone a friend is not used. LL2 = 0 means Phone a friend is used.
//LL3 = 1 means Ask the public is not used. LL3 = 0 means Ask the public is used.

void Lifeline1(const string& fileName, const string& line, const int& numberQuestion, const int& rand) {
	UsedLifelines("1", LL1, LL2, LL3);
	system("cls");
	LifeLine50_50(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);

}

void Lifeline2(const string& fileName, const string& line, const int& numberQuestion, const int& rand) {
	UsedLifelines("2", LL1, LL2, LL3);
	LifelinePhoneAFriendOverall(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
}

void Lifeline3(const string& fileName, const string& line, const int& numberQuestion, const int& rand) {
	UsedLifelines("3", LL1, LL2, LL3);
	LifelineAskThePublicOverall(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
}

void OutputLifelines(const string& fileName, const int& numberQuestion, const int& rand) {
	if (numberQuestion == 1) {
		LL1 = 1;
		LL2 = 1;
		LL3 = 1;
	}
	cout << "Do you want to use a lifeline? (y/n): ";
	string answerLifeline;

	getline(cin, answerLifeline);
	while (answerLifeline != "y" && answerLifeline != "n") {
		cout << "Invalid! Enter again: ";
		getline(cin, answerLifeline);
	}

	if (answerLifeline == "y") {

		if (LL1 == 1 && LL2 == 1 && LL3 == 1) {
			cout << "Available lifelines: 1. 50/50, 2. Phone a frined, 3. Ask the public" << endl;
			cout << "Enter your choice: ";

			string lifelineChoice;
			getline(cin, lifelineChoice);
			while (lifelineChoice != "1" && lifelineChoice != "2" && lifelineChoice != "3") {
				cout << "Invalid! Enter again: ";
				getline(cin, lifelineChoice);
			}

			if (lifelineChoice == "1") {
				Lifeline1(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
			if (lifelineChoice == "2") {
				Lifeline2(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
			if (lifelineChoice == "3") {
				Lifeline3(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
		}

		else if (LL1 == 0 && LL2 == 1 && LL3 == 1) {
			cout << "Available lifelines:  2. Phone a frined, 3. Ask the public" << endl;
			cout << "Enter your choice: ";

			string lifelineChoice;
			getline(cin, lifelineChoice);
			while (lifelineChoice != "2" && lifelineChoice != "3") {
				cout << "Invalid! Enter again: ";
				getline(cin, lifelineChoice);
			}
			if (lifelineChoice == "2") {
				Lifeline2(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
			if (lifelineChoice == "3") {
				Lifeline3(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
		}

		else if (LL1 == 1 && LL2 == 0 && LL3 == 1) {
			cout << "Available lifelines:  1. 50/50, 3. Ask the public" << endl;
			cout << "Enter your choice: ";

			string lifelineChoice;
			getline(cin, lifelineChoice);
			while (lifelineChoice != "1" && lifelineChoice != "3") {
				cout << "Invalid! Enter again: ";
				getline(cin, lifelineChoice);
			}

			if (lifelineChoice == "1") {
				Lifeline1(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}

			if (lifelineChoice == "3") {
				Lifeline3(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
		}
		else if (LL1 == 1 && LL2 == 1 && LL3 == 0) {
			cout << "Available lifelines:  1. 50/50, 2. Phone a friend" << endl;
			cout << "Enter your choice: ";

			string lifelineChoice;
			getline(cin, lifelineChoice);
			while (lifelineChoice != "1" && lifelineChoice != "2") {
				cout << "Invalid! Enter again: ";
				getline(cin, lifelineChoice);
			}

			if (lifelineChoice == "1") {
				Lifeline1(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}

			if (lifelineChoice == "2") {
				Lifeline2(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
			}
		}
		else if (LL1 == 1 && LL2 == 0 && LL3 == 0) {
			cout << "Available lifelines:  1. 50/50" << endl;
			cout << "Enter your choice: ";

			string lifelineChoice;
			getline(cin, lifelineChoice);
			while (lifelineChoice != "1") {
				cout << "Invalid! Enter again: ";
				getline(cin, lifelineChoice);
			}
			Lifeline1(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
		}

		else if (LL1 == 0 && LL2 == 1 && LL3 == 0) {
			cout << "Available lifelines:  2. Phone a friend" << endl;
			cout << "Enter your choice: ";

			string lifelineChoice;
			getline(cin, lifelineChoice);
			while (lifelineChoice != "2") {
				cout << "Invalid! Enter again: ";
				getline(cin, lifelineChoice);
			}
			Lifeline2(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
		}

		else if (LL1 == 0 && LL2 == 0 && LL3 == 1) {
			cout << "Available lifelines:  3. Ask the public" << endl;
			cout << "Enter your choice: ";

			string lifelineChoice;
			getline(cin, lifelineChoice);
			while (lifelineChoice != "3") {
				cout << "Invalid! Enter again: ";
				getline(cin, lifelineChoice);
			}
			Lifeline3(fileName, GetLineFromFile("answers.txt", stoi(GetLineFromFile(fileName, rand - 1))), numberQuestion, rand);
		}

		else if (LL1 == 0 && LL2 == 0 && LL3 == 0) {
			cout << "No available lifelines" << endl;
		}
	}
}
