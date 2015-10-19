#include <iostream>
#include <sstream>
#include <string>
#include <random>
using namespace std;

int const COMMENT_RANDOM_MIN = 0;
int const COMMENT_RANDOM_MAX = 3;
int const NUMBER_RANDOM_MIN = 0;

// #58
string chooseComment() {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(COMMENT_RANDOM_MIN, COMMENT_RANDOM_MAX);
    int random_number = distribution(generator);

    cout << "random_number: " << random_number << endl;

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
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(NUMBER_RANDOM_MIN, maxDigit);

    for (int i=0; i < 1; i++) {
        int r1 = distribution(generator);
        int r2 = distribution(generator);
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
    cout << "Percentage: " << percentage << endl;
    if (percentage < 75) {
        cout << "Please ask your teacher for extra help\n";
    } else {
        cout << "You are ready to go to the next level\n";
    }
}


// #60
int decideMaxDigit() {
    cout << "Enter a difficulty level: " << endl;
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
