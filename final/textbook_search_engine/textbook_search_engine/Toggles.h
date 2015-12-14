#ifndef TOGGLES_H
#define TOGGLES_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Switch {
public:
    bool button;
    std::string on_off;
    std::string sentence;
    std::string message;
    Switch() {
    }
    Switch(bool turn, std::string s) {
        on_off = turn;
        sentence = s;
    }
};

class Toggles {
public:
    Switch case_sensitive;
    Switch and_or;
    Switch ranking;
    Toggles();
    void turnToggle(Switch &toggle);
    ~Toggles();
    // don't forget to implement
};


#endif //TOGGLES_H