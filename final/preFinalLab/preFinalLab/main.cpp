#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

void getValuesFromFile(vector<int> &originalValues, int &total) {
    int counter = 0;
    fstream in("integers.txt", ios::in);
    if (in) {
        string transfer;
        while (getline(in, transfer)) {
            counter++;
            int num;
            stringstream(transfer) >> num;
            originalValues.push_back(num);
        }
    }
    else {
        cout << "The input file is failed to open the file\n";
    }
    total = counter;

    in.close();
}

int findHighValue(vector<int> &originalValues) {
    int high = originalValues.at(0);
    for (int value : originalValues) {
        if (high < value) {
            high = value;
        }
    }
    return high;
}

int findLowValue(vector<int> &originalValues) {
    int low = originalValues.at(0);
    for (int value : originalValues) {
        if (low > value) {
            low = value;
        }
    }
    return low;
}

void findDuplicate(vector<int> &originalValues, vector<int> &duplicatedValues,
                   vector<int> &numOfDuplicates, vector<int> &nonRepeatedValues) {
    //for (int a : originalValues) {
    for (int i = 0; i < originalValues.size(); i++) {
        int dup;
        int numOfDup = 0;
        //for (int b : originalValues) {
        for (int j = 0; j < originalValues.size(); j++) {
            if (originalValues.at(i) == originalValues.at(j)) {
                dup = originalValues.at(i);
                numOfDup++;
            }
        }
        if (numOfDup > 1) {
            duplicatedValues.push_back(dup);
            numOfDuplicates.push_back(numOfDup);
        } else {
            nonRepeatedValues.push_back(originalValues.at(i));
        }
    }
}

void writeToFile(vector<int> duplicatedValues,
                 vector<int> numOfDuplicates, vector<int> nonRepeatedValues, int low, int high,int total) {
    string fileName = "out.txt";
    fstream out(fileName, ios::out);
    if (out) {
        out << "Duplicates and Stats - File: " << fileName << endl
        << "Total values in data file: " << total << endl
        << "Low value: " << low << endl
        << "High value: " << high << endl
        << "==================================" << endl
        << "Duplicated values: " << endl;
        for (int i = 0; i < duplicatedValues.size(); i++) {
            out << duplicatedValues.at(i) << "\t\toccurred\t\t"
            << numOfDuplicates.at(i) << " times" << endl;
        }
        out << "==================================" << endl
        << "Non-Repeated Values: " << endl;
        for (int i = 0; i < nonRepeatedValues.size(); i++) {
            out << nonRepeatedValues.at(i) << endl;
        }
        
    } else {
        cout << "The output file is failed to open\n";
    }
    
}

/*
 void sortList(vector<int> &list) {
	for (int i = 0; i < list.size(); i++) {
 for (int j = 0; j < list.size() - 1; j++) {
 int temp;
 if (list.at(j) > list.at(j + 1)) {
 temp = list.at(j);
 list.at(j) = list.at(j + 1);
 list.at(j + 1) = temp;
 }
 }
	}
 }
*/



int main() {
    vector<int> originalValues;
    vector<int> duplicatedValues;
    vector<int> numOfDuplicates;
    vector<int> nonRepeatedValues;
    
    int total;
    getValuesFromFile(originalValues, total);
    int high = findHighValue(originalValues);
    int low = findLowValue(originalValues);
    
    findDuplicate(originalValues, duplicatedValues, numOfDuplicates, nonRepeatedValues);
    //sortList(nonRepeatedValues);
    writeToFile(duplicatedValues, numOfDuplicates, nonRepeatedValues, low, high, total);
}







