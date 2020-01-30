#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define N 998244353
using namespace std;


int n, len1, len7, len9;
inline int read()
{
  int x = 0; char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48),
    ch                             = getchar();
  return x;
}

int main()
{
  int T = read();
  while (T--)
  {
    n    = read();
    len1 = min(N, n / 2);
    n   -= len1 * 2;
    len7 = min(N, n);
    n   -= len7;
    len9 = min(N, n / 3);
    for (int i = 1; i <= len9; i++) putchar('9');
    for (int i = 1; i <= len7 - len9; i++) putchar('7');
    for (int i = 1; i <= len1 - len7; i++) putchar('1');
    putchar('\n');
    len1 = 0;
    len7 = 0;
    len9 = 0;
  }
}