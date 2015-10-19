#include <iostream>
using namespace std;

int main()
{
    char citys[] =  "Dallas";

    char cityc[] =  {'D', 'a', 'l', 'l', 'a', 's'};//,'\0'};




cout << sizeof (citys) << "\t" << citys << endl;
cout << sizeof (cityc) << "\t" << cityc << endl;

cout << static_cast<int>(citys[6]) << endl;


return 0;
}
