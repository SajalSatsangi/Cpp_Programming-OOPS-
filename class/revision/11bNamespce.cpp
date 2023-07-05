#include <iostream>
// using namespace std; // when we don't use it  // it is called using directive
// in place of std we can use the name of our namespace;
// std is the standard library namspace

// creation of namespace

// namespace myNamespace
// {
// it is also use a nested namespace
// it can only be use like global or in a another namespace

// function etc......

// it also can use like another file and you can include that in this file.
// } // namespace myNamespace

// Example
namespace mySpace
{
  int t = 20;

  void myFun()
  {
    std::cout << "hello world" << std::endl;
  }
}

int main()
{
  //  In c++ we use name space with std;

  // std::cout << "Hello World";

  mySpace ::myFun();
  return 0;
}

// using std:: cout; // using by declaration