#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

const int NUM_OF_DIVISION = 4;
const int NUM_OF_QUARTER = 4;
const vector<string> NAME_OF_DIVISION = {"East", "West", "North", "South"};

class Quarter {
public:
    int quarterNum;
    double sales;
};

struct DivisionInfo {
    string name;
    Quarter quarterInfo[4];
};

void initDivisionName(vector<DivisionInfo> &divisionInfo) {
    for (int i=0; i<NUM_OF_DIVISION; i++) {
        divisionInfo.at(i).name = (NAME_OF_DIVISION.at(i));
        cout << divisionInfo.at(i).name << endl;
    }
}

void writeToFile(vector<DivisionInfo> d) {
    fstream outFile("data.txt",ios::out);
    if(outFile) {
        for (int i=0; i<d.size() ;i++) {
            outFile << d.at(i).name << endl;
            for (int j=0; j<NUM_OF_QUARTER; j++) {
                outFile << "Quarter " << j+1 << ": " << d.at(i).quarterInfo[j].sales << endl;
            }
        }
    } else {
        cout << "The file cannot be opened" << endl;
    }
    outFile.close();
    
}



int main() {
    
    vector<DivisionInfo> d(NUM_OF_DIVISION);
    
    initDivisionName(d);
    
    
    // string name;
    // string name = d().at(0).name;
    // char a = 'a';
    //    cout << "name: " << d().size() << end;
    
    string transfer;
    for (int i=0; i<d.size(); i++) {
        cout <<"Input the quartely sales for " <<  d.at(i).name << endl;
        for (int j=0; j<NUM_OF_QUARTER; j++) {
            cout << "Quarter " << j+1 << ": "<< endl;
            getline(cin, transfer);
            stringstream(transfer) >> d.at(i).quarterInfo[j].sales;
        }
    }
    
    writeToFile(d);
    
    
    
    
    return 0;
}
