#include <iostream>
using namespace std;

//INHERITENCE---->>> the capability if a class to inherite the other class is called inheritence

class Parent
{
  int t = 20; // private property can not be inherite.

public:
  int x = 30;
  void sayHello(string name)
  {
    cout << "Hello" << name << endl;
  }
  void saySomething()
  {
    cout << "Bye Bye" << endl;
  }

protected:
  int y = 40;
};

class Child
{
  int a = 20;

public:
  int b = 30;
  void myFun()
  {
    cout << "I'm child" << endl;
  }
};

// we can use parent class propeties in child class and also use ago after making object or if any other class will inherite it so we can use it there also.
class Child1 : public Parent
{
  int a = 20;

public:
  int b = 30;
  void myFun()
  {
    cout << "I'm child" << endl;
  }
};

// we can use parent class propeties in child class but now it become private so it can only use in only this class.
class Child2 : private Parent
{
  int a = 20;

public:
  int b = 30;
  void myFun()
  {
    cout << "I'm child" << endl;
  }
};

// we can use parent class propeties in child class and in those class which will inherite this class but it can't be use outside the class beacause all properties will become proteccted.
class Child2 : protected Parent
{
  int a = 20;

public:
  int b = 30;
  void myFun()
  {
    cout << "I'm child" << endl;
  }
};

int main()
{
  Child cobj;
  cobj.myFun();
  // cobj.saySomething();  ----> we can't use it because this is a function of parent class and it hasn't inherited.

  Child1 cobj1;
  cobj1.myFun();
  cobj1.saySomething(); // ----> we can use it because this is a function of parent class and it has inherited in the child1 class.

  return 0;
}

// we can inherite the puclic and protected properties but we can't inherite the private properties
// protected properties can only be use in the inherited class but public can also be use outside the class. 