#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;
const ll  INF = 0x3f3f3f3f3f3f3f3f;
int t, n, k, p;
int a[maxn];
ll  sum[maxn], ou[maxn];
int check(int x) {
  if (sum[x] <= p) return 1;
  else return 0;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    sum[0] = 0;
    for (int i = 1; i < k; i++) {
      sum[i] = sum[i - 1] + a[i];
    }
    sum[k] = a[k];
    for (int i = k + 1; i <= n; i++) {
      sum[i] = sum[i - k] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (sum[i] <= p) ans = i;
    }
    printf("%d\n", ans);
  }

  return 0;
}

/*
   6
   5 6 2
   2 4 3 5 7

 */