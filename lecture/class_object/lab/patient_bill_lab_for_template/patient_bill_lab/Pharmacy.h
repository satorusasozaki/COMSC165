#ifndef Pharmacy_h
#define Pharmacy_h

#include "BaseItem.h"
#include <string>
#include <vector>
#include <ostream>
using std::string;
using std::vector;
using std::ostream;

class Pharmacy : public BaseItem {
public:
    Pharmacy();
private:
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