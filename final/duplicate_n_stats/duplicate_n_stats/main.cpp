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
    setTimes(1);
}
Data::~Data() { 
}

int main() {
    vector<Data> numList;
    string filename("/Users/satoru/Dropbox/COMSC165/final/duplicate_n_stats/duplicate_n_stats/Integers.txt");
    fstream in(filename,ios::in);
    if(in){
        string transfer;
        int buffer;
        int max = 0;
        int min = 0;
        if(getline(in,transfer)) {
            stringstream(transfer) >> buffer;
            Data data;
            data.setValue(buffer);
            numList.push_back(data);
            max = buffer;
            min = buffer;
        }
        
        while(getline(in,transfer)) {
            stringstream(transfer) >> buffer;
            Data data;
            data.setValue(buffer);
            // Duplicated values are not added to list
            if (data.getValue() >= max) {
                if (data.getValue() == max) {
                    int times = numList.back().getTimes();
                    times++;
                    numList.back().setTimes(times);
                } else {
                    numList.push_back(data);
                    max = data.getValue();
                }
            } else if (data.getValue() <= min) {
                if (data.getValue() == min) {
                    int times = numList.front().getTimes();
                    times++;
                    numList.front().setTimes(times);
                } else {
                    numList.insert(numList.begin(),data);
                    min = data.getValue();
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
    
    for (int i=0; i<numList.size(); i++) {
        if (numList.at(i).getTimes() > 3) {
            cout << setw(10) << left << numList.at(i).getValue() << setw(3) << left << numList.at(i).getTimes() << " occured" <<endl;
        }
    }
    
    
    return 0;
    
}