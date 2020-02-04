#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
const ll  INF  = 0x3f3f3f3f3f3f3f3f;
char s[maxn];
queue<int> q;
int ans[maxn];
int main() {
  int n;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    q.push(i);
  }
  q.push(-1);
  int num = 1;
  int pre = -1;
  while (true) {
    if (q.size() == 1) break;
    int u = q.front(); q.pop();

    // cout<<u<<endl;
    if (u == -1) q.push(u), num++, pre = -1;
    else if (s[u] >= pre) ans[u] = num, pre = s[u];
    else q.push(u);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt = max(ans[i], cnt);
  }
  if (cnt > 2) printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < n; i++) printf("%d", ans[i] - 1);
  }
  return 0;
}