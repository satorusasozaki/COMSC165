#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct S {
    int var1;
    int var2;
};

struct T {
    int var3;
    vector<S> s;

};


int main() {
    S s(5);
    return 0;

}
