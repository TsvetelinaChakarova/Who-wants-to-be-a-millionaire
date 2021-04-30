/*
* @author Tsvetelina Chakarova
* @compiler VC
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
