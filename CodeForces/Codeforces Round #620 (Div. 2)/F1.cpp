#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e4 + 1000;
const ll  INF  = 0x3f3f3f3f3f3f3f3f;
int a[55][maxn];
int dp[55][maxn];
int la[maxn], ra[maxn];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      a[i][j] += a[i][j - 1];
    }
    for (int j = 1; j <= k; j++) a[i][m + j] = a[i][m];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      la[j] = ra[j] = 0;
    }
    for (int j = k + 1; j <= m; j++) {
      la[j] = max(la[j - 1], dp[i - 1][j - k]);
    }
    for (int j = m; j >= 0; j--) {
      ra[j] = max(ra[j + 1], dp[i - 1][j + k]);
    }
    for (int j = 1; j <= m; j++) {
      dp[i][j] = a[i][j + k - 1] - a[i][j - 1] + a[i + 1][j + k - 1] -
                 a[i + 1][j - 1];
      dp[i][j] += max(la[j], ra[j]);

      // cout<<"dp"<<i<<" "<<j<<" "<<dp[i][j]<<endl;
      int l = max(1, j - k + 1), r = min(m, j + k - 1);

      // cout<<l<<" "<<r<<endl;
      for (int x = l; x <= r; x++) {
        if (x <= j) {
          dp[i][j] =
            max(dp[i][j],
                dp[i - 1][x] +
                (a[i][j + k - 1] - a[i][j - 1] + a[i + 1][j + k - 1] -
                 a[i + 1][j - 1]) -
                (a[i][x + k - 1] - a[i][j - 1]));

          // cout<<"x"<<x<<"
          // "<<dp[i-1][x]+(a[i][j+k-1]-a[i][j-1]+a[i+1][j+k-1]-a[i+1][j-1])-(a[i][x+k-1]-a[i][j-1])<<endl;
        }
        else {
          dp[i][j] =
            max(dp[i][j],
                dp[i - 1][x] +
                (a[i][j + k - 1] - a[i][j - 1] + a[i + 1][j + k - 1] -
                 a[i + 1][j - 1]) -
                (a[i][j + k - 1] - a[i][x - 1]));

          // cout<<"x"<<x<<"
          // "<<dp[i-1][x]+(a[i][j+k-1]-a[i][j-1]+a[i+1][j+k-1]-a[i+1][j-1])-(a[i][j+k-1]-a[i][x-1])<<endl;
        }
      }

      // cout<<"dp"<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    }
  }
  int ma = -1000000;
  for (int i = 1; i <= m; i++) {
    ma = max(dp[n][i], ma);
  }
  cout << ma << endl;


  return 0;
}