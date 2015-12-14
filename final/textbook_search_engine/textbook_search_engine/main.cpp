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
    Toggle *case_sensitive = new Toggle(true,"Case sensitive search is now ");
    Toggle and_or();
};


int main() {

    

    return 0;
}