// header file containing the function EditQuestion() that is called when the user chooses 3. Edit question from the Home Menu

#ifndef _EditQuestion_
#define _EditQuestion_

#include <fstream>
#include <string.h>

#include "FileFunctions.h";



void EditQuestion()
{

	int questionCode;
	char answer; // that is fot the user to input if he wants to edit 
	int lastExistingQuestionCode = FileLinesCount("answers.txt");   // "answers.txt" contains number of lines equal to the last existing question code
	cout << "Input the Question code of the question you want to edit: ";
	cin >> questionCode;
	while (questionCode > lastExistingQuestionCode || questionCode < 1) {
		cout << "Inccorect! A question with that code was not found." << endl;
		cout << "Try again: ";
		cin >> questionCode;
	}

	ifstream myFile;
	string myFileName = FindFileContainingString(to_string(questionCode));   //finding the file containg the question we want to edit 
	myFile.open(myFileName);
	vector<int>line = FindLinesEqualToString(myFileName, to_string(questionCode));  // there will be only one element in that vector 

	cout << "We found the question you are looking for!" << endl;
	cout << endl;
	// ouputing the question who will be edited with the answers
	for (int i = 2; i < 7; i++) {
		cout << GetLineFromFile(myFileName, line[0] + i) << endl;
	}
	cout << endl;

	string newQuestion = " ", newA = " ", newB = " ", newC = " ", newD = " ";

	cout << "Do you want to edit the question's content? y/n: ";  // "question's content" means the question itself without the answers to it
	cin >> answer;  // y/n
	if (answer == 'y') {
		cout << "Input the edited question below: " << endl;
		cin.ignore();
		getline(cin, newQuestion);
	}

	cout << "Do you want to editoption A? y/n: ";
	cin >> answer;  // y/n
	if (answer == 'y') {
		cout << "Input the edited option A below in fromat: A. ___: " << endl;
		cin.ignore();
		getline(cin, newA); cout << newA << " " << "A" << endl;
	}

	cout << "Do you want to option B? y/n: ";
	cin >> answer;  // y/n
	if (answer == 'y') {
		cout << "Input the edited option B below in format: B. ___: " << endl;
		cin.ignore();
		getline(cin, newB);
	}

	cout << "Do you want to edit option C? y/n: ";
	cin >> answer;  // y/n
	if (answer == 'y') {
		cout << "Input the edited option C below in format: C. ___: " << endl;
		cin.ignore();
		getline(cin, newC);
	}

	cout << "Do you want to edit option D? y/n: ";
	cin >> answer;  // y/n
	if (answer == 'y') {
		cout << "Input the edited option D below in format: D. ___ " << endl;
		cin.ignore();
		getline(cin, newD);
	}

	string tempFileName = "temp.txt";   // creating a temporary file for the editing file algorithm
	ofstream tempFile(tempFileName);

	int myFileLines = FileLinesCount(myFileName);
	vector<int> lines = FindLinesEqualToString(myFileName, GetLineFromFile(myFileName, line[0] + 2));  // lines[0] is the line we will change

	for (int i = 1; i <= myFileLines; i++) {
		if (i != lines[0]) {

			tempFile << GetLineFromFile(myFileName, i) << endl;
		}
		else {
			if (newQuestion != " ") tempFile << newQuestion << endl; else tempFile << GetLineFromFile(myFileName, i) << endl;
			if (newA != " ") {
				tempFile << newA << endl;
			}
			else tempFile << GetLineFromFile(myFileName, i + 1) << endl;
			if (newB != " ") {
				tempFile << newB << endl;
			}
			else tempFile << GetLineFromFile(myFileName, i + 2) << endl;
			if (newC != " ") {
				tempFile << newC << endl;
			}
			else tempFile << GetLineFromFile(myFileName, i + 3) << endl;
			if (newD != " ") {
				tempFile << newD << endl;
			}
			else tempFile << GetLineFromFile(myFileName, i + 4) << endl;
			i = i + 4;
		}
	}


	myFile.close();
	tempFile.close();

	//char* fileName is used as a pointer to the name of the file containing the edited question.
	char* fileName = new char[myFileName.size() + 1];
	std::copy(myFileName.begin(), myFileName.end(), fileName);
	fileName[myFileName.size()] = '\0';

	const char* newName = fileName;
	const char* oldName = "temp.txt";
	remove(newName);
	rename(oldName, newName);


	myFile.close();
	cout << "Question edited successfully!" << endl;
	system("pause");
	system("cls");
}
#endif