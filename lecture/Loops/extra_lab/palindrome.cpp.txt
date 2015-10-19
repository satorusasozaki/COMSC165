/***
Problem:
Checking Palindromes

Description:
A string is a palindrome if it reads the same forward and backward. The words Òmom,Ó Òdad,Ó and Ònoon,Ó for example,
are palindromes.

Name: Satoru Sasozaki
ID: 1516331
Date: September 19

Status: Complete

***/


#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter a string: ";
    string s;
    getline(cin, s);

    bool isPalindrome = true;
    int count_from_left = 0;
    int count_from_right = s.size()-1;
    int half_point = s.size() / 2;
    while(isPalindrome && count_from_left <= half_point){

        if(s.at(count_from_left) == s.at(count_from_right)) {
            isPalindrome = true;
        } else {
            isPalindrome = false;
        }
        count_from_right--;
        count_from_left++;
    }

    if(isPalindrome) {
        cout << s << " is a palindrome" << endl;
    } else {
        cout << s << " is not a palindrome" << endl;
    }

  return 0;
}

