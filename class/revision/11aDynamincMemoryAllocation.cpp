#include <iostream>
using namespace std;

class Student
{
  int roll;
  string name;

public:
  Student(int roll, string name)
  {
    this->name = name;
    this->roll = roll;
  }

  void display()
  {

    cout << name << "-" << roll << endl;
  }
};

int main()
{
  // a new method create a objects
  Student *object1 = new Student(2104410, "Karan"); // This is a new method to create a object
  Student *object2 = new Student(2104412, "Aman");
  delete object1; 
  // since c++ does not have a garbage collector, if we don't do that, the next line would cause 
  // a "memory leak", i.e. a piece of claimed memory that the app cannot use
  // and that we have no way to recalim........

  object1 = object2; // same as java here object1 is point to object2

  object1->display();
  object2->display();

  return 0;
}