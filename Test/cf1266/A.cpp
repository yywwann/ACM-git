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


bool check0() {
  for (int i = 0; i < s.size(); i++) if (s[i] == '0') return true;
  return false;
}

bool check2() {
  ll ans = 0;
  for (int i = 0; i < s.size(); i++) if ((s[i] - '0') % 2 == 0) ans++;
  return ans > 1;
}

bool check3() {
  ll ans = 0;
  for (int i = 0; i < s.size(); i++) ans += s[i] - '0';
  return ans % 3 == 0;
}

int main() {
  for (int _ = read(); _; _--) {
    cin >> s;
    if (check0() && check2() && check3()) cout << "red" << endl;
    else cout << "cyan" << endl;
  }

  return 0;
}