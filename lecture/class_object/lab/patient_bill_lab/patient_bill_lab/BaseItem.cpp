/***********************************
Problem: Class and Object lab
Description: You are to write a program that computes a patient s bill for a hospital stay.
Name: Satoru Sasozaki
ID: 1516331
Date: 10/22/2015
Status: Complete

BaseItem.cpp
***********************************/

#include "BaseItem.h"
#include <string>
#include <vector>
#include <ostream>
using std::string;
using std::vector;
using std::ostream;
using std::endl;

BaseItem::BaseItem() {
    name = "";
    charge = 0;
}

string BaseItem::getName() {
    return name;
}

int BaseItem::getCharge() {
    return charge;
}

void BaseItem::setItem(ostream &st) {
    if (0<index && index <= 5) {
        name = items.at(index-1).name;
        charge = items.at(index-1).charge;
    } else {
        st << "Wrong number\n";
    }
}

void BaseItem::printList(ostream &st) {
    int i = 1;
    for (Item item : items) {
        st << i << ". "
        << "name: " << item.name << "\t"
        << "charge: " << item.charge << endl;
        i++;
    }
}