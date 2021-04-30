/*
* @author Tsvetelina Chakarova
* @compiler VC
* .h file containing the lifelines output
*
*/

#ifndef _LifelinesOutput_
#define _LifelinesOutput_

void UsedLifelines(const string& lifelineChoice, bool& LL1, bool& LL2, bool& LL3);
void Lifeline1(const string& fileName, const string& line, const int& numberQuestion, const int& rand);
void Lifeline2(const string& fileName, const string& line, const int& numberQuestion, const int& rand);
void Lifeline3(const string& fileName, const string& line, const int& numberQuestion, const int& rand);
void OutputLifelines(const string& fileName, const int& numberQuestion, const int& rand);


#endif
