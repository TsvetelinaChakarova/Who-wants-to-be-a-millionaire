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

//#include <iostream>
#ifndef _Menus_
#define _Menus_

#include <string>
using namespace std;

bool InputMenuCheck(const string& input);
bool InputAnswerCheck(const string& input);
void HomeScreen(string& choice);
void ChooseCategory(string& choice);


#endif