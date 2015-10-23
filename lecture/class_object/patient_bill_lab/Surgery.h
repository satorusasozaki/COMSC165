/***********************************
Problem: Class and Object lab
Description: You are to write a program that computes a patient s bill for a hospital stay.
Name: Satoru Sasozaki
ID: 1516331
Date: 10/22/2015
Status: Complete

Surgery.h
***********************************/

#ifndef Surgery_h
#define Surgery_h

#include "BaseItem.h"
#include <string>
#include <vector>
#include <ostream>
using std::string;
using std::vector;
using std::ostream;

class Surgery : public BaseItem {
public:
    Surgery();
private:
    void initList();
};

#endif

/*
 The Surgery class
 o The Surgery class will have stored within it the charges for at least 5 types of surgery
 o Has get/set methods to get/set the selected medication item for each object
 o Has a function that prints a list of types of surgery items and their costs
 */