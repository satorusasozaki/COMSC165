#include <iostream>
#include <sstream>
#include <string>
#include <random>
using namespace std;

int const COMMENT_RANDOM_MIN = 0;
int const COMMENT_RANDOM_MAX = 3;
int const NUMBER_RANDOM_MIN = 0;

int generateRandomNumber (int min, int max) {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

// #58
string chooseComment() {
    int random_number = generateRandomNumber(COMMENT_RANDOM_MIN,COMMENT_RANDOM_MAX);
    string comment;
    switch (random_number) {
        case 0: comment = "Very good!\n";
            break;
        case 1: comment = "Excellent!\n";
            break;
        case 2: comment = "Nice work!\n";
            break;
        case 3: comment = "Keep up the good work!\n";
            break;
        default: comment = "Error occured in displayComment function\n";
    }
    return comment;
}


// #57
void askQuestion (int &correct_counter,int &incorrect_counter,int maxDigit) {
    for (int i=0; i < 10; i++) {
        int r1 = generateRandomNumber(NUMBER_RANDOM_MIN,maxDigit);
        int r2 = generateRandomNumber(NUMBER_RANDOM_MIN,maxDigit);
        int answer = r1 * r2;
        cout << "How much is " << r1 << " times " << r2 << "?\n"
             << "Answer: ";
        string transfer;
        int userAnswer;
        getline(cin,transfer);
        stringstream(transfer) >> userAnswer;
        
        while (userAnswer != answer) {
            cout << "No, Please try again: ";
            getline(cin,transfer);
            stringstream(transfer) >> userAnswer;
            incorrect_counter++;
        }
        correct_counter++;
        cout << chooseComment();
    }
}

// #59
void calcResult (int cc, int ic) {
    int total_count = cc + ic;
    float percentage = static_cast<float>(cc) / static_cast<float>(total_count) * 100;
    if (percentage < 75) {
        cout << "Please ask your teacher for extra help.\n";
    } else {
        cout << "You are ready to go to the next level.\n";
    }
}


// #60
int decideMaxDigit() {
    cout << "Enter a difficulty level: ";
    string transfer;
    int level;
    getline(cin,transfer);
    stringstream(transfer) >> level;
    
    int maxDigit = 10;
    for (int i=0; i < level-1; i++) {
        maxDigit *= 10;
    }
    maxDigit -= 1;
    return maxDigit;
}

int main() {
    int max_digit = decideMaxDigit();
    int correct_counter = 0;
    int incorrect_counter = 0;
    askQuestion(correct_counter,incorrect_counter,max_digit);
    calcResult(correct_counter,incorrect_counter);
    
    return 0;
    
}