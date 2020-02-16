#include <bits/stdc++.h>
#define res register int
#define ll long long
#define maxn 100010
using namespace std;
struct Node {
  int to, next;
};
Node edge1[maxn << 1];
int  head1[maxn << 1], n, m, root, d[maxn], fa[maxn][30], num1;
int  x, y, a, b, k, d1, dax, day, dbx, dby;
inline int read() {
  int  s = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') { if (c == '-') w = 1; c = getchar(); }
  while (c >= '0' && c <= '9') s = s * 10 + c - '0', c = getchar();
  return s * w;
}

inline void add1(int x, int y) {
  edge1[++num1].to = y; edge1[num1].next = head1[x]; head1[x] = num1;
}

inline void build(int u, int pre) {
  d[u] = d[pre] + 1; fa[u][0] = pre;
  for (res i = 0; fa[u][i]; ++i) fa[u][i + 1] = fa[fa[u][i]][i];
  for (res i = head1[u]; i; i = edge1[i].next) {
    int e = edge1[i].to;
    if (e != pre) build(e, u);
  }
}

inline int lca(int u, int v) {
  if (d[u] > d[v]) swap(u, v);
  for (res i = 20; i >= 0; --i) if (d[u] <= d[v] - (1 << i)) v = fa[v][i];
  if (u == v) return u;
  for (res i = 20; i >= 0;
       --i) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}

inline int dist(int u, int v) {
  return d[u] + d[v] - 2 * d[lca(u, v)];
}

int main() {
  n = read(), root = 1;
  for (res i = 1; i < n; ++i) {
    x = read(), y = read();
    add1(x, y); add1(y, x);
  }
  m = read(), build(root, 0);
  while (m--) {
    x  = read(), y = read(), a = read(), b = read(), k = read();
    d1 = dist(a, b);
    if ((d1 <= k) && ((k - d1) % 2 == 0)) {
      printf("YES\n");
      continue;
    }
    dax = dist(a, x);
    day = dist(a, y);
    dbx = dist(b, x);
    dby = dist(b, y);
    d1  = dax + dby + 1;
    if ((d1 <= k) && ((k - d1) % 2 == 0)) {
      printf("YES\n");
      continue;
    }
    d1 = day + dbx + 1;
    if ((d1 <= k) && ((k - d1) % 2 == 0)) {
      printf("YES\n");
      continue;
    }
    printf("NO\n");
  }
  return 0;
}