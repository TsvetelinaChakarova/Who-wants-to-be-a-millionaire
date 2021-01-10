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
* .h file containing the functions related to outputing questions for option 1. New game from the home menu
*
*/

#ifndef _OutputQuestions
#define _OutputQuestions_

void OutputQuestion(const string& level, const string& category, int& check, int numberQuestion, int& prev, int& rem);
void OutputAllQuestions(string category);
void OutputAllQueastionsForAllCategories();

#endif