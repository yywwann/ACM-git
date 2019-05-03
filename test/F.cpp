
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
LL n, book[100000], top, bl[100000], br[100000], qian[100000];
struct node {
  LL v;
  LL i;
} s[100000];
int main() {
  cin >> n;
  LL ans = 0, ai = 0;
  for (LL i = 1; i <= n; i++)
    scanf("%lld", &book[i]);
  top = 0;
  for (LL i = 1; i <= n; i++) {
    while (top && s[top].v >= book[i])
      top--;
    if (top == 0)
      bl[i] = 0;
    else
      bl[i] = s[top].i;
    s[++top].i = i, s[top].v = book[i];
  }
  top = 0;
  for (LL i = n; i >= 1; i--) {
    while (top && s[top].v >= book[i])
      top--;
    if (top == 0)
      br[i] = n + 1;
    else
      br[i] = s[top].i;
    s[++top].i = i, s[top].v = book[i];
  }
  for (LL i = 1; i <= n; i++)
    qian[i] = qian[i - 1] + book[i];
  for (LL i = 1; i <= n; i++) {
    if (ans < (qian[br[i] - 1] - qian[bl[i]]) * book[i]) {
      ai = i;
      ans = (qian[br[i] - 1] - qian[bl[i]]) * book[i];
    }
  }
  cout << ans << endl;
  // if(ans) cout<<bl[ai]+1<<' '<<br[ai]-1<<endl;
  // else cout<<1<<' '<<1<<endl;

  return 0;
}
