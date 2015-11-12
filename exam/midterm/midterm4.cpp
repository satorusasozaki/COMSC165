#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <fstream>

using namespace std;


bool isAnagrams (string a, string b) {
    bool isAnagram = true;

    string newA;
    for (int i=0; i < a.size(); i++) {
        if (isalpha(a.at(i))) {
            newA += a.at(i);
        }
    }
    cout << "newA: " << newA << endl;

    string newB;
    for (int i=0; i < b.size(); i++) {
        if (isalpha(b.at(i))) {
            newB += b.at(i);
        }
    }
    cout << "newB: " << newB << endl;

    int totalA = 0;
    int totalB = 0;

    if (newA.size() == newB.size()) {
        for (int i=0; i < newA.size(); i++) {
            totalA += tolower(newA.at(i));
            totalB += tolower(newB.at(i));
        }
    } else {
        isAnagram = false;

    }

   if (totalA != totalB) {
        isAnagram = false;
    }

    return isAnagram;

}



int main () {

    string fileName;

    do {
        cout << "Input the file name: ";
        getline(cin,fileName);

        fstream in;
        in.open(fileName,ios::in);

        vector<string> pairs;
        if(in) {
            string transfer;
            while(getline(in,transfer)) {
                pairs.push_back(transfer);
            }

            if (pairs.size() == 2) {
                if (isAnagrams(pairs.at(0), pairs.at(1))) {
                    cout << pairs.at(0) << " and " << pairs.at(1) << " is anagrams\n";
                } else {
                    cout << pairs.at(0) << " and " << pairs.at(1) << " is NOT anagrams\n";
                }

            } else {
                cout << "The number of lines read from the file is not 2\n";
            }

        }
    } while(!fileName.empty());

    return 0;

}
