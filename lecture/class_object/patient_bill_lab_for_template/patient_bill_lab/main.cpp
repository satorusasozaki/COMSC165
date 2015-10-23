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
        cout << "The list is empty. Please select 1 to add a patient." << endl;
    }
}

bool askAndValidate(vector<PatientAccount> pVec, int &paIndex) {
    displayPatientName(pVec);
    cout << "Enter the patient number: ";
    paIndex = askNumber();
    bool valid = rangeValidation(pVec.size(),paIndex);
    return (!pVec.empty() && valid);
}

void displayDetailedBill(vector<PatientAccount> pVec) {
    int paIndex;
    bool canProceed = askAndValidate(pVec,paIndex);
    if (canProceed) {
        PatientAccount pa = pVec.at(paIndex-1);
        int sTotal = pa.printSurgeryList<Surgery>(cout,pa.surgeries);
        int pTotal = pa.printMedicationList(cout);
        int hTotal = pa.getHospitalFee();
        cout << "Hospital fee is $" << hTotal << endl;
        cout << "Overall total is $" << (sTotal + pTotal + hTotal) << endl;
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
    
    cout << "How many days have you spent in this hospital?: ";
    getline(cin,transfer);
    stringstream(transfer) >> num;
    p.days = num;
    
    pVec.push_back(p);

}

void checkOutPatient(vector<PatientAccount> &pVec) {
    int paIndex;
    bool canProceed = askAndValidate(pVec,paIndex);
    if (canProceed) {
        pVec.erase(pVec.begin() + paIndex-1);
        cout << "Patient " << paIndex+1 << " has been checked out\n";
    }  else {
        cout << "There is no patient numbered " << paIndex << endl;
    }
}

void addSurgeryItem(vector<PatientAccount> &pVec) {
    int paIndex;
    bool canProceed = askAndValidate(pVec,paIndex);
    if (canProceed) {
        Surgery s;
        s.printList(cout);
        cout << "Enter the item number: ";
        s.index = askNumber();
        s.setItem(cout);
        pVec.at(paIndex-1).surgeries.push_back(s);
    }  else {
        cout << "There is no patient numbered " << paIndex << endl;
    }
}

void addPharmacyItem(vector<PatientAccount> &pVec) {
    int paIndex;
    bool canProceed = askAndValidate(pVec,paIndex);
    if (canProceed) {
        Pharmacy p;
        p.printList(cout);
        cout << "Enter the item number: ";
        p.index = askNumber();
        p.setItem(cout);
        pVec.at(paIndex-1).medications.push_back(p);
    }  else {
        cout << "There is no patient numbered " << paIndex << endl;
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
                cout << "Wrong number!" << endl;
                break;
        }
        
        cout << endl << endl;
    }while(choice <= 5);
    
    cout << "Bye bye\n";
    return 0;
}



