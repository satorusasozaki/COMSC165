/***********************************
Problem: Class and Object lab
Description: You are to write a program that computes a patient s bill for a hospital stay.
Name: Satoru Sasozaki
ID: 1516331
Date: 10/22/2015
Status: Complete

Pharmacy.cpp
***********************************/

#include "Pharmacy.h"
#include <string>
#include <vector>
#include <ostream>
using std::string;
using std::vector;
using std::ostream;


Pharmacy::Pharmacy () {
    initList();
}

void Pharmacy::initList() {
    Item s;
    for (int i = 0; i < 5; i++) {
        items.push_back(s);
        items.at(i).name = "medication" + std::to_string(i+1);
        items.at(i).charge = (i+1) * 10;
    }
}
