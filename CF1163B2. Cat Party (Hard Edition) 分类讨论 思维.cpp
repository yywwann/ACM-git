#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |  \ V /
const ll N = 1e5 + 5;      //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    \____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int n;
int a[N];
int mp[N], cnt[N];
int ans;
int ty;
int main() {
  for (int _ = 1; _; _--) {
    n = read();
    for (int i = 1; i <= n; i++) {
      a[i] = read();
      mp[a[i]]++;
    }
    for (int i = 1; i <= 100000; i++) {
      if (mp[i] != 0)
        ty++;
      cnt[mp[i]]++;}
    for (int i = n; i >= 1; i--) {
      int len = i;
      // cout << cnt[mp[a[i]]] << ' ' << mp[a[i]] << endl;
      if (cnt[mp[a[i]]] * mp[a[i]] == len && len + 1 <= n) {
        ans = max(ans, len + 1);
      }
      if (cnt[mp[a[i]]] * mp[a[i]] + mp[a[i]] + 1 == len &&
          ty - cnt[mp[a[i]]] == 1) {
        ans = max(ans, len);
      }
      if (cnt[mp[a[i]]] * mp[a[i]] + 1 == len) {
        ans = max(ans, len);
      }
      cnt[mp[a[i]]]--;
      mp[a[i]]--;
      cnt[mp[a[i]]]++;
      if (mp[a[i]] == 0)
        ty--;
    }
    cout << max(ans, 1) << endl;
  }
  return 0;
}

/*
分类讨论
1. 删最后一个
2. 删中间单独的一个
3. 删中间最多的一个
 */
