#include <iostream>
using namespace std;
#define ll long long
ll n;
string s;
ll     dp[4];
ll     a[100005];
int main() {
  cin >> n >> s;

  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++) {
    if (s[i] == 'h') {
      dp[0] += a[i];
    }

    if (s[i] == 'a') {
      dp[1] = min(dp[0], dp[1] + a[i]);
    }

    if (s[i] == 'r') {
      dp[2] = min(min(dp[0], dp[1]), dp[2] + a[i]);
    }

    if (s[i] == 'd') {
      dp[3] = min(min(dp[0], min(dp[1], dp[2])), dp[3] + a[i]);
    }
  }
  cout << dp[3] << endl;
}
