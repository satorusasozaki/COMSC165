#include <iostream>
#include <string>
#include <sstream>
#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"
using namespace std;


//inline bool rangeValidation (unsigned long int listSize, int selectedNum) {
//    return selectedNum <= listSize;
//}


int askNumber(unsigned long int size, bool rangeValidation) {
    string transfer;
    int num;
    getline(cin,transfer);
    stringstream(transfer) >> num;
    
    if (num <= size) {
        rangeValidation = true;
    } else {
        rangeValidation = false;
    }
    return num;
}

bool displayPatientName(vector<PatientAccount> &pVec) {
    if(!pVec.empty()) {
        for (int i=0; i<pVec.size(); i++) {
            cout << i+1 << ": " << pVec.at(i).name << endl;
        }
    } else {
        cout << "The list is empty. Please add a patient\n";
    }
    return pVec.empty();
}

void displayDetailedBill(vector<PatientAccount> pVec) {
    displayPatientName(pVec);
    bool rangeValidation;
    unsigned long int listSize = pVec.size();
    int pIndex = askNumber(listSize, rangeValidation) - 1;
    if (displayPatientName(pVec) && rangeValidation) {
        PatientAccount p = pVec.at(pIndex);
        p.printItems(cout);
    } else {
        cout << "There is no patient numbered " << pIndex+1 << endl;
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
    bool rangeValidation;
    unsigned long int listSize = pVec.size();
    int pIndex = askNumber(listSize, rangeValidation) - 1;
    if (displayPatientName(pVec) && rangeValidation) {
        pVec.erase(pVec.begin() + pIndex);
        cout << "Patient " << pIndex+1 << " has been checked out\n";
    }  else {
        cout << "There is no patient numbered " << pIndex+1 << endl;
    }
}

void addSurgeryItem(vector<PatientAccount> &pVec) {
    displayPatientName(pVec);
    bool rangeValidation;
    unsigned long int listSize = pVec.size();
    int pIndex = askNumber(listSize, rangeValidation) - 1;
    if (displayPatientName(pVec) && rangeValidation) {
        pVec.erase(pVec.begin() + pIndex);
        cout << "Patient " << pIndex+1 << " has been checked out\n";
    }  else {
        cout << "There is no patient numbered " << pIndex+1 << endl;
    }
}

void addPharmacyItem(vector<PatientAccount> &pVec) {
    
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
    
    do{
        displayMenu();
        switch (askNumber()) {
            case 1: addNewPatient(pVec);
                break;
            case 2: displayDetailedBill(pVec);
                break;
            case 3: checkOutPatient(pVec);
                break;
            case 4: addSurgeryItem(pVec);
                break;
            case 5:
            default:
                break;
        }
        
        
        
        
    }while(false);
    
    
    
    
    PatientAccount pa;

    Surgery s;
    s.index = 3;
    s.setItem(cout);
    pa.surgeries.push_back(s);
    cout << pa.surgeries.at(0).name << endl;
    cout << pa.surgeries.at(0).charge << endl;
    
    Pharmacy p;
    p.index = 3;
    p.setItem(cout);
    pa.medications.push_back(p);
    cout << pa.medications.at(0).name << endl;
    cout << pa.medications.at(0).charge << endl;
    

    addNewPatient(pVec);
    displayDetailedBill(pVec);
    s.printList(cout);
    p.printList(cout);
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}



