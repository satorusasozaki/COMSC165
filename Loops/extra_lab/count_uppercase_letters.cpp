/*****
Problem:
Random Number Guessing Game

Description:
Write a program that generates a random number between 1...100 and asks the user to guess what the number is. If the
user's guess is higher than the random number, the program should display “Too high, try again”. If the user s guess is
lower than the random number, the program should display “Too low, try again”. The program should use a loop that
repeats until the user correctly guesses the random number.
The program will keep a count of the number of guesses that the user makes. When the user correctly guesses the
random number, the program should display the number of guesses.

Name: Satoru Sasozaki
ID: 1516331
Date: September 19
Status: Complete
*****/


#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

const string PROMPT_FIRST = "Enter a string: ";
const string PROMPT_LAST = "The number of uppercase letters is ";

int main() {
    string transfer;
    int counter = 0;

    cout << PROMPT_FIRST;
    getline(cin, transfer);

    for (int i = 0 ; i < transfer.length(); i++) {
        char c = transfer.at(i);
        if (isupper(c)) {
            counter++;
        }
    }

    cout << endl << PROMPT_LAST << counter << endl;

    return 0;
}
