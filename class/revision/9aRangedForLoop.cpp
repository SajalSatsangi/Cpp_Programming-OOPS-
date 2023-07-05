#include <iostream>
using namespace std;

int main()
{
  int num[] = {1, 3, 2, 6, 5, 2};
  int n = 6;
  int *ptr;
  int *a, *b;

  for (int i = 0; i < n - 1; i++)  // Loop through the array elements
  {
    ptr = num;
    cout << *ptr << endl;
    for (int j = 0; j < n - i - 1; j++)  // Compare adjacent elements and swap if necessary
    {
      a = ptr;
      ptr++;
      if (*a > *ptr)
      {
        int c = *a;
        *a = *ptr;
        *ptr = c;
      }
    }
    for (int k = 0; k < n; k++)  // Print the current state of the array
    {
      cout << num[k] << " ";
    }
    cout << endl;
  }

  return 0;
}
