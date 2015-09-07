/****************************************
Lab problem: making decision
Description: internet service provider
Name: Satoru Sasozaki
ID: 1516331
Date: September 6
Status: Complete
****************************************/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class CPackage {
public:
    float fee;
    float hours;
    int addFee;
    char id;
    CPackage();
    CPackage(char c);
    void setPlan(float userFee, float userHours, int userAddFee, char userId);
};

CPackage::CPackage() {
    fee = 0;
    hours = 0;
    addFee = 0;
    id = 'x';
}

void CPackage::setPlan(float userFee, float userHours, int userAddFee, char userId) {
    fee = userFee;
    hours = userHours;
    addFee = userAddFee;
    id = userId;
}

CPackage::CPackage (char c) {
    switch (c) {
        case 'a':   fee = 9.95;
            hours = 10;
            addFee = 2;
            id = c;
            break;
        case 'b':   fee = 14.95;
            hours = 20;
            addFee = 1;
            id = c;
            break;
        case 'c':   fee = 19.95;
            id = c;
            break;
        default:    cout << "The package does not exist.\n";
    }
}

float calcBill(int hours, CPackage package) {
    float total = package.fee;
    if (hours > package.hours && package.id != 'c') {
        total += (hours - package.hours) * package.addFee;
    }
    return total;
}

bool validate(int hours, string m) {
    int limit = 720;
    bool validation = true;
    switch (m.at(1)) {
        case 'a':
        case 'u':
        case 'c':
        case 'e':
            switch (m.at(2)) {
                case 'n':
                    if (m.at(3) == 'u') {
                        limit = 744;
                        break;
                    }
                case 'p':
                    break;
                case 'b': limit = 672;
                    break;
                default:  limit = 744;
            }
    }
    if (hours > limit) {
        validation = false;
    }
    return validation;
}

void calcSaving(CPackage package, int hours) {
    float savingB, savingC;
    CPackage packageB('b');
    CPackage packageC('c');

    float userTotal = calcBill(hours,package);
    float bTotal = calcBill(hours,packageB);
    float cTotal = calcBill(hours,packageC);

    if(userTotal > bTotal) {
        savingB = userTotal - bTotal;
        cout << "If you purched package B, you would save $" << savingB << endl;
    }
    if(userTotal > cTotal) {
        savingC = userTotal - cTotal;
        cout << "If you purchesed package C, you would save $" << savingC << endl;
    }
}

int main () {
    cout << "Do you want set your own plan?(y or n): ";
    string transfer;
    char yn;
    getline(cin,transfer);
    stringstream(transfer) >> yn;

    if(tolower(yn) == 'n'){
        cout << "Which package did you purchase?(A, B or C): ";
        char c;
        getline(cin,transfer);
        stringstream(transfer) >> c;
        CPackage package(tolower(c));

        cout << "How many hours did you use?: ";
        getline(cin,transfer);
        int hours;
        stringstream(transfer) >> hours;

        cout << "Input the name of the month: ";
        getline(cin,transfer);
        string month;
        stringstream(transfer) >> month;

        cout << "Your total due is $" << calcBill(hours, package) << endl;
        if (!validate(hours,month)) {
            cout << "You exceeded the limitation.\n" << endl;
        }
        calcSaving(package,hours);

    } else {
        CPackage userPackage;
        char userId;
        float userFee;
        float userHours;
        int userAddFee;

        cout << "Input the package ID: ";
        getline(cin,transfer);
        stringstream(transfer) >> userId;

        cout << "Input the fee: ";
        getline(cin,transfer);
        stringstream(transfer) >> userFee;

        cout << "Input the base hours: ";
        getline(cin,transfer);
        stringstream(transfer) >> userHours;

        cout << "Input the additional fee: ";
        getline(cin,transfer);
        stringstream(transfer) >> userAddFee;

        userPackage.setPlan(userFee, userHours, userAddFee, userId);

        cout << "How many hours did you use?: ";
        getline(cin,transfer);
        int hours;
        stringstream(transfer) >> hours;

        cout << "Input the name of the month: ";
        getline(cin,transfer);
        string month;
        stringstream(transfer) >> month;

        cout << "Your total due is $" << calcBill(hours, userPackage) << endl;

        if (!validate(hours,month)) {
            cout << "You exceeded the limitation.\n" << endl;
        }
    }
    return 0;
}

