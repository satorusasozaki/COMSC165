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

//	items.at(0).name = "surgery1";
//	items.at(0).charge = 100;
//	items.at(1).name = "surgery2";
//	items.at(1).charge = 200;
//	items.at(2).name = "surgery3";
//	items.at(2).charge = 300;
//	items.at(3).name = "surgery4";
//	items.at(3).charge = 400;
//	items.at(4).name = "surgery5";
//	items.at(4).charge = 500;
}
