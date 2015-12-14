#ifndef TOGGLE_H
#define TOGGLE_H
#include <string>
using std::string;


class Toggle {
public:
    bool button;
    string sentence;
    string message;
    Toggle();
    Toggle(bool status, string s);
    void turn();
    ~Toggle();
};




#endif // TOGGLE_H