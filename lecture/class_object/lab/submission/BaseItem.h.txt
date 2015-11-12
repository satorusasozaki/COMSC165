/***********************************
Problem: Class and Object lab
Description: You are to write a program that computes a patient s bill for a hospital stay.
Name: Satoru Sasozaki
ID: 1516331
Date: 10/22/2015
Status: Complete

BaseItem.h
***********************************/

#ifndef BaseItem_h
#define BaseItem_h

#include <string>
#include <vector>
#include <ostream>
using std::string;
using std::vector;
using std::ostream;
using std::endl;

class BaseItem {
public:
    BaseItem();
    string getName();
    int getCharge();
    void setItem(ostream & st);
    void printList(ostream & st);
    struct Item {
        string name;
        int charge;
    };
    int index;
    string name;
    int charge;
    vector<Item> items;
};

#endif