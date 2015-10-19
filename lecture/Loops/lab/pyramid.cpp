/****
Problem: Loops lab 1 (Display pyramid)
Description:
Write a program that prompts the user to enter an integer from 1 to 9 and displays a pyramid,
as shown in the following sample run:

Name: Satoru Sasozaki ( with Kristina )
ID: 1516331
Date: September 16
Status: Complete

****/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
	string transfer;
	int number_of_lines;
	int numbers_in_one_line;

	cout << "Enter the number of lines: ";

	// Get number of lines

	getline(cin, transfer);

	stringstream(transfer) >> number_of_lines;



	numbers_in_one_line = 2 * number_of_lines - 1;

	cout << endl;


	for (int j = 1; j <= number_of_lines; j++) {

		string buffer_left = "";

		string buffer_right = " ";

		// for left half
		for (int k = j; k>0; k--) {

			// combine the number with space needed
            stringstream convert;
            string result;
			convert << k;
			convert >> result;

			buffer_left += result;

			// if 1, space is not needed, because buffer right has a space when it is 2
			buffer_left += k == 1 ? "" : " ";

		}

		// for right half
		for (int l = 2; l <= j; l++) {
            stringstream convert;
            string result;
            convert << l;
            result = convert.str();
			buffer_right += result + " ";

		}

		// set the frame
		int numbers_with_space = numbers_in_one_line * 2 + 1;
		int half_numbers = (numbers_with_space - 1) / 2;

		cout << setw(half_numbers + 1) << right << buffer_left << setw(half_numbers) << left << buffer_right << endl;

	}

	return 0;
}


