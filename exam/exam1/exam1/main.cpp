#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const string RLE_EXT = ".RLE.txt";

string askFileName(){
    string fileName;
    cout << "input a file name including extension: ";
    getline(cin,fileName);
    return fileName;
}

string createNewName(string fileName) {
    //remove .txt extension from the original file name
    string tempName = fileName.substr(0,fileName.size()-4);
    //combine the name created above code with .RLE.txt
    string newName = tempName + RLE_EXT;
    return newName;
}

void compressFile(string inputFileName, string outputFileName) {
    fstream in(inputFileName, ios::in);
    fstream out(outputFileName, ios::out);
    if(in && out) {
        string s;
        while(getline(in,s)) {
            int counter =1;
            cout << "size: "<<s.size() << endl;
            
            for (int i=0; i < s.size()-1; i++){
                cout << "i: "<<i << "\t";
                if( s.at(i+1) != s.at(i) ){
                    out << s.at(i);
                    out << counter;
                    counter = 1;
                }else {
                    counter++;
                }
                
                if (i == s.size()-2) {
                    out << s.at(i+1);
                    out << counter;
                }
                cout << "counter: " << counter << endl;


            }
            out << endl;
        }
        cout << "The file has been compressed\n";
    } else {
        cout << "The file does not exist\n";
    }
}

int main() {
    
    string fileName = askFileName();
    string newName = createNewName(fileName);
    compressFile(fileName,newName);
    
}