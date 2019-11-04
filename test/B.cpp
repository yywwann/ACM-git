#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 2e5 + 5;    //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    ____| |_| |_|   |_|
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1; ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0'; ch = getchar();
  }
  return x * f;
}

ll k, n;
struct node {
  int l, r, id;
  bool operator<(const node& rr) const
  {
    return r < rr.r;
  }
} line[N];

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
  } tree[N * 4];

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

int cmp(node a, node b) {
  if (a.l == b.l) return a.r > b.r;

  return a.l < b.l;
}

int main() {
  n = read(), k = read();
  tree.build(1, 1, 200000);

  for (int i = 1; i <= n; i++) {
    line[i].l  = read(), line[i].r = read();
    line[i].id = i;
    tree.update(1, line[i].l, line[i].r, 1);
  }
  sort(line + 1, line + 1 + n, cmp);
  int pos = 1;
  vector<int> ans;
  priority_queue<node> q;

  for (int i = 1; i <= 200000; i++) {
    int val = tree.querySUM(1, i, i);

    if (val > k) {
      for (pos; pos <= n; pos++) {
        if (line[pos].l > i) break;

        if ((line[pos].l <= i) && (line[pos].r >= i)) {
          q.push(line[pos]);
        }
      }

      while (val > k) {
        while (!q.empty()) {
          node u = q.top();
          q.pop();

          if ((u.l <= i) && (u.r >= i)) {
            tree.update(1, u.l, u.r, -1);
            ans.push_back(u.id);
            val--;
            break;
          }
        }
      }
    }
  }
  cout << ans.size() << endl;

  for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
  return 0;
}
