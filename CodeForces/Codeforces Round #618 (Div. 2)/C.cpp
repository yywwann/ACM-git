#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;
const ll  INF  = 0x3f3f3f3f3f3f3f3f;
int a[maxn];
int pre[maxn], nex[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] | a[i];
  }
  for (int i = n; i >= 1; i--) {
    nex[i] |= nex[i + 1] | a[i];
  }
  int ans = -100, id = 0;
  for (int i = 1; i <= n; i++) {
    int num = pre[i - 1] | nex[i + 1];
    if (a[i] - (a[i] & num) > ans) id = i, ans = a[i] - (a[i] & num);
  }
  printf("%d", a[id]);
  for (int i = 1; i <= n; i++) {
    if (i == id) continue;
    else printf(" %d", a[i]);
  }
  printf("\n");
  return 0;
}