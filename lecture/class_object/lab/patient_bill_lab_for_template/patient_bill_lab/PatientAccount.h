#ifndef Employee_h
#define Employee_h

#include <string>
#include <ostream>
#include "Surgery.h"
#include "Pharmacy.h"
using std::string;
using std::ostream;
const int HOSPITAL_RATE_PER_DAY = 50;

class PatientAccount {
public:
    string name;
    int age;
    string address;
    int ssn;
    int days;
    vector<Surgery> surgeries;
    vector<Pharmacy> medications;
    PatientAccount();
    int getHospitalFee();
    template <class T> int printSurgeryList(ostream &st, vector<T> items);
    int printMedicationList(ostream &st);
};




#endif

/**
 The PatientAccount class
 o Will keep patient’s personal information: Name, age, address, SSN
 o Will keep track of patient’s chargeable items, mainly surgeries and pharmacy items
 o Can print an itemized bill listing each item, its cost and the total cost.
 o It will also keep track of the number of days spent in the hospital. The group must
 decide on the hospital s daily rate.
 **/