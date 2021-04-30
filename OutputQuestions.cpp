/*
* @author Tsvetelina Chakarova
* @compiler VC
* .cpp  file with definitions for the functions in OutputQuestions.h
*
*/

#include <iostream>
#include <ctime>
#include <cstring>

#include "FileFunctions.h"
#include "Lifelines.h"
#include "LifelinesOutput.h"
#include "OutputQuestions.h"
#include "Menus.h"

void OutputQuestion(const string& level, const string& category, int& check, int numberQuestion, int& prev, int& rem) {
	string prizeScale[15] = { "$500", "$1,000", "$2,000", "$3,000", "$5,000", "$7,500", "$10,000", "$20,000",
							 "$30,000", "$50,000", "$75,000", "$150,000", "$250,000", "$500,000", "$1 MILLION" };   //on question number i from the game the player wins prizeScale[i-1] if his answer is correct
	system("cls");
	check = 1;
	string answerChoice;
	string fileName = "level" + level + ".txt";
	vector<int> a = FindLinesEqualToString(fileName, category);
	a.erase(remove(a.begin(), a.end(), rem), a.end());
	srand(time(0));

	int randomNumber = rand() % a.size();
	int rand = a[randomNumber];
	prev = rand;

	cout << "========================================================================" << endl;
	cout << numberQuestion << ".";
	for (int i = rand + 1; i < rand + 6; i++) {
		cout << GetLineFromFile(fileName, i) << endl;
	}
	cout << endl;
	cout << "Question code: ";
	cout << GetLineFromFile(fileName, rand - 1) << endl;

	cout << "========================================================================" << endl;

	OutputLifelines(fileName, numberQuestion, rand);

	cout << "Enter your choice here: ";
	getline(cin, answerChoice);
	while (InputAnswerCheck(answerChoice) == false) {
		cout << "Incorrect input! Input A, B, C or D: "; getline(cin, answerChoice);
	}

	string questionID = GetLineFromFile(fileName, rand - 1);
	rem = prev;
	string rightAnswer = GetLineFromFile("answers.txt", stoi(questionID));
	system("cls");

	if (answerChoice == rightAnswer) {
		cout << "========================================================================" << endl;
		cout << "                          Correct answer!" << endl;
		cout << "                    Your cuurent prize is:" << prizeScale[numberQuestion - 1] << endl;
		cout << "========================================================================" << endl;
		system("pause");
	}
	else {
		system("cls");
		cout << "========================================================================" << endl;
		cout << "                     Your answer was wrong." << endl;
		cout << "                    The correct answer was:";
		cout << endl;

		//outputing the write answer
		if (rightAnswer == "A") {
			cout << "                          ";
			cout << GetLineFromFile(fileName, rand + 2) << endl; //If the answer is A -> output the line 2 lines below the  line with the category
		}

		else if (rightAnswer == "B") {
			cout << "                          ";
			cout << GetLineFromFile(fileName, rand + 3) << endl;
		}

		else if (rightAnswer == "C") {
			cout << "                          ";
			cout << GetLineFromFile(fileName, rand + 4) << endl;
		}
		else {
			cout << "                          ";
			cout << GetLineFromFile(fileName, rand + 5) << endl;
		}

		cout << endl;
		cout << "                        END OF GAME!" << endl;
		cout << endl;

		if (numberQuestion == 1) {
			cout << "                        You won: $0" << endl;
		}
		else {
			cout << "                       You won: ";
			cout << prizeScale[numberQuestion - 2] << endl; //the player ends the game with the money earned from the previous question
		}
		cout << "========================================================================" << endl;
		system("pause");
		check = 0;
	}
}

void OutputAllQuestions(string category) {
	int check = 1;
	int questionLevels[15] = { 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10 };
	int i = 0; int prev; int rem;
	do {
		OutputQuestion(to_string(questionLevels[i]), category, check, i + 1, prev, rem);
		i++;
		if (i == 15) {
			break;
		}
	} while (check != 0);
	system("cls");
	if (i == 15) {
		cout << "========================================================================" << endl;
		cout << endl;
		cout << "                       Congratulattions!" << endl;
		cout << "                      You won $1 MILLION!" << endl;
		cout << endl;
		cout << "========================================================================" << endl;
		system("pause");
		system("cls");
	}
}

void OutputAllQueastionsForAllCategories() {
	int check = 1;
	string categories[3] = { "Bulgarian history", "Bulgarian sport" ,"Bulgarian geography" };
	int questionLevels[15] = { 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10 };
	int i = 0;
	int prev;
	int rem;

	do {
		srand(time(0));                 // helps to generate a different number each time rand() is executed
		int randomNumber = rand() % 3;  // generates a random number between 0 and 2
		OutputQuestion(to_string(questionLevels[i]), categories[randomNumber], check, i + 1, prev, rem);
		i++;
		if (i == 15) {
			break;
		}
	} while (check != 0);
	system("cls");
	if (i == 15) {
		cout << "========================================================================" << endl;
		cout << endl;
		cout << "                       Congratulattions!" << endl;
		cout << "                      You won $1 MILLION!" << endl;;
		cout << endl;
		cout << "========================================================================" << endl;
		system("pause");
		system("cls");
	}
}
