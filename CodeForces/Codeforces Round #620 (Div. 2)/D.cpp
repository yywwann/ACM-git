#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 2e18;    //   | |     |  _  |   V /
const ll N   = 2e5 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

ll n, ans[N], num;
string s;
vector<int> pos;
int main() {
  for (int _ = read(); _; _--) {
    pos.clear();
    n = read();
    cin >> s;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == '<') pos.push_back(i + 1);
    }

    /****************/
    for (int i = 0; i <= n; i++) ans[i] = 0;
    num = 1;
    for (int i = pos.size() - 1; i >= 0; i--) {
      int len = 1;
      for (int j = i - 1; j >= 0; j--) {
        if (pos[i] - pos[j] == len) len++;
        else break;
      }
      int p = pos[i];
      for (int j = p - len + 1; j <= p; j++) ans[j] = num++;
      i -= len - 1;
    }
    for (int i = n; i >= 1; i--) {
      if (ans[i] == 0) ans[i] = num++;
    }
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]); printf("\n");

    /****************/
    for (int i = 0; i <= n; i++) ans[i] = 0;
    num = 1;
    for (int i = 0; i < pos.size(); i++) {
      int p = pos[i];
      ans[p] = num++;
    }
    for (int i = n; i >= 1; i--) {
      if (ans[i] == 0) ans[i] = num++;
    }
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]); printf("\n");
  }
  return 0;
}