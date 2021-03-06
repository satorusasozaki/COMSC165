
/********************************************************************************************************
Problem: Loops lab 2 (Encryption and decryption)
Description:
(Enforcing Privacy with Cryptography) The explosive growth of Internet communications
and data storage on Internet-connected computers has greatly increased privacy concerns.
The field of cryptography is concerned with coding data to make it difficult (and hopefully�with the most
advanced schemes�impossible) for unauthorized users to read.

In this exercise you�ll investigate a simple scheme for encrypting and decrypting data. A company that
wants to send data over the Internet has asked you to write a program that will encrypt it so that it
may be transmitted more securely. All the data is transmitted as four-digit integers. Your application
should read a four-digit integer entered by the user and encrypt it as follows: Replace each digit with
the result of adding 7 to the digit and getting the remainder after dividing the new value by 10.
Then swap the first digit with the third, and swap the second digit with the fourth. Then print the
encrypted integer. Write a separate application that inputs an encrypted four-digit integer and decrypts
it (by reversing the encryption scheme) to form the original number.

[Optional reading project: Research �public key
cryptography� in general and the PGP (Pretty Good Privacy) specific public key scheme. You may
also want to investigate the RSA scheme, which is widely used in industrial-strength applications.]

Name: Satoru Sasozaki
ID: 1516331
Date: September 16
Status: Complete
********************************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	string s;
	int num;
	vector <int> numvec;

    cout << "Input a encrypted number: " << endl;
    getline(cin, s);
    stringstream(s) >> num;

    for (num; num > 0; num /= 10)
    {
        numvec.push_back(num % 10);
    }


    for (int i = 0; i < numvec.size(); i++)
    {

        if (numvec.at(i) > 7)
        {

        numvec.at(i) = (numvec.at(i) - 7);
        }

        else
        {
        numvec.at(i) = (10 + numvec.at(i) - 7);
        }
    }

    cout << "\nThe original number is: " << endl;

    for (int i = 0; i < numvec.size(); i++)
    {
        cout << numvec.at(i);
    }
    cout << endl;



	return 0;
}
