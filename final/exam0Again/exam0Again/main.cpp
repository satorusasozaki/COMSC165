/*
 Write a program that calculates divers' average scroes in a diving contest as follows:
 
 - Prompts the user for an output file name
 
 - Prompts the user to input each diver's 1st name, and a set of 5 scores (all in 1 line)
 
 - Continues to input data until the user inputs an empty line.
 
 - The program then will print (to screen AND to file):
 
 A) A table of divers' names , scores, and the average score per diver.
 -  Average score is calculated by dropping the highest and lowest score and average the remaining 3 scores
 - Scores values are between 0 and 20.0
 
 B) The contest's score average (average score of all divers' averages) aligned unders the averages column
 
 -The same output will be saved to the file.
 
 -HINT/Reminder: all output streams are of type ostream
 
 
 
 DVC DIVING CONTEST - SCORES
 
 Name                 Scores             Average
 ---------------------------------------------------
 John         12.5  7.0 11.2 10.1  9.5   10.3
 Alexander     6.0 10.2  2.2 11.1 11.2    9.1
 Alan         11.1  9.9 10.2  7.2  2.2    9.1
 ---------------------------------------------------
 9.5
 
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

struct UserData {
    string name;
    vector<double> scores;
};

void outputData(vector<UserData> const &list, ostream &st) {
    st << setw(20) << left << "Name" << setw(20) << left << "Scores" << left << "Average\n"
       << left << "-------------------------------------------------------------\n";
    double averageForAll = 0;
    for (UserData data : list) {
        double total = 0;
        st << setw(15) << left << data.name;
        for (int score : data.scores) {
            st << setw(3) << right << score << " ";
            total += score;
        }
        double average = total / data.scores.size();
        averageForAll += average;
        st << "  " << setw(3) << right << average << endl;
    }
    averageForAll /= list.size();
    st << setw(60) << right << averageForAll << endl;
}



int main () {
    vector<UserData> userDataList;
    
    
    
    cout << "Input the output file name: ";
    string filename;
    getline(cin,filename);

    string transfer;
    cout << "Input the driver's first name and 5 scores with commas: ";
    while (getline(cin,transfer) && !transfer.empty()) {
        UserData newData;
        stringstream ss;
        ss << transfer;
        string buffer;
        getline(ss,buffer,',');
        newData.name = buffer;
        for (int i=0; i < 5; i++) {
            string transfer;
            int buffer;
            getline(ss,transfer,',');
            stringstream(transfer) >> buffer;
            newData.scores.push_back(buffer);
        }
        userDataList.push_back(newData);
    }
    outputData(userDataList, cout);
    
    fstream out(filename, ios::out);
    if (out) {
        outputData(userDataList, out);
    } else {
        cout << "Failed to open\n";
    }
    out.close();
    
    
    return 0;
    
}

