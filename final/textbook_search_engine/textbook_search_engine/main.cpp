#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Toggle.h"
using namespace std;

struct Toggles {
    // Compiler misunderstand this code is a function definition
    // Toggle case_sensitive(bool b,string s);
//    Toggle case_sensitive(true,"Case sensitive search is now ");
    
    // This is the only way to create class object in struct
    Toggle *case_sensitive = new Toggle(true, "Case sensitive search is now ");
    Toggle *and_or = new Toggle(true, "AND/OR search is now ");
    Toggle *ranking = new Toggle(false, "Ranking search is now ");
};


int main() {
    Toggles toggles;
    
    Toggle a(true,"this is test");
    cout << a.button << endl;
    cout << a.sentence << endl;
    cout << toggles.case_sensitive->button << endl;

    

    return 0;
}