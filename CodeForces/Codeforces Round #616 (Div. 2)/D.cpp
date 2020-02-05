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

string s;
ll     q, l, r, flg;
ll     sum[26][N], num[26];

int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < 26; j++) {
      sum[j][i + 1] = sum[j][i];
    }
    sum[s[i] - 'a'][i + 1]++;
  }

  q = read();
  while (q--) {
    l = read(), r = read();
    for (int i = 0; i < 26; i++) {
      num[i] = 0, num[i] += sum[i][r] - sum[i][l - 1];
    }
    ll t = 0;
    for (int i = 0; i < 26; i++) {
      if (num[i] > 0) t++;
    }
    if (t == 1) {
      if (r == l) flg = 1;
      else flg = 0;
    } else if (t == 2) {
      if (s[l - 1] == s[r - 1]) flg = 0;
      else flg = 1;
    } else flg = 1;
    if (flg) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}