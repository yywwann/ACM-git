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

ll n, a[N];
vector<char> v;

int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = i;

  // a[1] = 1, a[2] = 2, a[3] = 3;
  do {
    for (int i = 1; i <= n; i++) v.push_back(a[i] + '0');
  } while (next_permutation(a + 1, a + 1 + n));
  for (int i = 0; i <= v.size(); i++) cout << v[i];
  return 0;
}