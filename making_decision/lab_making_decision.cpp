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
};

CPackage::CPackage() {

}

CPackage::CPackage (char c) {
    switch (c) {
        case 'A':   fee = 9.95;
                    hours = 10;
                    addFee = 2;
                    id = 'a';
                    break;
        case 'B':   fee = 14.95;
                    hours = 20;
                    addFee = 1;
                    id = 'b';
                    break;
        case 'C':   fee = 19.95;
                    id = 'c';
                    break;
        default:    cout << "The package does not exist.\n";
    }
}

float calcBill(int hours, CPackage package) {
    float total = package.fee;
    if (hours > package.hours) {
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
    cout << "Limit is " << limit << endl;
    if (hours > limit) {
        validation = false;
    }
    return validation;
}

void calcSaving(CPackage package, int hours) {
    float savingAB, savingAC, savingBC;
    CPackage packageB('B');
    CPackage packageC('C');

    if (package.id = 'a') {

        if(calcBill(hours,package) > calcBill(hours,packageB)) {
            savingAB = calcBill(hours,package) - calcBill(hours,packageB);
            cout << "If you purched package B, you would save $" << savingAB << endl;
        }
        if(calcBill(hours,package) > calcBill(hours,packageC)) {
            savingAC = calcBill(hours,package) - calcBill(hours,packageC);
            cout << "If you purchesed package C, you would save $" << savingAC;
        }

    } else if (package.id = 'b') {
        if(calcBill(hours,package) > calcBill(hours,packageC)) {
            savingBC = calcBill(hours,package) - calcBill(hours,packageC);
            cout << "c bill is " << calcBill(hours,packageC) << endl;

            cout << "If you purched package C, you would save $" << savingBC << endl;
        }
    }
}




int main () {
    cout << "Which package did you purchase?(A, B or C): ";
    string transfer;
    char c;
    getline(cin,transfer);
    stringstream(transfer) >> c;
    CPackage package(c);

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



    return 0;
}

