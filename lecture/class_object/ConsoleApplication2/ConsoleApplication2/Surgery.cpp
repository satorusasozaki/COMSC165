#include "Surgery.h"
#include <string>
#include <vector>
#include <ostream>
using std::string;
using std::vector;
using std::ostream;

Surgery::Surgery() {
	initList();
	name = "";
	charge = 0;
}

void Surgery::initList() {
	surgeryItem s;
	for (int i = 0; i < 5; i++) {
		items.push_back(s);
	}

	items.at(0).name = "surgery1";
	items.at(0).charge = 100;
	items.at(1).name = "surgery2";
	items.at(1).charge = 200;
	items.at(2).name = "surgery3";
	items.at(2).charge = 300;
	items.at(3).name = "surgery4";
	items.at(3).charge = 400;
	items.at(4).name = "surgery5";
	items.at(4).charge = 500;
}

string Surgery::getName() {
	return name;
}

int Surgery::getCharge() {
	return charge;
}

void Surgery::setSurgery(ostream & st) {
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

void Surgery::printList(ostream & st) {
	int i = 1;
	for (surgeryItem item : items) {
		st << i << ":\n"
			<< "name: " << item.name << endl
			<< "charge: " << item.charge << endl;
	}
}