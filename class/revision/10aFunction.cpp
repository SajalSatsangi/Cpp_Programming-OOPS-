#include <iostream>
using namespace std;

void sayHello(string name = "Human") // defining the default parameter
{
  // here human is the default value in the function it only valid when you don't pass the parameter
  cout << "Hello " << name << endl;
}

void sum(int a, int b = 0, int c = 0) // here we have to pass the one value because we didn't initialize the a
{
  cout << a + b + c << endl;
}

void mySwap(int a, int b)
{
  int c = a;
  a = b;
  b = c;
}

void mySwap(int *a, int *b)
{
  int c = *a;
  *a = *b;
  *b = c;
}

void mySwap2(int &a, int &b)
{
  int c = a;
  a = b;
  b = c;
}

void myFun(int xyz[], int n)
{
  for (int i = 0; i < n; i++)
  {
    xyz[i] = xyz[i] + 5;
  }
}

void myDisplay(int xyz[], int n)
{
  cout << "\nArray Elements: ";
  for (int i = 0; i < n; i++)
  {
    cout << xyz[i] << " ";
  }
}

int main()
{
  // sayHello();        // here print default value
  // sayHello("Karan"); // here print karan

  // sum(10);
  // sum(10, 20);
  // sum(10, 20, 30);

  // int a = 5, b = 7;

  // cout << "Before: Value of A: " << a << " and Value of B: " << b << endl;
  // mySwap(a, b); // call by value
  // cout << "Before: Value of A: " << a << " and Value of B: " << b << endl;
  // mySwap(&a, &b); // call by address
  // cout << "Before: Value of A: " << a << " and Value of B: " << b << endl;
  // mySwap2(a, b); // call by reference

  int arr[] = {24, 85, 67, 54, 32, 98, 32};
  int n = 7;

  myDisplay(arr, n);
  myFun(arr, n);
  myDisplay(arr, n);

  return 0;
}