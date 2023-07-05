#include <iostream>
using namespace std;

class Student
{
  int roll;
  string name;
  double cgpa;

public:
  // Student(int r, string n, double c)  //we should use name relevant for standard practice so we can't use r,n and c here
  // {
  //   roll = r;
  //   name = n;
  //   cgpa = c;
  // }

  // Student(int roll, string name, double cgpa)  //we should use name relevant for standard practice
  // {
  //   roll = roll;  // here the function always give priority to it's local variable so we can't use like it so we use a this pointer
  //   name = name;
  //   cgpa = cgpa;
    
  // }

  Student(int roll, string name, double cgpa) // we should use roll,name and cgpa
  {
    this->roll = roll;  //use of this pointer --> this use to refere the instance variable when our local and instance variable name are same
    this->name = name;  // this is a pointer variable which refers a current object as a refernce variable
    this->cgpa = cgpa;  // we can say this is also a type of reference variable
  }

  string getName()
  {
    return name;
  }

  void display()
  {
    cout << "Roll No.: " << roll << ", Name: " << name << " and CGPA: " << cgpa << endl;
  }
};

int main()
{
  Student stu1(101, "Karan Sharma", 8.9);
  Student stu2(102, "Aman Verma", 7.6);

  stu1.display();
  stu2.display();

  return 0;
}