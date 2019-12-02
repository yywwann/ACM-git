#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6 + 5;
const ll  INF  = 0x3f3f3f3f3f3f3f3f;
int ans[maxn];
int main() {
  int t;
  ll  n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    int tot = 0;
    int chu = 1;
    while (true) {
      ans[++tot] = n / chu;
      chu        = ((int)(n * 1.0 / ans[tot]) + 1);
      if (ans[tot] == 0) break;
    }
    printf("%d\n", tot);
    for (int i = tot; i >= 1; i--) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }

  return 0;
}