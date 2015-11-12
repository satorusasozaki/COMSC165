#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main () {


    int vals[] = {4,7,11};
    // Vals holds 4's memory address, which is 0x7fff570dfbac
    int *valptr = vals;
    // Assign 0x7fff570dfbac (4's memory address) to *valptr which is a pointer variable
    // Now, *valptr is equal to 4 not 0x7fff570dfbac, and valptr is equal to 0x7fff570dfbac

    cout << vals << endl;
    // Print 0x7fff570dfbac (4's memory address)
    cout << *valptr << endl;
    // Print 4

    // Remember valptr stands for 0x7fff570dfbac (4's memory address)
    valptr++; // point at 7
    // This means that the increment change the current address value where 4 is located
    // to the next address value in which 7 is located
    // Note that the change is done by each size of the data type allocated in memory,
    // but not every single memory block

    cout << *valptr << endl;
    // Print 7

    valptr--; // point at 4;
    cout << *valptr << endl;
    // Print 4

    valptr+=2;
    cout << *valptr << endl;
    // Print 11

    valptr-=1;
    cout << *valptr << endl;
    // Print 7

    valptr+=2;
    cout << valptr << endl;
    // Print 0x7fff579f6bb8
    cout << *valptr << endl;
    // Print -395897676 which is a garbage value,
    // because 0x7fff579f6bb8 is out of the memory block allocated for vals array

    return 0;


}
