#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream in("/Users/satoru/Dropbox/COMSC165/lecture/Files/file_read_reverse/file_read_reverse/textFile.txt");
    fstream out("/Users/satoru/Dropbox/COMSC165/lecture/Files/file_read_reverse/file_read_reverse/out.txt");

/*
    fstream in;
    fstream out;
    in.open("/Users/satoru/Dropbox/COMSC165/lecture/Files/file_read_reverse/file_read_reverse/textFile.txt",ios::in);
    out.open("/Users/satoru/Dropbox/COMSC165/lecture/Files/file_read_reverse/file_read_reverse/out.txt",ios::out);
*/
    if (in && out) {
        in << "Hello world";
        in.seekg(0,in.end);
        int length = in.tellg();
        cout << length << endl;
        length += 2;
        for (int i=length;i>0;i--) {
            cout <<"i: " << i<< "\t";
            cout << 'a' << endl;
            in.seekg(i,ios::beg);
            cout <<"Letter: " << static_cast<char>(in.peek()) << endl;
            out.put(in.peek());
        }

    } else {
        cout << "File failed to open\n";
    }

    in.close();
    out.close();

    return 0;
}
