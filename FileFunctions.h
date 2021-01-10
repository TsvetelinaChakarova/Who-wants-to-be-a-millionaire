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
* .h file containing the functions connected to the direct work with txt files
*
*/

#ifndef _FileFunctions_
#define _FileFunctions_

#include <string>
#include <vector>
using namespace std;

int FileLinesCount(const string& fileName);
string GetLineFromFile(const string & fileName, const int& certainLine);
vector<int> FindLinesEqualToString(const string& fileName, const string& searchedString);
string FindFileContainingString(const string& searched);

#endif