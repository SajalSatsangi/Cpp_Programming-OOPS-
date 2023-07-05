#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{

  ifstream input;
  size_t pos;
  string line;

  input.open("sajal.txt");
  if (input.is_open())
  {
    while (getline(input, line))
    {
      pos = line.find("hey");
      if (pos != string::npos) // string::npos is returned if string is not found
      {
        cout << "Found!";
        break;
      }
    }
  }

  system("pause");
}
