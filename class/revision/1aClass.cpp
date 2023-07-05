#include <iostream>
using namespace std;

class Student
{
  // access modifier ------> public, private and protectedd

private: // which we define here we can't use it outside the class----> and also it no need to define if don't use any modifier it means it is under private access modifier
  int z;

public: // in the publlic section which we have define we can use it outside the class
  // variable declaration
  int y;
  // function defition()
  // {
  // }

  int a = 20; // instance variable & object level variable

  void myFun(int t)
  {
    int x = 20; // local variable ----> it's life is connected with function call
  }

  void sayHello()
  {
    // cout << x; we couldn't use here
    cout << a; // we can use here because it is a class level variable
  }
};

int main()
{
  int a;

  Student stu; // here stu is reference variable and This methon of genrating object to access a class

  cout << a; //we can't use it without reference variable
  cout << stu.a; // for accessing we have to use reference variable

  return 0;
}