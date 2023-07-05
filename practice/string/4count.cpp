#include <iostream>
using namespace std;

int main()
{
  string v = "Sajal Satsangi";
  int i = 0, j, conso = 0, vowel = 0, other = 0;
  j = v.length() - 1;

  for (i = 0; i <= j; i++)
  {
    int alpha = v[i];
    if ((alpha < 97 && alpha > 90) || alpha < 65 || alpha > 122)
      other++;
    else if (alpha == 97 || alpha == 101 || alpha == 105 || alpha == 111 || alpha == 117 || alpha == 65 || alpha == 69 || alpha == 73 || alpha == 79 || alpha == 85)
      vowel++;
    else
      conso++;
  }

  cout << "\nVowel :" << vowel << "\nConsonant : " << conso<< "\nother : " << other ;

  return 0;
}