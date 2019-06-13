#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
const ll INF = 0x3f3f3f3f;
int T;
int n, m;
ll a[N], b[N], c;
ll ans, dp[2*N];
int main() {
  cin >> T;
  while (T--) {

    cin >> n >> m >> c;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    for (int i = 0; i < 2*N; i++) dp[i] = INF;
    dp[0] = 0;
    ans = INF;

    for (int i = 1; i <= m; i++) {
      for (int j = a[i]; j < 2*N; j++) {
        dp[j] = min(dp[j], dp[j-a[i]] + b[i]);
      }
    }
    for (int i = 1; i < 2*N; i++) {
      dp[i] = min(dp[i], dp[i-1] + c);
    }
    for (int i = n; i < 2*N; i++) {
      ans = min(ans, dp[i]);
    }
    cout << ans << endl;
  }
}
