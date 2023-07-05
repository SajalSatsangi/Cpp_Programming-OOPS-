#include <iostream>
using namespace std;

int t = 30;

class Hello
{
public:
  void myFun()
  {
    cout << "Hello fun" << endl;
  }
  void myMethod()
  {
    cout << "Hello myMethod" << endl;
  }
};

class Bye : public Hello
{
public:
  void saysomething()
  {
    cout << "Bye" << endl;
  }

  void myMethod ()
  {
    cout << "Bye MyMethod";
  }
};

class First
{
private:
  int a = 10;

public:
  int b = 20;

  // static variable use foe class level variable
  // we can use static method also
  static string clgname;

  First()
  {
    cout << "I'm first constructor\n";
  }

  // return type classname :: functionname (parameters) ---->method
  // declare of class is outside the class
  void MyMethod()
  {
    cout << "I'm first class MyMethod" << endl;
  }

  void MyFun();

protected:
  int c = 30;
};

void First ::MyFun() //method override
{
  cout << "I'm first class MyFun" << endl;
}

string First ::clgname = "DEI";

int main()
{
  int t = 20;
  First stu;
  First stu1;
  cout << stu.b;
  cout << endl;
  stu.MyFun();
  cout << "value of t =" << t << endl;
  cout << "value of t =" << ::t << endl;

  // access of static variable
  cout << stu.clgname << endl;
  cout << stu1.clgname << endl;
  cout << First::clgname << endl;

  Hello hobj;
  Bye bobj;

  bobj.myFun();
  bobj.myMethod();
  bobj.saysomething();
}