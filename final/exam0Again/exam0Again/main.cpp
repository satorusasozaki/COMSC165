#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

struct UserData {
    string name;
    vector<int> scores;
};

void outputData(vector<UserData> const &list, ostream &st) {
    st << setw(20) << left << "Name" << setw(20) << left << "Scores" << setw(20) << left << "Average\n"
       << "--------------------------------------------------------------------------------\n";
    int averageForAll = 0;
    for (UserData data : list) {
        int total = 0;
        st << setw(15) << left << data.name;
        for (int score : data.scores) {
            st << setw(3) << right << score << " ";
            total += score;
        }
        int average = total / data.scores.size();
        averageForAll += average;
        st << "  " << setw(3) << right << average << endl;
    }
    st << setw(90) << right << averageForAll << endl;
}



int main () {
    vector<UserData> userDataList;
    
    
    
    cout << "Input the output file name: ";
    string filename;
    getline(cin,filename);

    string transfer;
    cout << "Input the driver's first name and 5 scores with commas: ";
    while (getline(cin,transfer)) {
        UserData newData;
        stringstream ss;
        ss << transfer;
        ss >> newData.name;
        for (int i=0; i < 5; i++) {
            int buffer;
            ss >> buffer;
            newData.scores.push_back(buffer);
        }
        userDataList.push_back(newData);
    }
    outputData(userDataList, cout);
    
    

    
    
    
    return 0;
    
}

