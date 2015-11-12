// This program demonstrates a simple append
// operation on a linked list.
#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
    // Define a NumberList object.
    NumberList list;
    
    // Append some values to the list.
    
    cout << "First list" << endl;
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);
    list.displayList();
    
    cout << "after 3 inserted" << endl;
    list.insertNode(3);
    list.displayList();
    
    cout << "after 1 inserted" << endl;
    list.insertNode(1);
    list.displayList();
    
    cout << "after 2 inserted" << endl;
    list.insertNode(2);
    list.displayList();
    
    return 0;
}