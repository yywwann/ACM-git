#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 2e18;    //   | |     |  _  |   V /
const ll N   = 1e5 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

#define random(x) (rand() % x + 1)
ll n, k;
ll a[N], vis[N], sum;
map<int, int> mp;
int pos, apos;
vector<int> ans, aans, tt;
int main() {
  srand((int)time(0));

  n = read(), k = read();
  for (int i = 1; i <= n; i++) a[i] = -1;
  while (sum < k && (n - sum) >= k) {
    cout << "?";
    mp.clear();
    tt.clear();
    for (int i = 1; i <= k; i++) {
      int t = random(n);
      while (vis[t] == 1 || mp[t] == 1) {
        t = random(n);
      }
      mp[t] = 1;
      tt.push_back(t);
    }
    sort(tt.begin(), tt.end());
    for (int i = 0; i < tt.size(); i++) {
      cout << ' ' << tt[i];
    } cout << endl;
    pos      = read(), apos = read();
    a[pos]   = apos;
    vis[pos] = 1;
    sum++;

    // cout << sum << endl;
  }
  if (sum == k) {
    for (int i = 1; i <= n; i++) {
      // cout << a[i] << endl;
      if (a[i] != -1) {
        ans.push_back(i);
        aans.push_back(a[i]);
      }
    }
    cout << "?";
    for (int i = 0; i < ans.size(); i++) {
      cout << ' ' << ans[i];
    }
    cout << endl;
    pos = read(), apos = read();
    sort(aans.begin(), aans.end());
    cout << "! " <<
      lower_bound(aans.begin(), aans.end(), apos) - aans.begin() + 1 << endl;
    return 0;
  }
  else {
    cout << "bug" << endl;
    vector<int> tans, ttans;
    for (int i = 1; i <= n; i++) {
      if (a[i] != -1) {
        tans.push_back(i);
        ttans.push_back(a[i]);
      }
    }
  }
}