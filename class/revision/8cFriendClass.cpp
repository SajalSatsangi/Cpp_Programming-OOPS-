/*
class class_Name
{
  declartion of class properties

  friend return_ttpe function_Name(class Name &);
}
*/

// C++ Program to demonstrate the
// functioning of a friend class
#include <iostream>
using namespace std;

class GFG
{
private:
  int private_variable;

protected:
  int protected_variable;

public:
  GFG()
  {
    private_variable = 10;
    protected_variable = 99;
  }

  // friend class declaration
  friend class F;
};

// Here, class F is declared as a
// friend inside class GFG. Therefore,
// F is a friend of class GFG. Class F
// can access the private members of
// class GFG.
class F
{
public:
  void display(GFG &t)
  {
    cout << "The value of Private Variable = " << t.private_variable << endl;
    cout << "The value of Protected Variable = " << t.protected_variable;
  }
};

// Driver code
int main()
{
  GFG g;
  F fri;
  fri.display(g);
  return 0;
}
