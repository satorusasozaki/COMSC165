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
