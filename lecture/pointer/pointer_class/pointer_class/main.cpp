//#include <iostream>
//#include "Course.h"
//using namespace std;
//
//int main()
//{
//    Course course1("Data Structures", 10);
//    Course course2("Database Systems", 15);
//    
//    course1.addStudent("Peter Jones");
//    course1.addStudent("Brian Smith");
//    course1.addStudent("Anne Kennedy");
//    
//    course2.addStudent("Peter Jones");
//    course2.addStudent("Steve Smith");
//    
//    cout << "Number of students in course1: " <<
//    course1.getNumberOfStudents() << "\n";
//    string* students = course1.getStudents();
//    for (int i = 0; i < course1.getNumberOfStudents(); i++)
//        cout << students[i] << ", ";
//    
//    cout << "\nNumber of students in course2: "
//    << course2.getNumberOfStudents() << "\n";
//    students = course2.getStudents();
//    for (int i = 0; i < course2.getNumberOfStudents(); i++)
//        cout << students[i] << ", ";
//    
//    return 0;
//}

#include <iostream>
#include "Course.h"
using namespace std;

int main()
{
    Course course1("C++", 10);
    Course course2(course1);
    
    course1.addStudent("Peter Pan"); // Add a student to course1
    course2.addStudent("Lisa Ma"); // Add a student to course2
    
    cout << "students in course1: " <<
    course1.getStudents()[0] << endl;
    cout << "students in course2: " <<
    course2.getStudents()[0] << endl;
    
    // both are lisa ma
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}






