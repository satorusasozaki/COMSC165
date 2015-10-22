#include <iostream>
#include <string>
#include <sstream>
#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"
using namespace std;


bool rangeValidation(unsigned long int listSize, int selectedNum) {
    return (0 < listSize) && (listSize >= selectedNum);
}

int askNumber() {
    string transfer;
    int num;
    getline(cin,transfer);
    stringstream(transfer) >> num;
    return num;
}

void displayPatientName(vector<PatientAccount> &pVec) {
    if(!pVec.empty()) {
        for (int i=0; i<pVec.size(); i++) {
            cout << i+1 << ": " << pVec.at(i).name << endl;
        }
    } else {
        cout << "The list is empty. Please add a patient\n";
    }
}

void displayDetailedBill(vector<PatientAccount> pVec) {
    displayPatientName(pVec);
    cout << "Enter the patient number: ";
    int paIndex = askNumber();
    bool valid = rangeValidation(pVec.size(),paIndex);
    if (!pVec.empty() && valid) {
        PatientAccount pa = pVec.at(paIndex-1);
        int sTotal = pa.printSurgeryList(cout);
        int pTotal = pa.printMedicationList(cout);
        cout << "Overall total is $" << sTotal+pTotal << endl;
    } else {
        cout << "There is no patient numbered " << paIndex << endl;
    }
}

void addNewPatient(vector<PatientAccount> &pVec) {
    string transfer;
    PatientAccount p;
    cout << "Please input the following infomation about the patient\n"
         << "name: ";
    getline(cin,transfer);
    p.name = transfer;
    
    cout << "age: ";
    getline(cin,transfer);
    int num;
    stringstream(transfer) >> num;
    p.age = num;
    
    cout << "address: ";
    getline(cin,transfer);
    p.address = transfer;
    
    cout << "SSN: ";
    getline(cin,transfer);
    stringstream(transfer) >> num;
    p.ssn = num;
    pVec.push_back(p);
}

void checkOutPatient(vector<PatientAccount> &pVec) {
    displayPatientName(pVec);
    cout << "Enter the patient number: ";
    int pIndex = askNumber();
    bool valid = rangeValidation(pVec.size(),pIndex);
    if (!pVec.empty() && valid) {
        pVec.erase(pVec.begin() + pIndex-1);
        cout << "Patient " << pIndex+1 << " has been checked out\n";
    }  else {
        cout << "There is no patient numbered " << pIndex << endl;
    }
}

void addSurgeryItem(vector<PatientAccount> &pVec) {
    displayPatientName(pVec);
    cout << "Enter the patient number: ";
    int pIndex = askNumber();
    bool valid = rangeValidation(pVec.size(),pIndex);
    if (!pVec.empty() && valid) {
        Surgery s;
        s.printList(cout);
        cout << "Enter the item number: ";
        s.index = askNumber();
        s.setItem(cout);
        pVec.at(pIndex-1).surgeries.push_back(s);
    }  else {
        cout << "There is no patient numbered " << pIndex << endl;
    }
}

void addPharmacyItem(vector<PatientAccount> &pVec) {
    displayPatientName(pVec);
    cout << "Enter the patient number: ";
    int pIndex = askNumber();
    bool valid = rangeValidation(pVec.size(),pIndex);
    if (!pVec.empty() && valid) {
        Pharmacy p;
        p.printList(cout);
        cout << "Enter the item number: ";
        p.index = askNumber();
        p.setItem(cout);
        pVec.at(pIndex-1).medications.push_back(p);
    }  else {
        cout << "There is no patient numbered " << pIndex << endl;
    }
}

void displayMenu() {
    cout << "1. Add new patient\n"
         << "2. Display a patient’s detailed bill\n"
         << "3. Check out a patient\n"
         << "4. Add surgery item to a patient’s account\n"
         << "5. Add pharmacy item to a patient’s account\n";
}

int main() {
    vector<PatientAccount> pVec;
    int choice;
    do{
        displayMenu();
        cout << "Enter the number in the list: ";
        int choice = askNumber();
        switch (choice) {
            case 1: addNewPatient(pVec);
                break;
            case 2: displayDetailedBill(pVec);
                break;
            case 3: checkOutPatient(pVec);
                break;
            case 4: addSurgeryItem(pVec);
                break;
            case 5: addPharmacyItem(pVec);
                break;
            default:
                break;
        }
    }while(choice <= 5);
    
    cout << "Bye bye\n";
    return 0;
}



