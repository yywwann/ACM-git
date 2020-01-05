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

ll n, k, ans;
string s[N];
map<string, int> mp;

char f(char a, char b) {
  char c[] = { 'S', 'E', 'T' };
  if (a == b) return a;
  else {
    for (int i = 0; i < 3; i++) {
      if ((c[i] != a) && (c[i] != b)) return c[i];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> s[i], mp[s[i]] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      string t = "";
      for (int z = 0; z < k; z++) t += f(s[i][z], s[j][z]);
      ans += mp[t];

      // cout << ans << endl;
    }
  }
  printf("%lld\n", ans / 3);

  return 0;
}