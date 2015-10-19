#include <iostream>
using namespace std;

// Return the max between two numbers
int max(int num1, int num2)
{
return num1 > num2 ? num1 : num2;
}

int main()
{
int i = 5;
int j = 2;
int k = max(i, j);
cout << "The maximum between " << i <<
" and " << j << " is " << k << endl;

return 0;
}
