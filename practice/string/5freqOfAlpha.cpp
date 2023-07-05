#include <iostream>
using namespace std;

int main()
{
  string v = "Sajal Satsangi Deepak Kumar";
  int i = 0, j, count, HighFerq = 0;
  char HighFreqAlpha;
  j = v.length() - 1;
  for (i = 0; i <= j; i++)
  {
    count = 1;
    char alpha = v[i];
    for (int k = i + 1; k <= j; k++)
    {
      if (alpha == v[k])
        count++;
    }
    if (HighFerq < count)
    {
      HighFerq = count;
      HighFreqAlpha = v[i];
    }
  }

  cout <<HighFreqAlpha<<" : "<< HighFerq;

  return 0;
}