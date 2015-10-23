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