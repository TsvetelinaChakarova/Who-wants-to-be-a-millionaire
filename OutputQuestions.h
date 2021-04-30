/*
* @author Tsvetelina Chakarova
* @compiler VC
* .h file containing the functions related to outputing questions for option 1. New game from the home menu
*
*/

#ifndef _OutputQuestions
#define _OutputQuestions_

void OutputQuestion(const string& level, const string& category, int& check, int numberQuestion, int& prev, int& rem);
void OutputAllQuestions(string category);
void OutputAllQueastionsForAllCategories();

#endif
