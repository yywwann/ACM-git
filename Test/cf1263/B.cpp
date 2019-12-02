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

ll n, ans;
string s[N];
map<string, int> mp, mp2;
vector<string>   v;
int main() {
  for (int _ = read(); _; _--) {
    n   = read();
    ans = 0;
    v.clear();
    mp.clear();
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      mp[s[i]]++;
    }
    for (int i = 1; i <= n; i++) {
      if (mp[s[i]] > 1) {
        ans++;
        mp[s[i]]--;
        string S = s[i];
        for (int j = 0; j < 4; j++) {
          int  f = 0;
          char t = S[j];
          for (int k = 0; k <= 9; k++) {
            S[j] = char(k + '0');
            if (mp[S] == 0) {
              f = 1;
              break;
            }
          }
          if (f) break;
          S[j] = t;
        }
        mp[S]++;
        v.push_back(S);
      }
      else v.push_back(s[i]);
    }

    // for (int i = 1; i <= n; i++) {
    //   cin >> s;
    //   if (mp[s] != 0) {
    //     ans++;
    //     for (int j = 0; j < 4; j++) {
    //       int  f = 0;
    //       char t = s[j];
    //       for (int k = 0; k <= 9; k++) {
    //         s[j] = char(k + '0');
    //         if (mp[s] == 0) {
    //           f = 1;
    //           break;
    //         }
    //       }
    //       if (f) break;
    //       s[j] = t;
    //     }
    //   }
    //   mp[s]++;
    //   v.push_back(s);
    // }
    cout << ans << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
  }
  return 0;
}