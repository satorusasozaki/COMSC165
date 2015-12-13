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
    string filename("/Users/satoru/Dropbox/COMSC165/final/duplicate_n_stats/duplicate_n_stats/in.txt");
    fstream in(filename,ios::in);
    if(in){
        string transfer;
        int count = 0;
        while(getline(in,transfer)) {
            int buffer;
            stringstream(transfer) >> buffer;
            Data data;
            data.setValue(buffer);
            if (count==0) {
                numList.push_back(data);
            }
            if (count==1) {
                if (numList.at(0).getValue() > data.getValue()) {
                    numList.insert(numList.begin(), data);
                } else if (numList.at(0).getValue() == data.getValue()) {
                    int times = numList.at(0).getTimes();
                    times++;
                    numList.at(0).setTimes(times);
                } else {
                    numList.push_back(data);
                }
            }
            int posToInsert = 0;
            for (int i=0; i<numList.size()-1; i++) {
                if (data.getValue() > numList.at(i).getValue() && data.getValue() < numList.at(i+1).getValue()  ) {
                    posToInsert = i;
                } else if (data.getValue() == numList.at(i).getValue() ) {
                    int times = numList.at(i).getTimes();
                    times++;
                    numList.at(i).setTimes(times);
                } else {
//                    numList.push_back(data);
                }
                
            }
                
            numList.insert(numList.begin()+posToInsert, data);

            
            /*
            int posToInsert=0;
            
            for (int i=0; i<numList.size()-1/* && data.getValue() >= numList.at(i).getValue() ; i++) {
                if (i==0) {
                  numList.push_back(data);
                } else if (i==1) {
                    if (data.getValue() < numList.at(i).getValue()) {
                        numList.insert(numList.begin(), data);
                    } else {
                        numList.push_back(data);
                    }
                    
                } else if (data.getValue() >= numList.at(i).getValue() && data.getValue() < numList.at(i+1).getValue()) {
                    posToInsert = i;
                }
                if (data.getValue() == numList.at(i).getValue()) {
                    int times = numList.at(i).getTimes();
                    times++;
                    numList.at(i).setValue(times);
                }
            }
            cout << "posToInsert " << posToInsert << endl;
            numList.insert(numList.begin()+posToInsert, data);
            */
            count++;
        }
        
    } else {
        cout << "Failed to open\n";
    }
    
    in.close();
    
    for (int i=0; i<numList.size(); i++) {
        cout << numList.at(i).getValue() << endl;
    }
    
    
    return 0;
    
}