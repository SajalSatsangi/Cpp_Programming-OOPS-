#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string str;
  ofstream copyfile("sajal.txt", ios::out);
  ifstream myfile("state_capital.txt", ios ::in);

  if (myfile.is_open() && copyfile.is_open())
  {
    while (getline(myfile, str))
    {
      int l = str.length();
      for (int i = 0; i < l; i++)
      {
        if (toupper(str[i]) == 'A' || toupper(str[i]) == 'E' || toupper(str[i]) == 'I' || toupper(str[i]) == 'O' || toupper(str[i]) == 'U')
        {
          str.replace(i, 1, "V");
        }
      }
      copyfile << str << endl;
    }
  }
  else
    cout << "File Not Found";

  return 0;
}