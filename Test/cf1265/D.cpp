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

ll a, b, c, d;
ll aa, bb, cc, dd;
string ans;
int    sadasd, dsadasdas, dasdasdas, dasdasdasd;
void bfs(int x1) {
  ans = "";
  queue<int> q;
  if (x1 == 0) if (aa > 0) aa--, q.push(x1);
  if (x1 == 1) if (bb > 0) bb--, q.push(x1);
  if (x1 == 2) if (cc > 0) cc--, q.push(x1);
  if (x1 == 3) if (dd > 0) dd--, q.push(x1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    // cout << u << endl;
    // cout << ans << endl;
    // cout << aa << ' ' << bb << ' ' << cc << ' ' << dd << endl;
    if (u == 0) {
      ans += "0 ";
      if (bb > 0) bb--, q.push(1);
      else break;
    }
    if (u == 1) {
      ans += "1 ";
      if (aa > 0) aa--, q.push(0);
      else if (cc > 0) cc--, q.push(2);
      else break;
    }
    if (u == 2) {
      ans += "2 ";
      if (bb > 0) bb--, q.push(1);
      else if (dd > 0) dd--, q.push(3);
      else break;
    }
    if (u == 3) {
      ans += "3 ";
      if (cc > 0) cc--, q.push(2);
      else break;
    }
  }
}

int main() {
  a  = read(), b = read(), c = read(), d = read();
  aa = a, bb = b, cc = c, dd = d;
  bfs(0);
  if (ans.size() / 2 == a + b + c + d) {
    cout << "YES" << endl;
    cout << ans << endl;
    return 0;
  }
  aa = a, bb = b, cc = c, dd = d;
  bfs(1);
  if (ans.size() / 2 == a + b + c + d) {
    cout << "YES" << endl;
    cout << ans << endl;
    return 0;
  }
  aa = a, bb = b, cc = c, dd = d;
  bfs(2);
  if (ans.size() / 2 == a + b + c + d) {
    cout << "YES" << endl;
    cout << ans << endl;
    return 0;
  }
  aa = a, bb = b, cc = c, dd = d;
  bfs(3);
  if (ans.size() / 2 == a + b + c + d) {
    cout << "YES" << endl;
    cout << ans << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}