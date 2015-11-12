#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool isLeap(int year) {
    bool isLeap = false;
    if (year%4 == 0 && year%100 != 0) {
        isLeap = true;
    }
    return isLeap;

}



int main () {
    string transfer;
    getline(cin,transfer);
    stringstream ss;
    int month;
    int year;
    ss(transfer) >> month >> year;

    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 9:



    }


}
