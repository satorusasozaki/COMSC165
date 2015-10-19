// This program demonstrates reading from one file and writing
// to a second file.
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>	// Needed for the toupper function.
using namespace std;

int main()
{
   string fileName;		// To hold the file name
   char ch;			// To hold a character

   ifstream inFile;		// Input file
   ofstream outFile("out.txt"); // Open a file for output.

   // Get the input file name.
   cout << "Enter a file name: ";
   getline(cin, fileName);

   // Open the file for input.
   inFile.open(fileName);

   // If the input file opened successfully, continue.
   if (inFile)
   {
       // Read a char from file 1.


       // While the last read operation was
       // successful, continue.
       int indexIn = 0;
       int indexOut = 0;
       while (inFile)
       {

        inFile.seekg (indexIn, inFile.end);
        inFile.get(ch);

        //outFile.seekp (indexOut, outFile.beg);
        outFile.put(ch);

        indexIn++;
        //indexOut++;
       }

       inFile.close();
       outFile.close();
       cout << "File conversion done.\n";
   }
   else
      cout << "Cannot open " << fileName << endl;
   return 0;
}
