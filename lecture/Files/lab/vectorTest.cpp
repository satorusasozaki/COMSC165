/*********************************************************************
Problem: W06 - problem 11
Description : This Program generates a list of divisions and then
              prompts a user to input the quarterly sales
Name : Satoru Sasozaki
ID : 1516331
Date : 09 / 23 / 15
Status :Complete
*********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_OF_DIVISION = 4, NUM_OF_QUARTERS = 4;
const vector<string> NAME_OF_DIVISION = { "East", "West", "North", "South" };

class Quarter {
public:
    int quarter = 0;
    double sales = 0;
};

struct DivisionInfo {
    string name;
    vector<Quarter> quarters(4,0);
//    Quarter quarters[4];

    void saveData(string name){

        ofstream file;
        file.open(name, ios::out | ios::app);

        if (file){
            for (int i = 0; i < NUM_OF_QUARTERS; i++){

                file << DivisionInfo::name << " " << DivisionInfo::quarters[i].quarter << " " << fixed << setprecision(2) << DivisionInfo::quarters[i].sales << endl;
            }
            file.close();
        }
        else cout << "Error: Could not open file!";
    }

};

void initDivisionName(vector<DivisionInfo> &divisionInfo) {
    for (int i = 0; i<NUM_OF_DIVISION; i++) {
        divisionInfo.at(i).name = (NAME_OF_DIVISION.at(i));
        for (int j = 0; j < NUM_OF_QUARTERS; j++){
            divisionInfo.at(i).quarters[j].quarter = j+1;
        }
    }
}

void promptUser(string division, int quarter){
    cout << "Please enter the information for division " << division << " in quarter " << quarter << endl;
    }

int main(){

    string s, name;
    bool valid = false;
    vector<DivisionInfo> yearlySales(NUM_OF_DIVISION);

    initDivisionName(yearlySales);

    cout << "Please name the file : ";
    getline(cin, name);

    ofstream file;
    while (valid)
    file.open(name, ios::out);
    if (file){
        valid = true;
    }
    else {
        cout << "Could not open file";
        getline(cin, name);
    }


    for (int i = 0; i < NUM_OF_DIVISION; i++){
        cout << "Please enter the sales for division " << yearlySales.at(i).name << endl;
        for (int j = 0; j < NUM_OF_QUARTERS; j++){
            cout << "Quarter " << yearlySales.at(i).quarters[j].quarter << ": ";
            double validationBuffer;
            getline(cin, s);
            stringstream(s) >> validationBuffer;
            while(validationBuffer < 0) {
                cout << "You cannot input a negative number, try again: ";
                getline(cin, s);
                stringstream(s) >> validationBuffer;
            }
            yearlySales.at(i).quarters[j].sales = validationBuffer;
        }
        yearlySales.at(i).saveData(name);
    }

    return 0;
}
