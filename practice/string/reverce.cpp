#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  string v = "Sajal Satsangi";
  char str[20];
  int i = 0, j;
  j = v.length() - 1;
  while (v[i] != '\0')
  {
    str[j] = v[i];
    i++;
    j--;
  }
  str[i] = '\0';
  cout << str << endl;

  return 0;
}