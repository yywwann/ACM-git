#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
const ll MOD = 1e9+7;

int T;
int n, m;
ll a[N], b[N];
ll ans;
ll _2[N];

int main() {
  _2[0] = 1;
  for (int i = 1; i < N; i++) {
    _2[i] = (_2[i-1] * 2) % MOD;
  }
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);

    ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = (ans + ((_2[a[i]]-1+MOD)%MOD * b[i]) % MOD) % MOD;
    }
    printf("%lld\n", ans);
  }
}
