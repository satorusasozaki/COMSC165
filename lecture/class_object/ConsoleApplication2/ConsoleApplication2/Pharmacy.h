#ifndef Pharmacy_h
#define Pharmacy_h

#include <string>
#include <vector>
#include <ostream>
using std::string;
using std::vector;
using std::ostream;
struct medicationItem {
	string name;
	int charge;
};

class Pharmacy {
public:
	Pharmacy();
	string getName();
	int getCharge();
	void setMedication(ostream & st);
	void printList(ostream & st);
	int index;
private:
	string name;
	int charge;
	vector<medicationItem> items;
	void initList();
};






#endif 


/*
The Pharmacy class
o The Pharmacy class will have stored within it the price of at least 5 types of medication
and the price of each.
o Has get/set methods to get/set the selected medication item for each object
o Has a function that prints a list of types of medications items and their costs
*/