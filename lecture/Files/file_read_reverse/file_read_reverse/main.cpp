#include <iostream>
#include <fstream>
using namespace std;

int main() {
        fstream in("/Users/satoru/Dropbox/COMSC165/lecture/Files/file_read_reverse/file_read_reverse/textFile.txt");
        fstream out("/Users/satoru/Dropbox/COMSC165/lecture/Files/file_read_reverse/file_read_reverse/out.txt");
    
// This does not work only in Xcode
//    fstream in;
//    fstream out;
//    in.open("/Users/satoru/Dropbox/COMSC165/lecture/Files/file_read_reverse/file_read_reverse/textFile.txt",ios::in);
//    out.open("/Users/satoru/Dropbox/COMSC165/lecture/Files/file_read_reverse/file_read_reverse/out.txt",ios::out);
    
    if (in && out) {
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
    } else {
        cout << "File failed to open\n";
    }
    return 0;
}
