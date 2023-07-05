#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream myfile("sajal.txt", ios::in);

  if (myfile.is_open())
  {
    string str;

    myfile>>str;

    cout<<myfile.tellg();

    myfile.close();
  }
  else
  {
    cout << "file is not found" << endl;
  }

  return 0;
}