/***********************************
Problem: Class and Object lab
Description: You are to write a program that computes a patient s bill for a hospital stay.
Name: Satoru Sasozaki
ID: 1516331
Date: 10/22/2015
Status: Complete

PatientAccount.cpp
***********************************/

#include "PatientAccount.h"
#include <string>
#include <vector>
#include <iomanip>

using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::left;
using std::right;

PatientAccount::PatientAccount(){
    name = "";
    age = 0;
    address = "";
    ssn = 0;
}

int PatientAccount::getHospitalFee() {
    return HOSPITAL_RATE_PER_DAY * days;
}

void PatientAccount::printDetail(ostream &st) {
    int surgeryCost = 0;
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
            surgeryCost += item.getCharge();
        }
        st << "---------------------" << endl;
        st << left << setw(13) << "Total";
        st << "|";
        st << "$" << setw(6) << surgeryCost << endl;
    } else {
        st << "There is no surgery item added yet\n";
    }
    
    int medicationCost = 0;
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
            medicationCost += item.getCharge();
        }
        st << "---------------------" << endl;
        st << left << setw(13) << "Total";
        st << "|";
        st << "$" << setw(6) << medicationCost << endl;

    } else {
        st << "There is no surgery item added yet\n";
    }
    
    st << "=====================" << endl;
    st << "Hospital" << endl;
    st << "---------------------" << endl;
    st << left << setw(13) << "Days";
    st << "|";
    st << setw(6) << "Cost" << endl;
    st << "---------------------" << endl;
    st << left << setw(13) << days;
    st << "|";
    int hospitalFee = getHospitalFee();
    st << "$" << setw(6) << hospitalFee << endl;
    
    st << "=====================" << endl;
    st << "Overall Total" << endl;
    st << "---------------------" << endl;
    st << "$" << right << setw(20)  << surgeryCost + medicationCost + hospitalFee << endl;
}


