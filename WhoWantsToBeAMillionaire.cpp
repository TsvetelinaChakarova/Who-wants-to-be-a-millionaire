/**
*
* Solution to course project # 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Tsvetelina Chakarova
* @idnumber 62553
* @compiler VC
*
* the main .cpp file
*
*/
#include <iostream>

#include "Menus.h"
#include "OutputQuestions.h"
#include "EditQuestion.h"
#include "AddQuestion.h"

using namespace std;

int main()
{
	string choice;
	do {

		HomeScreen(choice);

		if (choice == "1") {
			system("cls");
			cout << "========================================================================" << endl;
			cout << "                          Attention!                                    " << endl;
			cout << "     Remember the question code in case you want to edit it later!      " << endl;
			cout << "========================================================================" << endl;
			system("pause");
			system("cls");
			string categoryChoice;
			string category;
			ChooseCategory(categoryChoice);
			system("cls");

			if (categoryChoice == "1") {
				OutputAllQuestions("Bulgarian history");
			}
			else if (categoryChoice == "2") {
				OutputAllQuestions("Bulgarian geography");
			}
			else if (categoryChoice == "3") {
				OutputAllQuestions("Bulgarian sport");
			}
			if (categoryChoice == "4") {
				OutputAllQueastionsForAllCategories();
			}
		}

		if (choice == "2") {
			system("cls");
			AddNewQuestion();
		}

		if (choice == "3") {
			system("cls");
			EditQuestion();
		}

	} while (choice != "4");

	return 0;
}