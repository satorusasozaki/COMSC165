#include "Toggle.h"
using std::string;

Toggle::Toggle() {
    
}

Toggle::Toggle(bool status, string s){
    button = status;
    sentence = s;
}

void Toggle::turn() {
    button = !button;
    message = sentence + (button ? "ON" : "OFF");
    
}