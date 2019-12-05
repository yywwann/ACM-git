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

string s;

int main() {
  for (int _ = read(); _; _--) {
    cin >> s;
    int flg = 1;
    for (int i = 0; i < s.size(); i++) {
      if ((s[i] == '?') && (i == 0) && (i == s.size() - 1)) s[i] = 'a';
      else if (s[i] == '?') {
        if (i == 0) {
          if (s[i + 1] == 'a') s[i] = 'b';
          if (s[i + 1] == 'b') s[i] = 'a';
          if (s[i + 1] == 'c') s[i] = 'a';
          if (s[i + 1] == '?') s[i] = 'a';
        }
        else if (i == s.size() - 1) {
          if (s[i - 1] == 'a') s[i] = 'b';
          if (s[i - 1] == 'b') s[i] = 'a';
          if (s[i - 1] == 'c') s[i] = 'a';
        }
        else {
          if ((s[i - 1] == 'a') && (s[i + 1] == 'a')) s[i] = 'b';
          if ((s[i - 1] == 'a') && (s[i + 1] == 'b')) s[i] = 'c';
          if ((s[i - 1] == 'a') && (s[i + 1] == 'c')) s[i] = 'b';
          if ((s[i - 1] == 'a') && (s[i + 1] == '?')) s[i] = 'b';
          if ((s[i - 1] == 'b') && (s[i + 1] == 'a')) s[i] = 'c';
          if ((s[i - 1] == 'b') && (s[i + 1] == 'b')) s[i] = 'a';
          if ((s[i - 1] == 'b') && (s[i + 1] == 'c')) s[i] = 'a';
          if ((s[i - 1] == 'b') && (s[i + 1] == '?')) s[i] = 'a';
          if ((s[i - 1] == 'c') && (s[i + 1] == 'a')) s[i] = 'b';
          if ((s[i - 1] == 'c') && (s[i + 1] == 'b')) s[i] = 'a';
          if ((s[i - 1] == 'c') && (s[i + 1] == 'c')) s[i] = 'a';
          if ((s[i - 1] == 'c') && (s[i + 1] == '?')) s[i] = 'a';
        }
      }
      else if (s[i] == s[i + 1]) flg = 0;
    }
    if (flg == 0) cout << -1 << endl;
    else cout << s << endl;
  }
  return 0;
}