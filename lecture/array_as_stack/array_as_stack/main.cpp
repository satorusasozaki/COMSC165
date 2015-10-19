#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main() {
    
    string transfer;
    int num;
    int size = 0;
    char cont;
    int array[size];

    do {
        cout << "Input a number to push to the stack: ";
        getline(cin,transfer);
        stringstream(transfer) >> num;
        
    size++;
    array[size];
        array[size] = num;
        
    
            for (int i=0; i<size; i++){

                cout << array[i] << endl;
            }
     
        
        cout << "Do you want to continue?: (y / n)";
        getline(cin,transfer);
        stringstream(transfer) >> cont;
    }while(cont=='y');

    
    for (int i=0; i<size; i++){
    //    cout << array[i] << endl;
    }
    
    int buffer[size];
    for (int i=0; i<size; i++){
        
        
    }
    return 0;
    
}