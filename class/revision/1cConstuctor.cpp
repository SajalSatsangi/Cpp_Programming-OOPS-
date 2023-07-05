#include <iostream>
using namespace std;

class Student
{
  int roll;
  string name;

public:
  Student(int r, string n) // it calls just after creating object , it doesn't have data type, it's name always same as class name
  {
    roll = r;
    name = n;
  }
  string getname()
  {
    return name;
  }
  void display()
  {
    cout << "Student RollNo : " << roll << " and Name : " << name << endl;
  }
};

int main()
{
  // Student stu1; // we can't define object like it because here it calls consturctor just after creating object
  // stu1.display();

  Student stu1(101, "Karan"); // we have to create object like it because we are using constructor
  Student stu2(102, "Aman");
  stu1.display();
  stu2.display();

  return 0;
}