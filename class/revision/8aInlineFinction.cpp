// The C++ inline function is called at the compile time by the compiler and copies the code of the function to that inline function call loaction.
// This optimization feature reduces the overhead function calls by replacing the function call with the function code

/*inline return-type function-name(parameters)
{
    // function code
}  */

#include <iostream>
using namespace std;
inline int cube(int s) { return s * s * s; }
int main()
{
  cout << "The cube of 3 is: " << cube(3) << "\n";
  return 0;
}