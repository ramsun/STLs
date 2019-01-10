/*
Ramamurthy Sundar
student id: 00667077
netid: rsundar
CPS 271 - Machine Problem 1
9/7/2018

class.cpp

This is the declaration of the FrequencyTable class.  It makes use of a
map in the backend, which maps a unique string key to a count of the
word, an int.

The public functions recieve and output information related to the frequency table
from a text file stream.
*/

#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <map>
#include <locale>
#include <sstream>
#include <algorithm>

class FrequencyTable {
private:
	std::map<std::string, int> F;

public:
	void stream_infile(std::ifstream &infile);
	void print_to_text(std::ofstream &outfile);
};

