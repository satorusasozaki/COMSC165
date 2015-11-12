#include <iostream>
using namespace std;

int main () {
    int temp = 1;
    int current = 4;
    cout << current << endl;
    int previous = 0;
    while (current < 97) {
        previous = temp;
        temp = current;
        current += previous;
        cout << current << endl;
    }
    return 0;
}
