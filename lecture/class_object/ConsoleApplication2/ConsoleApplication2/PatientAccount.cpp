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

void PatientAccount::printItems(ostream &st) {
	int totalCost;
	st << "Surgery\n";
	for (Surgery item : surgeries) {
        st << "name" << item.getName() << endl
        << "cost" << item.getCharge() << endl;
		totalCost += item.getCharge();
	}

	st << "Medications\n";
	for (Pharmacy item : medications) {
		st << "name" << item.getName() << endl
			<< "cost" << item.getCharge() << endl;
		totalCost += item.getCharge();
	}

	st << "Total Cost: " << totalCost << endl;
}











