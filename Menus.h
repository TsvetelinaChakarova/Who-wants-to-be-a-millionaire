/*
* @author Tsvetelina Chakarova
* @compiler VC
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
