/***
Problem: Random Number Guessing Game

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


***/

#include <iostream>
#include <string>
#include <sstream>
#include <random>

using namespace std;

const int RANDOM_MAX = 100;
const int RANDOM_MIN = 1;

const string TOO_HIGH = "Too high, try again.";
const string TOO_LOW = "Too low, try again.";
const string CORRECT = "Whooray! Your guess is correct! The number of your guesses is: ";

int main() {
    string transfer;
    int guessed_number;
    int guesses = 0;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(RANDOM_MIN, RANDOM_MAX);
    int random_number = distribution(generator);

    do {
        guesses++;
        cout << "Guess the number: ";
        getline(cin, transfer);
        stringstream(transfer) >> guessed_number;

        if (guessed_number > random_number) {
            cout << TOO_HIGH << endl;
        } else if (guessed_number < random_number) {
            cout << TOO_LOW << endl;
        }
    } while (guessed_number != random_number);

    cout << CORRECT << guesses << endl;

    return 0;
}
