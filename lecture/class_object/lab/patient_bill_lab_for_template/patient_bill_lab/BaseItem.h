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