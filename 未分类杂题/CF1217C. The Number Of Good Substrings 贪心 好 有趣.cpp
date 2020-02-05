#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 2e5 + 5;    //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    ____| |_| |_|   |_|
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1; ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0'; ch = getchar();
  }
  return x * f;
}

string s;
ll     num[N], l0[N], ans;
int main() {
  // for (int i = 1; i < N; i++) {
  //   int t   = i;
  //   int cnt = 0;
  //
  //   while (t) {
  //     cnt++;
  //     t /= 2;
  //   }
  //   num[i] = cnt;
  // }

  for (int _ = read(); _; _--) {
    cin >> s;
    ll cnt = 0;
    ans = 0;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') l0[i] = cnt, cnt = 0;
      else cnt++;
    }

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        ll cnt = l0[i];
        ll t   = 1;
        ans++;

        for (int j = i + 1; j < s.size(); j++) {
          t *= 2;

          if (s[j] == '1') t++;

          if (cnt >= (t - (j - i + 1))) ans++;
          else break;
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}
