#include <iostream>
using namespace std;

// class Hello
// {
// public:
//   void myFun()
//   {
//     int t = 10;
//     cout << t << endl;
//     t++;
//   }
// };

// output---> 10,10,10

class Hello
{
  int t = 10;

public:
  void myFun()
  {
    cout << t << endl;
    t++;
  }
};

// output---> 10,11,12

int main()
{
  // Hello hobj;

  // hobj.myFun();
  // hobj.myFun();
  // hobj.myFun();

  Hello obj1, obj2, obj3;
  obj1.myFun();
  obj2.myFun();
  obj3.myFun();

  // output --> 10,10,10
  return 0;
}