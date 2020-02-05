#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;
const ll  INF  = 0x3f3f3f3f3f3f3f3f;
char s[maxn];
map<int, map<int, int> > mp;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    mp.clear();
    int ans = 100000000, l, r;
    int x = 0, y = 0;
    mp[0][0] = 10;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') x--;
      else if (s[i] == 'R') x++;
      else if (s[i] == 'U') y++;
      else y--;
      if (mp[x][y]) {
        if (ans > i + 11 - mp[x][y]) {
          ans      = i + 11 - mp[x][y];
          l        = mp[x][y], r = i + 11;
          mp[x][y] = i + 11;
        }
      }
      mp[x][y] = i + 11;
    }
    if (ans == 100000000) cout << -1 << endl;
    else cout << l - 9 << " " << r - 10 << endl;
  }
  return 0;
}