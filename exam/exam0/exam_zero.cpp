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
#include <fstream>
#include <vector>

using namespace std;


vector<string> askFileName () {
    string userInput;
    getline(cin,userInput);
    return userInput;
}

vector<float> askUserInfo (vector<string> &name) {
    string transfer;
    vector<float> v;
    getline(cin,transfer);
    stringstream(transfer) >> name;
    for (int i=0; i < 4; i++) {
        stringstream(transfer) >> v.at(i);
    }

    return v;

}
void writeFile (string fileName, vector<string> name, vector<float> score, vector<float> average, float overallAve){
    ofstream theFile;
    theFile.open (fileName);
    if(theFile) {
        theFile << "DVC DRIVING CONTEST - SCORES" << endl
                << "Name"  << "\t" << "Scores\t\t\t" << "Averages" << endl
                << "----------------------------------------------------------------------------\n";
        for (int i=0; i < name.size(); i++) {
            theFile << name.at(i) << "\t";
            for (int j=0; j < 4; j++){
                theFile << score.at(i).at(j) << " ";
            }
            theFile << average.at(i);
        }
        theFile << "\n----------------------------------------------------------------------------\n";
        theFile << overallAve;
    }
    theFile.close();
}

void display (vector<string> name, vector<float> score, vector<float> average, float overallAve) {
    cout << "DVC DRIVING CONTEST - SCORES" << endl
         << "Name"  << "\t" << "Scores\t\t\t" << "Averages" << endl
         << "----------------------------------------------------------------------------\n";
        for (int i=0; i < name.size(); i++) {
            theFile << name.at(i) << "\t";
            for (int j=0; j < 4; j++){
                cout << score.at(i).at(j) << " ";
            }
            cout << average.at(i);
        }
        theFile << "\n----------------------------------------------------------------------------\n";
        theFile << "\t\t\t\t\t\t\t\t" << overallAve;
}

float calcAverage (vector<float> &v){
    float minimum = v.at(0);
    float maximum = v.at(0);
    int minIndex;
    int maxIndex;

    for (int i=0; i<v.size(); i++) {
        if (v.at(i) < minimum) {
             minIndex = i;
             minimum = v.at(i);
        }
        if (v.at(i) > maximum) {
            maxIndex = i;
            maximum = v.at(i);
        }
    }
    v.erase(minIndex);
    v.erase(maxIndex);

    float total;
    for (int i=0; i <v.size(); i++) {
        total += v.at(i);
    }
    float average = total / v.size();
    return average;
}

int main () {
    vector<float> scoreByUser;
    vector<string> name;
    vector<float> average;
    float overallAve;


    string fileName = askFileName();

    do {
    vector<float> scores = askUserInfo(name);
    scoreByUser.push_back(scores);
    average.push_back(alcAverage(scores));

    } while ()

    float total;
    for (int i=0; i < average.size(); i++){
        total += average.at(i);
    }
    overallAve = total / average.size();

    writeFile(fileName,name,scoreByUser,average,overallAve);

    return 0;
}
