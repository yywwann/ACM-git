#include <iostream>
#include <string>
using namespace std;
int findMin(string s)
{
  int len = s.length();
  int i = 0, j = 1, k = 0;

  while (i < len && k < len && j < len)
  {
    if (s[(i + k) % len] == s[(j + k) % len])
    {
      k++;
    }
    else if (s[(i + k) % len] > s[(j + k) % len])
    {
      i = i + k + 1;
      k = 0;
    }
    else
    {
      j = j + k + 1;
      k = 0;
    }

    if (i == j) j++;
  }
  return min(i, j);
}

int main()
{
  int n;
  string s;

  cin >> n;
  cin >> s;
  int t = findMin(s) + 1;

  if (t == 1) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}

///das
