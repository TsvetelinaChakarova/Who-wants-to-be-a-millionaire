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
* .h file containing the home screen menu and the category choice menu
*
*/

#ifndef _Menus_
#define _Menus_

#include <fstream>
#include <string>
#include <vector>

using namespace std;


bool InputMenuCheck(int input) {
	if (input != 1 && input != 2 && input != 3 && input != 4) {
		return 0; // in case of incorrect input
	}
	else return 1; // in case of correct input
}

bool InputAnswerCheck(string input) {
	if (input != "A" && input != "B" && input != "C" && input != "D") {
		return 0; // in case of incorrect input
	}
	else return 1; // in case of correct input
}

void HomeScreen(int& choice) {
	cout << "===================== Who wants to be a milionaire =====================" << endl;
	cout << "=========================== Bulgaria edition ===========================" << endl;
	cout << endl;
	cout << "                           1. New Game                                  " << endl;
	cout << "                           2. Add new question                          " << endl;
	cout << "                           3. Edit question                             " << endl;
	cout << "                           4. Exit                                      " << endl;
	cout << endl;
	cout << "========================================================================" << endl;
	cout << endl;
	cout << "Enter your choice here: ";
	cin >> choice;
	if (InputMenuCheck(choice) == 1) {
		cout << endl;
	}
	else {
		while (InputMenuCheck(choice) == 0) {
			cout << "Incorrect input! Input 1, 2, 3 or 4: "; cin >> choice;
		}
	}
}


void ChooseCategory(int& choice) {
	cout << "========================================================================" << endl;
	cout << endl;
	cout << "                       Choose a category:                               " << endl;
	cout << "                       1. Bulgarian history                             " << endl;
	cout << "                       2. Bulgarian geography                           " << endl;
	cout << "                       3. Bulgarian sport                               " << endl;
	cout << "                       4. All categories                                " << endl;
	cout << endl;
	cout << "========================================================================" << endl;
	cout << "Enter your choice here: ";
	cin >> choice;
	if (InputMenuCheck(choice) == 1) {
		cout << endl;
	}
	else {
		while (InputMenuCheck(choice) == 0) {
			cout << "Incorrect input! Input 1, 2, 3 or 4: "; cin >> choice;
		}
	}
}

#endif
