/*
Ramamurthy Sundar
student id: 00667077
netid: rsundar
CPS 271 - Machine Problem 7
Fall 2018

class.cpp

This is the implementation of class.h.

Functions are commented bellow.
*/
#include "class.h"

//streams data from an input file stream to the FrequencyTable class
void FrequencyTable::stream_infile(std::ifstream &infile) {
	using namespace std;
	string word;
	locale loc; //from C++ 11 STL locale (#include <locale>)
	while (infile >> word)
	{
		//remove potential punction in word
		for(unsigned int i = 0; i<word.size(); i++) {
			if (ispunct(word[i])) {
				word.erase(i);
			}
			word[i] = tolower(word[i], loc);	
		}

		//push the word into a map, or increase the count
		++F[word];

	}
}

//stream the frequency table into the 
void FrequencyTable::print_to_text(std::ofstream &outfile) {
	outfile << "Frequency Table: " << "\n";
	for (auto elem : F) {
		outfile << "Word: " << elem.first << "\tCount: " << elem.second << "\n";
	}
}
