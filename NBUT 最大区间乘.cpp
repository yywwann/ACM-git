#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t;
int n;
ll a[100000 + 5];
ll MAX[100000 + 5];
ll MIN[100000 + 5];
ll ans;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    ans = MAX[1] = MIN[1] = a[1];

    for (int i = 2; i <= n; i++) {
      MAX[i] = max(a[i], max(a[i] * MAX[i - 1], a[i] * MIN[i - 1]));
      MIN[i] = min(a[i], min(a[i] * MAX[i - 1], a[i] * MIN[i - 1]));
      ans = max(ans, MAX[i]);
    }
    cout << ans << endl;
  }
  return 0;
}

/*
最大区间乘

MAX[i] 表示以 a[i]为结尾的最大的数
MIN[i] 表示以 a[i]为结尾的最小的数


 */
