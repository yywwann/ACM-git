#include <bits/stdc++.h>
using namespace std;     //     ____   _   _  __   __
#define ll long long     //    / ___| | |_| |   / /
const ll INF  = 2e18;    //   | |     |  _  |   V /
const ll maxn = 2e5 + 5; //   | |___  | | | |   | |
const ll MOD  = 1e9 + 7; //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

ll n;
vector<int> g[maxn];
struct Edge {
  ll u, v, w;
};
vector<Edge> edge, que;
ll f[maxn];    // 父亲
ll d[maxn];    // 深度
ll son[maxn];  // 重儿子
ll size[maxn]; // 大小
ll top[maxn];  // 所在链的顶端
ll id[maxn];   // dfs序
ll rk[maxn];   // dfs序对应的结点编号
ll cnt;        // dfs的时间戳



void dfs1(ll x, ll pre, ll deep) {
  size[x] = 1, d[x] = deep;
  f[x]    = pre;
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i];
    if (y == pre) continue;
    f[y] = x; dfs1(y, x, deep + 1); size[x] += size[y];
    if (size[son[x]] < size[y]) son[x] = y;
  }

  // for (ll i = head[x]; i != -1; i = edge[i].nxt) {
  //   ll y = edge[i].to;
  //   if (y == pre) continue;
  //   f[y] = x; dfs1(y, x, deep + 1); size[x] += size[y];
  //   if (size[son[x]] < size[y]) son[x] = y;
  // }
}

void dfs2(ll x, ll tp) {
  top[x] = tp; id[x] = ++cnt; rk[cnt] = x;
  if (son[x]) dfs2(son[x], tp);
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i];
    if ((y != son[x]) && (y != f[x])) dfs2(y, y);
  }

  // for (ll i = head[x]; i != -1; i = edge[i].nxt) {
  //   ll y = edge[i].to;
  //   if ((y != son[x]) && (y != f[x])) dfs2(y, y);
  // }
}

struct segt {
  ll *a;
  ll  SUM, MAX, MIN;
  struct Tree {
    int l, r;
    ll  sum, lz, max, min, set;
    void update(ll v) {
      sum += v * (r - l + 1);
      lz  += v;
      max += v;
      min += v;
    }

    void setval(ll v) {
      sum = v * (r - l + 1);
      lz  = 0;
      max = v;
      min = v;
      set = v;
    }
  } tree[maxn * 4];

  void modify(ll *arr) {
    a = arr;
  }

  void pushup(int x) {
    tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
    tree[x].max = max(tree[2 * x].max, tree[2 * x + 1].max);
    tree[x].min = min(tree[2 * x].min, tree[2 * x + 1].min);
  }

  void pushdown(int x) {
    if (tree[x].set != -1) {
      tree[2 * x].setval(tree[x].set);
      tree[2 * x + 1].setval(tree[x].set);
      tree[x].set = -1;
    }
    if (tree[x].lz != 0) {
      tree[2 * x].update(tree[x].lz);
      tree[2 * x + 1].update(tree[x].lz);
      tree[x].lz = 0;
    }
  }

  // 建树
  void build(int x, int l, int r) {
    tree[x].l   = l;
    tree[x].r   = r;
    tree[x].sum = tree[x].max = tree[x].min = tree[x].lz = 0;
    tree[x].set = -1;
    if (l == r) {
      tree[x].sum = tree[x].max = tree[x].min = 1000000;
      return;
    }
    int mid = (l + r) / 2;
    build(2 * x,     l,       mid);
    build(2 * x + 1, mid + 1, r);
    pushup(x);
  }

  // 将 l-r 范围的数都加上 c
  void update(int x, int l, int r, ll c) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;
    if ((l <= L) && (r >= R)) {
      tree[x].update(c);
      return;
    }

    pushdown(x);
    if (l <= mid) update(2 * x, l, r, c);
    if (r > mid) update(2 * x + 1, l, r, c);
    pushup(x);
  }

  // 将 l-r 范围的数变成 c， 如果 set 为 -1 表示没有被赋值过
  void setval(int x, int l, int r, ll c) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;
    if ((l <= L) && (r >= R)) {
      tree[x].setval(c);
      return;
    }

    pushdown(x);
    if (l <= mid) setval(2 * x, l, r, c);
    if (r > mid) setval(2 * x + 1, l, r, c);
    pushup(x);
  }

  // 查询区间和
  ll querySUM(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;
    ll  res = 0;
    if ((l <= L) && (r >= R)) { // 要更新区间包括了该区间
      return tree[x].sum;
    }

    pushdown(x);
    if (l <= mid) res += querySUM(2 * x, l, r);
    if (r > mid) res += querySUM(2 * x + 1, l, r);
    return res;
  }

  // 查询区间最大值
  ll queryMAX(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;
    ll  res = -INF;
    if ((l <= L) && (r >= R)) { // 要更新区间包括了该区间
      return tree[x].max;
    }

    pushdown(x);
    if (l <= mid) res = max(res, queryMAX(2 * x, l, r));
    if (r > mid) res = max(res, queryMAX(2 * x + 1, l, r));
    return res;
  }

  // 查询区间最小值
  ll queryMIN(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;
    ll  res = INF;
    if ((l <= L) && (r >= R)) { // 要更新区间包括了该区间
      return tree[x].min;
    }

    pushdown(x);
    if (l <= mid) res = min(res, queryMIN(2 * x, l, r));
    if (r > mid) res = min(res, queryMIN(2 * x + 1, l, r));
    return res;
  }

  // 一次性查询区间 SUM，MAX，MIN
  void query(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + R) / 2;
    if ((l <= L) && (r >= R)) { // 要更新区间包括了该区间
      SUM += tree[x].sum;
      MAX  = max(MAX, tree[x].max);
      MIN  = min(MIN, tree[x].min);
      return;
    }

    pushdown(x);
    if (l <= mid) query(2 * x, l, r);
    if (r > mid) query(2 * x + 1, l, r);
  }
} tree;

void updates(ll x, ll y, ll c) {
  while (top[x] != top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    tree.setval(1, id[top[x]], id[x], c);
    x = f[top[x]];
  }
  if (id[x] > id[y]) swap(x, y);
  if (x != y) tree.setval(1, id[x] + 1, id[y], c);
}

ll Min(ll x, ll y) {
  ll res = INF;
  while (top[x] != top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    res = min(res, tree.queryMIN(1, id[top[x]], id[x]));
    x   = f[top[x]];
  }
  if (id[x] > id[y]) swap(x, y);
  if (x != y) res = min(res, tree.queryMIN(1, id[x] + 1, id[y]));
  return res;
}

int cmp(Edge a, Edge b) {
  return a.w < b.w;
}

int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    g[u].push_back(v);
    g[v].push_back(u);
    edge.push_back(Edge{ u, v, 0 });
  }
  cnt = 0;
  dfs1(1, 0, 1);
  dfs2(1, 1);
  tree.build(1, 1, n);
  int q = read(), flg = 1;
  while (q--) {
    ll u = read(), v = read(), w = read();
    que.push_back(Edge{ u, v, w });
  }
  sort(que.begin(), que.end(), cmp);
  for (int i = 0; i < que.size(); i++) {
    ll u = que[i].u, v = que[i].v, w = que[i].w;
    updates(u, v, w);
  }
  for (int i = 0; i < que.size(); i++) {
    ll u = que[i].u, v = que[i].v, w = que[i].w;
    ll MIN = Min(u, v);
    if (MIN != w) {
      flg = 0;
      break;
    }
  }
  if (flg) {
    for (int i = 0; i < edge.size(); i++) {
      cout << Min(edge[i].u, edge[i].v) << ' ';
    }
  }
  else cout << -1;
  return 0;
}