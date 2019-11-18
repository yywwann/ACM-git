#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 1e5 + 5;    //   | |___  | | | |   | |
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

ll n, a[N];
set<ll> st;
map<ll, ll> mp;
int main() {
  for (int _ = 1; _; _--) {
    n = read();

    for (int i = 1; i <= n; i++) a[i] = read();
    int flg = 1;
    vector<int> ans;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
      if (a[i] > 0) {
        if ((st.find(a[i]) != st.end()) || (mp[a[i]] != 0)) {
          flg = 0;
          break;
        }
        else {
          mp[a[i]]++;
          st.insert(a[i]);
          cnt++;
        }
      }
      else {
        ll t = -a[i];

        if (st.find(t) != st.end()) {
          st.erase(t);
        }
        else {
          flg = 0;
          break;
        }
      }

      if (st.size() == 0) {
        ans.push_back(cnt);
        cnt = 0;
        mp.clear();
      }
    }

    if (flg && (n % 2 == 0)) {
      cout << ans.size() << endl;

      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] * 2 << ' ';
      }
    }
    else cout << -1 << endl;
  }
  return 0;
}
