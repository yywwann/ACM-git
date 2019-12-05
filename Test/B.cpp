#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
  int t;
  int a[100005], b[100005], c[100005];
  while (scanf("%d", &t) != EOF) {
    long long ans = 0;
    for (int i = 0; i < t; i++) scanf("%d", &a[i]);
    sort(a, a + t);
    for (int i = 0; i < t; i++) scanf("%d", &b[i]);
    sort(b, b + t);
    for (int i = 0; i < t; i++) scanf("%d", &c[i]);
    sort(c, c + t);

    long long k1, k2;
    for (int i = 0; i < t; i++) {
      k1 = lower_bound(a, a + t, b[i]) - a;
      k2 = upper_bound(c, c + t, b[i]) - c;
      if (b[i] == c[k2]) k2 = k2 + 1;
      ans = ans + (k1) * (t - k2);
    }
    printf("%lld\n", ans);
  }
}