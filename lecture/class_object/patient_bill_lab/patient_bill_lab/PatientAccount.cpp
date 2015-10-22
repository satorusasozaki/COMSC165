#include "PatientAccount.h"

#include <string>
#include <vector>
#include <iomanip>

using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::left;

PatientAccount::PatientAccount(){
    name = "";
    age = 0;
    address = "";
    ssn = 0;
}

int PatientAccount::getHospitalFee() {
    return HOSPITAL_RATE_PER_DAY * days;
}

int PatientAccount::printSurgeryList(ostream &st) {
    int totalCost = 0;
    st << "=====================" << endl;
    st << "Surgeries\n";
    if (!surgeries.empty()) {
        st << "---------------------" << endl;
        st << left << setw(13) << "Name";
        st << "|";
        st << setw(6) << "Cost" << endl;
        st << "---------------------" << endl;
        for (Surgery item : surgeries) {
            st << left << setw(13) << item.name;
            st << "|";
            st << "$" << setw(6) << item.charge << endl;
            totalCost += item.getCharge();
        }
        st << left << setw(13) << "Total";
        st << "|";
        st << "$" << setw(6) << totalCost << endl;
        st << "---------------------" << endl;
    } else {
        st << "There is no surgery item added yet\n";
    }
    return totalCost;
}

int PatientAccount::printMedicationList(ostream &st) {
    int totalCost = 0;
    st << "=====================" << endl;
    st << "Medications\n";
    if (!medications.empty()) {
        st << "---------------------" << endl;
        st << left << setw(13) << "Name";
        st << "|";
        st << setw(6) << "Cost" << endl;
        st << "---------------------" << endl;
        for (Pharmacy item : medications) {
            st << left << setw(13) << item.name;
            st << "|";
            st << "$" << setw(6) << item.charge << endl;
            totalCost += item.getCharge();
        }
        st << left << setw(13) << "Total";
        st << "|";
        st << "$" << setw(6) << totalCost << endl;
        st << "---------------------" << endl;
    } else {
        st << "There is no surgery item added yet\n";
    }
    return totalCost;
}


