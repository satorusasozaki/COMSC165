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

void BaseItem::printList(ostream &st) {
    int i = 1;
    for (Item item : items) {
        st << i << ". "
        << "name: " << item.name << "\t"
        << "charge: " << item.charge << endl;
        i++;
    }
}