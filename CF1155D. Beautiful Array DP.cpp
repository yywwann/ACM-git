#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 3e5 + 5;

LL a[N], n, x, ans, pre[N], suf[N], sum[N];

int main() {
  scanf("%lld%lld", &n, &x);

  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

  for (int i = 1; i <= n; i++) pre[i] = max(pre[i], pre[i - 1] + a[i]);

  for (int i = n; i >= 1; i--) suf[i] = max(suf[i], suf[i + 1] + a[i]);

  LL MAX = 0;

  for (int i = 1; i <= n; i++) {
    MAX = max(MAX, pre[i] - x * sum[i]);
    ans = max(ans, suf[i + 1] + sum[i] * x + MAX);
  }
  printf("%lld\n", ans);

  return 0;
}

// 枚举被修改区间右端点R，那么答案可以表示成 suf[R+1] + pre[L-1] + (sum[R]-sum[L-1]) * x
// 维护前缀，pre[L-1] - sum[L-1] * x  最大值即可。

/*
    suf[R+1] + pre[L-1] + (sum[R]-sum[L-1]) * x
   =   suf[R+1] + sum[R] * x + pre[L-1] - sum[L-1] * x
   枚举 R, 过程中(pre[L-1] - sum[L-1] * x)取最大值
 */
