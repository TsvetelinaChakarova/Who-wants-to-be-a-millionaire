/**
*
* Solution to course project #1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020 / 2021
*
*@author Tsvetelina Chakarova
* @idnumber 62553
* @compiler VC
*
*.h file containing the functions connected to the lifelines
*
*/

#ifndef _Lifelines_
#define _Lifelines_

#include <vector>

void LifeLine50_50(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random);
void LifelinePhoneAFriendSpecific(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random, const int& percantage);
void LifelinePhoneAFriendOverall(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random);
vector<int> Generate100();
void LifelineAskThePublicSpecific(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& percantage);
void LifelineAskThePublicOverall(const string& fileName, const string& rightAnswer, const int& numberQuestion, const int& random);

#endif