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

string s;
int    T;
int    Dp[3]; // 0 A   1 C   2 M

int main() {
  // freopen("In.txt","r",stdin);
  cin >> T;

  while (T--) {
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'A') Dp[0] += 1;
      else if (s[i] == 'C') Dp[1] = min(Dp[0], Dp[1] + 1);
      else Dp[2] = min(Dp[1], Dp[2] + 1);
    }
    cout << Dp[2] << endl;
  }

  return 0;
}
