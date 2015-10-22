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
    
//    items.at(0).name = "medication1";
//    items.at(0).charge = 10;
//    items.at(1).name = "medication2";
//    items.at(1).charge = 20;
//    items.at(2).name = "medication3";
//    items.at(2).charge = 30;
//    items.at(3).name = "medication4";
//    items.at(3).charge = 40;
//    items.at(4).name = "medication5";
//    items.at(4).charge = 50;
}

