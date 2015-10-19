#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    fstream in("textFile.txt");
    fstream out("out.txt");
    in << "Hello world";
    in.seekg(0,in.end);
    int length = in.tellg();
    cout << length << endl;

    /// -1 needed?
    for (int i=length-1;i>=0;i--) {
            cout <<"i: " << i<< "\t";
        in.seekg(i,ios::beg);
        cout <<"Letter: " << static_cast<char>(in.peek()) << endl;
        out.put(in.peek());
    }




    return 0;
}

