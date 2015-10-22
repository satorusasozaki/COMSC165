#include "PatientAccount.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
using std::endl;

PatientAccount::PatientAccount(){
    name = "";
    age = 0;
    address = "";
    ssn = 0;
}

int PatientAccount::printSurgeryList(ostream &st) {
    int totalCost = 0;
    st << "Surgery\n";
    if (!surgeries.empty()) {
        for (Surgery item : surgeries) {
            st << "name: " << item.getName() << "\t"
            << "cost: " << item.getCharge() << endl;
            totalCost += item.getCharge();
        }
        st << "Total Surgery Cost: " << totalCost << endl;
    } else {
        st << "There is no surgery item added yet\n";
    }
    return totalCost;
}



int PatientAccount::printMedicationList(ostream &st) {
    int totalCost = 0;
    st << "Medications\n";
    if (!medications.empty()) {
        for (Pharmacy item : medications) {
            st << "name: " << item.getName() << "\t"
            << "cost: " << item.getCharge() << endl;
            totalCost += item.getCharge();
        }
        st << "Total Medication Cost: " << totalCost << endl;
    } else {
        st << "There is no surgery item added yet\n";
    }
    return totalCost;
}

