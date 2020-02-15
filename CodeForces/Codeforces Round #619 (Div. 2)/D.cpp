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

ll n, m, k;
struct node {
  int    f;
  string s;
};
vector<node> ans;

int main() {
  n = read(), m = read(), k = read();
  if (4 * n * m - 2 * n - 2 * m < k) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 1, z = 0; k > 0; i++) {
      if (i % 2 == 1) {
        if (z == n) {
          int f    = 0;
          string s = "U";
          for (int j = 1; j < n; j++) {
            if (k >= 1) {
              k -= 1;
              f++;
            }
          }
          if (f) ans.push_back(node{ f, s });
        }
        else if (i == 2 * n - 1) {
          int f    = 0;
          string s = "R";
          for (int j = 1; j < m; j++) {
            if (k >= 1) {
              k -= 1;
              f++;
            }
          }
          if ((m > 1) && f) ans.push_back(node{ f, s });
        }
        else {
          int f    = 0;
          string s = "RDU";
          for (int j = 1; j < m; j++) {
            if (k >= 3) {
              k -= 3;
              f++;
            }
            else if (k == 2) {
              k -= 2;
              if (f) ans.push_back(node{ f, s });
              ans.push_back(node{ 1, "RD" });
              break;
            }
            else if (k == 1) {
              k -= 1;
              if (f) ans.push_back(node{ f, s });
              ans.push_back(node{ 1, "R" });
              break;
            }
            if (k == 0) {
              if (f) ans.push_back(node{ f, s });
              break;
            }
          }
          if ((k != 0) && (m > 1) && f) {
            ans.push_back(node{ f, s });
          }
        }
      }
      else {
        z++;
        int f    = 0;
        string s = "L";
        for (int j = 1; j < m; j++) {
          if (k >= 1) {
            k -= 1;
            f++;
          }
        }
        if (m > 1) ans.push_back(node{ f, s });
        if ((k >= 1) && (z < n)) {
          k -= 1;
          ans.push_back(node{ 1, "D" });
        }
      }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].f << ' ' << ans[i].s << endl;
    }
  }
  return 0;
}