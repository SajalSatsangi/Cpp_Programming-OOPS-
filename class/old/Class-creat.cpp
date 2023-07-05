#include <iostream>
using namespace std;

class Students
{
  int roll;
  string name;
  double cgpa;

public:
  Students(int roll, string name, double cgpa)
  {
    this->roll = roll;
    this->name = name;
    this->cgpa = cgpa;
  }

  void display()
  {
    cout << "Roll No.: " << roll<< endl << "Name: " << name << endl<< "CGPA: " << cgpa << endl;
  }
};

int main()
{
  Students stu(2104410,"Sajal",9.5);
  stu.display();
}