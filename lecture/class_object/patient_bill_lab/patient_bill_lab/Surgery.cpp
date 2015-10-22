#include "Surgery.h"
#include <string>
#include <vector>
#include <ostream>
using std::string;
using std::vector;
using std::ostream;

Surgery::Surgery () {
    initList();
}

void Surgery::initList() {
    Item s;
    for (int i = 0; i < 5; i++) {
        items.push_back(s);
        items.at(i).name = "surgery" + std::to_string(i+1);
        items.at(i).charge = (i+1) * 100;
    }
}