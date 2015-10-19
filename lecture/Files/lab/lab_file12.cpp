#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

const int NUM_OF_DIVISION = 4;
const int NUM_OF_QUARTER = 4;

struct Quarter {
    int quarter;
    int sales;
};

struct Info {
    vector<Quarter> q = {{1,0},{2,0},{3,0},{4,0}};
};




int main() {
    vector<Info> info(4);

    fstream inFile("output1.txt", ios::in);
    string transfer;
    string name;
    int quarter;
    double sales;
    getline(cin, transfer);
    stringstream(transfer) >> name >> quarter >> sales;
    switch(name.at(0)) {
        case 'E':info.at(0);//.q.(quarter-1).sales = sales;


    }




}
