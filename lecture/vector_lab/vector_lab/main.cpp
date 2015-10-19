#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

void addToList(vector<string> &list){
    string item;
    cout << " Please add an item on the To Do list\n"
         << " ==> ";
    getline(cin,item);
    list.push_back(item);
}

void showNextItem(const vector<string> &list) {
    if (!list.empty()) {
        cout << " The next item on the To Do list is\n"
        << " ==> " << list.at(0) << endl;
    } else {
        cout << " The list is empty\n";
    }
}

void doThis(vector<string> &list) {
    if(!list.empty()) {
        cout << " OK, time to do this list item:"
        << " ==> " << list.at(0) << endl; //list.begin()
        list.erase(list.begin());
    } else {
        cout << " The list is empty\n";
    }
    
}

void listAllItems(const vector<string> &list) {
    if(!list.empty()) {
        cout << " Here are all the items in the list\n";
        for(string s : list) {
            cout << " " << s << endl;
        }
    } else {
        cout << " The list is empty\n";
    }
}

void save(const vector<string> &list) {
    string fileName;
    fstream out(fileName,ios::out);
    if (out) {
        for (string s : list) {
            out << s << endl;
        }
    } else {
        cout << " The file is failed to open\n";
    }
    out.close();
}

void load(vector<string> &list) {
    string fileName;
    fstream in(fileName,ios::in);
    if (in) {
        string transfer;
        while (getline(cin,transfer)) {
            list.push_back(transfer);
        }
    } else {
        cout << " The file is failed to open\n";
    }
    in.close();
}











int main() {
    vector<string> toDoList;
    int choiceNum;

    do {
        cout << "What to do?\n"
             << "1 Add to the list\n"
             << "2 Show the next item on the list\n"
             << "3 Do the next item on the list and remove it\n"
             << "4 List all items\n"
             << "5 Save list\n"
             << "6 Load list\n"
             << "7 All done with this To Do List!\n"
             << " ==> ";
        
        string transfer;
        getline(cin,transfer);
        stringstream(transfer) >> choiceNum;
        
        switch (choiceNum) {
            case 1: addToList(toDoList);
                break;
            case 2: showNextItem(toDoList);
                break;
            case 3: doThis(toDoList);
                break;
            case 4: listAllItems(toDoList);
                break;
            case 5: save(toDoList);
                break;
            case 6: load(toDoList);
                break;
            case 7: cout << " Goodbye for now.\n";
                break;
            default: cout << "Wrong Number!\n";
                break;
        }
        
    } while (choiceNum != 7);
    
    
}
