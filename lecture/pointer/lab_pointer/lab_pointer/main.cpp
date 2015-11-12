/*
 Problem: pointer #12 (textbook pp 338)
 Name: Satoru Sasozaki
 ID: 1516331
 Date: 11/2/2015
 */

#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;
const int RANDOM_MAX = 10;
const int RANDOM_MIN = 1;

int generateRandomNum() {
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(RANDOM_MIN, RANDOM_MAX);
    int random_number = distribution(generator);
    return random_number;
}

void moveTortoise (int *pos,int rnum) {
    // swich
    if (1 <= rnum && rnum <= 5) {
        // fast plod
        (*pos) += 3;
    } else if (6 <= rnum && rnum <= 7) {
        // slip
        (*pos) -= 6;
    } else {
        // slow plod
        (*pos) += 1;
    }
    
    if ( (*pos) < 0) {
        (*pos) = 0;
    }
}

void moveHare (int *pos, int rnum) {
    if (1 <= rnum && rnum <= 2) {
        // sleep
    } else if (3 <= rnum && rnum <= 4) {
        // big hop
        (*pos) += 9;
    } else if (rnum == 5) {
        // big slip
        (*pos) -= 12;
    } else if (6 <= rnum && rnum <= 8) {
        // small hop
        (*pos) += 1;
    } else {
        // small slip
        (*pos) -= 2;
    }
    
    if ( (*pos) < 0) {
        (*pos) = 0;
    }
}



int main() {
    
    int tortoisePos = 0;
    int harePos = 0;
    // *tortoiseP = &tortoisePos;
    
    
    //    int hare = 1;
    //    int *hare_pos = &hare;
    
    //   vector<string> line(70,"-");
    //   cout << line.at(3) << endl;
    
    while (tortoisePos < 70 && harePos < 70) {
        
        moveTortoise(&tortoisePos,generateRandomNum());
        moveHare(&harePos,generateRandomNum());
        
        //        cout << "Tortoise Pos: " << tortoisePos << endl;
        //        cout << "Hare Pos:     " << harePos << endl;
        for (int i=0; i < 70; i++) {
            if (i == tortoisePos && i == harePos) {
                cout << "OUCH!";
            } else if (i == tortoisePos) {
                cout << "T";
            } else if (i == harePos) {
                cout << "H";
            } else {
                cout << "-";
            }
        }
        cout << '\r';
        cout.flush();
        this_thread::sleep_for (chrono::seconds(1));
    }
    
    if (tortoisePos >= 60 && harePos >= 60) {
        cout << "It's a tie" << endl;
    } else if (tortoisePos >= 60) {
        cout << "Tortoise wins" << endl;
    } else {
        cout << "Hare wins" << endl;
    }
    //   // int *p = new (int);
    //    int *p = 10;
    //
    //
    //    int hare = 1;
    //    int *hare_pos = &hare;
    //
    
    return 0;
}
