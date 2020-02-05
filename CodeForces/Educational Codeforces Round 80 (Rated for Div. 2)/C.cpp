#define MOD 1000000007
#include <cstdio>
#include <algorithm>
using namespace std;

int f[1005][1005][15], n, m, g[1005][1005][15];
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      f[i][j][1] = 1;
    }
  }
  for (int k = 1; k <= m; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = i; j >= 1; j--) {
        g[i][j][k] = (g[i][j + 1][k] + f[i][j][k]) % MOD;
      }
    }
    for (int j = 1; j <= n; j++) {
      for (int i = j; i <= n; i++) {
        f[i][j][k + 1] = (f[i - 1][j][k + 1] + g[i][j][k]) % MOD;
      }
    }
  }
  printf("%d", f[n][1][m + 1]);
}