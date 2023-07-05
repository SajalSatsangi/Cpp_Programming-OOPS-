#include <iostream>
using namespace std;

int main()
{
  string str;
  cout << "enter a string: ";
  getline(cin, str);
  int j = str.length() - 1;
  int n = j;
  for (int i = 0; i <= n / 2; i++)
  {
    swap(str[i], str[j]);
    j--;
  }
  cout << str;
  return 0;
}