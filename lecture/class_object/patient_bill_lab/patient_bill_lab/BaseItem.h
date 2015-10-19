#ifndef BaseItem_h
#define BaseItem_h

#include <string>
#include <vector>
#include <ostream>
using std::string;
using std::vector;
using std::ostream;

struct Item {
    string name;
    int charge;
};

class BaseItem {
public:
    BaseItem();
    string getName();
    int getCharge();
    void setItem(ostream & st);
    void printList(ostream & st);
    int index;
private:
    string name;
    int charge;
    vector<Item> items;
    void initList();
};

#endif