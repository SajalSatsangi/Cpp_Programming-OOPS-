#include <iostream>
using namespace std;

class First
{
public:
  void saySomething()
  {
    cout << "I am first" << endl;
  }
};

class Second
{
public:
  void saySomething()
  {
    cout << "I am Second" << endl;
  }
};

template <class T>
class Handler
{
public:
  void callMethod(T &obj)
  {
    obj.saySomething();
  }
};

int main()
{
  First first;
  Second second;

  Handler<First> hd1;
  Handler<Second> hd2;

  hd1.callMethod(first);
  hd2.callMethod(second);

  return 0;
}