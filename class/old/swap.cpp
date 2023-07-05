#include <iostream>
using namespace std;

// void mySwap(int *a, int *b)
// {
//   int c;
//   c = *a;
//   *a = *b;
//   *b = c;
// }

// void mySwap(int a, int b)
// {
//   int c;
//   c = a;
//   a = b;
//   b = c;
// }

// void mySwap2(int &a, int &b)
// {
//   int c;
//   c = a;
//   a = b;
//   b = c;
// }

int main()
{
  int a = 5, b = 7;

  // cout << "Call by value : " << endl;
  // cout << "Before" << a << " " << b << endl;
  // mySwap(a, b);
  // cout << "After" << a << " " << b << endl;

  // cout << "\nCall by address : " << endl;
  // cout << "Before" << a << " " << b << endl;
  // mySwap(&a, &b);
  // cout << "After" << a << " " << b << endl;

  // cout << "\nCall by Reference : " << endl;
  // cout << "Before" << a << " " << b << endl;
  // mySwap2(a, b);
  // cout << "After" << a << " " << b << endl;
  int *g = &a;
  cout << "A" << &a << endl;
 
  int &d = *g;
  cout<< d << endl;
  

  return 0;
}
