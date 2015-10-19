#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream theFile ("file.txt",ios::out);
    
    theFile << "Hello world" << endl;
    
    
    
    return 0;
}