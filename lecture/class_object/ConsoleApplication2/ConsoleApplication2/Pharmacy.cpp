#include "Pharmacy.h"
#include <string>
#include <vector>
#include <ostream>
using std::string;
using std::vector;
using std::ostream;

Pharmacy::Pharmacy() {
	initList();

}

void Pharmacy::initList() {
	medicationItem m;
	for (int i = 0; i < 5; i++) {
		items.push_back(s);
	}

	items.at(0).name = "medication1";
	items.at(0).charge = 10;
	items.at(1).name = "medication2";
	items.at(1).charge = 20;
	items.at(2).name = "medication3";
	items.at(2).charge = 30;
	items.at(3).name = "medication4";
	items.at(3).charge = 40;
	items.at(4).name = "medication5";
	items.at(4).charge = 50;
}

string Pharmacy::getName() {
	return name;
}

int Pharmacy::getCharge() {
	return charge;
}

void Pharmacy::setMedication(ostream & st) {
	switch (index) {
	case 1: name = items.at(0).name;
		charge = items.at(0).charge;
		break;
	case 2: name = items.at(1).name;
		charge = items.at(1).charge;
		break;
	case 3: name = items.at(2).name;
		charge = items.at(2).charge;
		break;
	case 4: name = items.at(3).name;
		charge = items.at(3).charge;
		break;
	case 5: name = items.at(4).name;
		charge = items.at(4).charge;
		break;
	default:
		st << "Wrong number\n";
	}
}

void Pharmacy::printList(ostream & st) {
	int i = 1;
	for (medicationItem item : items) {
		st << i << ":\n"
			<< "name: " << item.name << endl
			<< "charge: " << item.charge << endl;
	}
}