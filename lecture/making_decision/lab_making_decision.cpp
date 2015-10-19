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
private:
    float fee_;
    float hours_;
    int addFee_;
    char id_;
public:
    CPackage();
    CPackage(char c, bool& packValidation);
    void setPlan(char c);
    float getFee() {return fee_;}
    float getHours() {return hours_;}
    int getAddFee() {return addFee_;}
    char getId() {return id_;}
};

CPackage::CPackage() {
    fee_ = 0;
    hours_ = 0;
    addFee_ = 0;
    id_ = 0;
}

void CPackage::setPlan(char c) {
    switch (c) {
        case 'a':   fee_ = 9.95;
                    hours_ = 10;
                    addFee_ = 2;
                    id_ = c;
                    break;
        case 'b':   fee_ = 14.95;
                    hours_ = 20;
                    addFee_ = 1;
                    id_ = c;
                    break;
        case 'c':   fee_ = 19.95;
                    id_ = c;
                    break;
        default:    cout << "The package does not exist.\n";
    }
}

CPackage::CPackage (char c, bool& packValidation) {
    switch (c) {
        case 'a':   fee_ = 9.95;
                    hours_ = 10;
                    addFee_ = 2;
                    id_ = c;
                    break;
        case 'b':   fee_ = 14.95;
                    hours_ = 20;
                    addFee_ = 1;
                    id_ = c;
                    break;
        case 'c':   fee_ = 19.95;
                    id_ = c;
                    break;
        default:    packValidation = false;
    }
}

float calcBill(int hours, CPackage package) {
    float total = package.getFee();
    if (hours > package.getHours() && package.getId() != 'c') {
        total += (hours - package.getHours()) * package.getAddFee();
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
    CPackage packageB;
    packageB.setPlan('b');
    CPackage packageC;
    packageC.setPlan('c');

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
    bool packValidation = true;
    string transfer;
    cout << "Which package did you purchase?(A, B or C): ";
    char c;
    getline(cin,transfer);
    stringstream(transfer) >> c;
    CPackage package(tolower(c), packValidation);
    if (packValidation) {
        cout << "How many hours did you use?: ";
        getline(cin,transfer);
        int hours;
        stringstream(transfer) >> hours;

        cout << "Input the name of the month: ";
        getline(cin,transfer);
        string month;
        stringstream(transfer) >> month;

        if (validate(hours,month)) {
            cout << "Your total due is $" << calcBill(hours, package) << endl;
            calcSaving(package,hours);
        } else {
            cout << "You cannot exceed the time limitation.\n" << endl;
        }
    } else {
        cout << "The package does not exist.\n";
    }
    return 0;
}

