#include <iostream>
using namespace std;

int main() {
    double total = 0;
    for (int i=1; i < 99; i+=2) {
        total += static_cast<double>(i) / (i+2);
    }
    cout << "total: " << total << endl;
    return 0;
}case
