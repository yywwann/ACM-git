#include <iostream>
#include <stdlib.h>
using namespace std;
int n = 0, m = 0, max = 0, all = 0, num = 0, lot = 0;
int a[1005][1005] = { 0 };
int b[1005]       = { 0 };
int c[1005]       = { 0 };
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      cin >> a[i][j];
      b[i] = b[i] + a[i][j];
      if (j != 0) c[i] = c[i] + a[i][j];
    }
  }
  lot = -c[0], num = 1;
  for (int i = 0; i < n; i++) {
    all  = all + b[i];
    c[i] = -c[i];
    if (lot < c[i]) lot = c[i], num = i + 1;
  }

  cout << all << " " << num << " " << lot;
  return 0;
}