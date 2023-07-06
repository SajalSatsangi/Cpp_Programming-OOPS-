#include <iostream>
using namespace std;

// it is called generic in java

// templates are very powerful feature in c++ because templates allow you to write generic programs. 
// It means we can only write one program that is used for multitple fuctions for different data types.

template <typename T>
void justPrint(T var)
{
  cout << var << endl;
}

int main()
{
  justPrint<int>(10);
  justPrint<char>('k');
  justPrint<double>(2.006);

  return 0;
}

// for multiple parameters

/*
  template <typename T, typename U>
  T someFunction(T arg, U arg)
  {
    ..... ... ....
  }

  int main()
  {
  justPrint<int, double>(10, 2.008)
  }
*/