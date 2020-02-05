#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>       //    ____   _   _  __   __
using namespace std;       //   / ___| | | | | \ \ / /
#define ll long long       //  | |     | |_| |  \ V /
const ll INF = 0x3f3f3f3f; //  | |___  |  _  |   | |
const ll N   = 1e5 + 5;    //   \____| |_| |_|   |_|
const ll MOD = 1e9 + 7;
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

ll n;
string str;

int main() {
  n = read();
  cin >> str;
  int  g   = 0;
  bool flg = false;

  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'S') {
      flg = true;
    }

    if (str[i] == 'G') {
      g++;
    }
  }
  int pre = 0, now = 0, ans = 0;

  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'G') {
      int j = i;

      if (pre == 0) {
        for (j = i; j < str.size() && str[j] == 'G'; j++) {
          pre++;
        }

        if (pre < g) {
          ans = max(ans, pre + 1);
        }
        else {
          ans = max(ans, pre);
        }
      }
      else {
        now = 0;

        for (j = i; j < str.size() && str[j] == 'G'; j++) {
          now++;
        }

        if (flg) {
          if (pre + now < g) {
            ans = max(ans, pre + now + 1);
          }
          else {
            ans = max(ans, pre + now);
          }
        }
        else {
          ans = max(ans, now);
        }
        pre = now;
      }
      i = j;
    }
    else {
      pre = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
