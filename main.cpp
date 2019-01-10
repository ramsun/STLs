/*
Ramamurthy Sundar
student id: 00667077
netid: rsundar
CPS 271 - Machine Problem 7
Fall 2018

main.cpp

This is the driver for Machine Problem 7.  It uses C++ 11 STL libraries in
order to make a frequency table generator and palindrome tester algorithm.
*/

#include "class.h"

using namespace std;

//HELPER FUNCTION(S)
//returns ture if the input word is a palindrome
//function only makes use of C++ STL functions
bool PalindromeTester(const string main) {
	//local string object for comparison
	string compare;
	
	//only copy input string to compare object if the chars are not punctuation
	copy_if(main.begin(), main.end(), back_inserter(compare), [](char i) {return !(ispunct(i)); });
	
	//convert all charachters to lower case
	transform(compare.begin(), compare.end(), compare.begin(), ::tolower);

	//remove spaces from the compare string
	compare.erase(remove(compare.begin(), compare.end(), ' '), compare.end());

	//reverse the compare string
	string reverse_compare = compare;
	reverse(reverse_compare.begin(), reverse_compare.end());

	//check whether the input is a palindrome
	return compare == reverse_compare;
}

//MAIN
int main() {
	//Exception handling
	try {
		//Part 1: Frequency Table
		//initialze variables
		FrequencyTable part1; string filename;
		ofstream outfile;
		outfile.open("output.txt");
		cout << "Part 1: Frequency Table" << endl;
		outfile << "Part 1: Frequency Table" << "\n";
		cout << "Please enter a filename: ";
		cin >> filename;

		//stream infile to FrequencyTable class
		ifstream infile;
		infile.open(filename.c_str());
		if (!infile.is_open()) {
			throw "the file for the frequncy table could not be opened";
		}
		part1.stream_infile(infile);

		//stream map in FrequencyTable class to an output file
		part1.print_to_text(outfile);

		//Part 2: Palindrome Tester
		//stream to terminal and output file
		ifstream infile2;
		cout << endl;
		outfile << "\n";
		cout << "Part 2: Palindrome Tester" << endl;
		outfile << "Part 2: Palindrome Tester" << "\n";
		cout << "Please enter a filename: ";
		cin >> filename;

		//error checking
		infile2.open(filename.c_str());
		if (!infile2.is_open()) {
			throw "the file for the the palindrome tester could not be opened";
		}

		//pass entire infile into a string stream
		stringstream strStream;
		strStream << infile2.rdbuf();//read the file
		string str = strStream.str();//str holds the content of the file as a string

		if (PalindromeTester(str)) {
			outfile << "The input string "<< str << " is a palindrome." << "\n";
		}
		else {
			outfile << "The input string is " << str << " NOT a palindrome." << "\n";
		}

	}
	catch (const char* e) {
		cout << "There was an error: " << e << endl;
	}

	return 0;
}