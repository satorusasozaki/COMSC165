#include <iostream>
#include <string>
using namespace std;

int main()
{
    int count = 5;
    int *pCount = &count;
    // Init *pCount with &count which is the memory address where the 5 is located
    // Now *pCount is 5
    // pCount is 0x7fff5fbff6c8 where the 5 is located
    // (This address is different everytime you allocate the memory)

    cout << "The value of count is " << count << endl;
    // Print 5

    cout << "The address of count is " << &count << endl;
    // Print 0x7fff5fbff6c8 which is the memory address of variable count holoding 5

    cout << "The address of count is " << pCount << endl;
    // Print 0x7fff5fbff6c8 which is the memory address taken from variable count holoding 5

    cout << "The value of count is " << *pCount << endl;
    // Print 5 pointed to by 0x7fff5fbff6c8

    // If you do not have anything to initialize the pointer variable with, then initialize with nullptr
    // http://stackoverflow.com/questions/1282295/what-exactly-is-nullptr
    int *n = nullptr;

    // Print n which is "0x0"
    cout << n << endl;

    return 0;
}
