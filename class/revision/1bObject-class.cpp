#include <iostream>
using namespace std;

class Student
{
  int roll;
  string name;

public:
  void setData(int r, string n)
  {
    roll = r;
    name = n;
  }
  void display()
  {
    cout << "Student RollNo : " << roll << " and Name : " << name << endl;
  }
};

int main()
{
  Student stu1, stu2; // stu1 and stu2 are the objects of student class
  
  stu1.setData(101, "Karan");
  stu1.display();
  stu2.display(); // we can't use it without define

  stu2.setData(102, "Aman");
  stu2.display();

  return 0;
}