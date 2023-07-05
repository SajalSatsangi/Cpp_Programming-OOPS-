#include <iostream>
using namespace std;

int main()
{
  int k = 0;
  string s1 = "234", s2;
  int j = s1.length() - 1;
  for (int i = 0; i <= j; i++)
  {
    k = isalpha(s1[i]);
    if (k != 0)
    {
      cout << "string has alphabets" << endl;
      break;
    }
  }
  if (k == 0)
    cout << "string has only digits" << endl;
}