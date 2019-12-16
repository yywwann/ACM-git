#include <bits/stdc++.h>
using namespace std;
int n, t;
int L, R, l, r;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    L = -1, R = 1e9 + 5;
    for (int i = 1; i <= n; i++) {
      cin >> l >> r;
      L = max(L, l);
      R = min(R, r);
    }
    cout << max(0, L - R) << endl;
  }

  return 0;
}