#include <iostream>
using namespace std;

namespace mySpace
{
  int t = 20;

  class Student
  {
    int roll;
    string name;

  public:
    Student(int roll, string name) : roll(roll), name(name)
    {
    }

    void display()
    {
      cout << name << "-" << roll << endl;
    }
  };
}