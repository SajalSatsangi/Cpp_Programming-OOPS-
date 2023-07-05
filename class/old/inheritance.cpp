#include <iostream>
using namespace std;

class First
{
private:
  int a = 10;

public:
  int b = 20;

  First()
  {
    cout << "I'm first constructor\n";
  }

  void MyMethod()
  {
    cout << "I'm first class MyMethod";
  }

  void MyFun()
  {
    cout << "I'm first class MyFun";
  }

protected:
  int c = 30;
};

class Second : public First
{
public:
  Second()
  {
    cout <<"I'm second constructor\n";
  }
};

class Third : protected Second
{
public:
  Third()
  {
    cout <<"I'm third constructor\n";
  }
};

int main()
{
  Second stu;
  cout<<stu.b;

  cout<<"\n\n";
  
  Third stud;
//cout<<stud.b;
// third class can't be print first class values cause of protected access modifier
}
