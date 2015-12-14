#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Data{
private:
    int value;
    int times;
public:
    Data();
    int getValue(){ return value; }
    void setValue(int num) { value = num; }
    int getTimes() { return times; }
    void setTimes(int num) { times = num; }
    ~Data();
};

Data::Data() {
    setValue(0);
    setTimes(0);
}
Data::~Data() { 
}

int main() {
    vector<Data> numList;
    string filename("/Users/satoru/Dropbox/COMSC165/final/duplicate_n_stats/duplicate_n_stats/Integers.txt");
    fstream in(filename,ios::in);
    int totalCount = 0;
    if(in){
        string transfer;
        int buffer;
        if(getline(in,transfer)) {
            stringstream(transfer) >> buffer;
            Data data;
            data.setValue(buffer);
            numList.push_back(data);
            totalCount++;
        }
        
        while(getline(in,transfer)) {
            totalCount++;
            stringstream(transfer) >> buffer;
            Data data;
            data.setValue(buffer);
            int times = data.getTimes();
            times++;
            data.setTimes(times);
            
            // Duplicated values are not added to list
            if (data.getValue() >= numList.back().getValue()) {
                if (data.getValue() == numList.back().getValue()) {
                    int times = numList.back().getTimes();
                    times++;
                    numList.back().setTimes(times);
                } else {
                    numList.push_back(data);
                }
            } else if (data.getValue() <= numList.front().getValue()) {
                if (data.getValue() == numList.front().getValue()) {
                    int times = numList.front().getTimes();
                    times++;
                    numList.front().setTimes(times);
                } else {
                    numList.insert(numList.begin(),data);
                }
            } else {
                bool isFound = false;
                for (int i=0; i<numList.size() && !isFound; i++) {
                    if (numList.at(i).getValue() == data.getValue()) {
                        int times = numList.at(i).getTimes();
                        times++;
                        numList.at(i).setTimes(times);
                        isFound = true;
                    } else if (numList.at(i).getValue() > data.getValue()) {
                        numList.insert(numList.begin()+i, data);
                        isFound = true;
                    }
                }
            }
        }
    } else {
        cout << "Failed to open\n";
    }
    
    in.close();
    
    fstream out("/Users/satoru/Dropbox/COMSC165/final/duplicate_n_stats/duplicate_n_stats/out.txt", ios::out);
    if (out) {
        out << "Total: " << totalCount << endl
            << "Min value: " << numList.front().getValue() << endl
            << "Max value: " << numList.back().getValue() << endl
            << "Duplicated values: " << endl;
        for (int i=0; i<numList.size(); i++) {
            if (numList.at(i).getTimes() > 1) {
                out << setw(10) << left << numList.at(i).getValue() << setw(3) << left << numList.at(i).getTimes() << " occured" <<endl;
            }
        }
        out << "Non-Duplicated values: " << endl;
        for (int i=0; i<numList.size(); i++) {
            if (numList.at(i).getTimes() == 1) {
                out << numList.at(i).getValue() << endl;
            }
        }
    } else {
        cout << "Failed to open out file\n";
    }
    
    return 0;
    
}