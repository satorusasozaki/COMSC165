#ifndef Employee_h
#define Employee_h

#include <string>
#include <ostream>
#include "Surgery.h"
#include "Pharmacy.h"
using std::string;
using std::ostream;

class PatientAccount {
public:
    string name;
    int age;
    string address;
    int ssn;
    PatientAccount();
    int printSurgeryList(ostream &st);
    int printMedicationList(ostream &st);
    vector<Surgery> surgeries;
    vector<Pharmacy> medications;
private:
    //	Will keep track of patient’s chargeable items, mainly surgeries and pharmacy items
    
    static int days;
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