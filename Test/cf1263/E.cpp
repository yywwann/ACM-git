#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 2e18;    //   | |     |  _  |   V /
const ll N   = 1e5 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

ll n, pos, len;
string s, t;

struct segt {
  ll *a;
  ll  SUM, MAX, MIN;
  struct Tree {
    int l, r;
    ll  sum, lz, max, min, set, L, R, maxBal;
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
    tree[x].maxBal =

      tree[x].sum = tree[2 * x].sum + tree[2 * x + 1].sum;
    tree[x].max   = max(tree[2 * x].max, tree[2 * x + 1].max);
    tree[x].min   = min(tree[2 * x].min, tree[2 * x + 1].min);
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
    tree[x].L   = tree[x].R = tree[x].maxBal = 0;
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

  void addL(int x, int pos, ll c) {
    int L = tree[x].l, R = tree[x].r, mid = (L + R) / 2;
    if ((L == R) && (L == pos)) {
      tree[x].L += c;
      return;
    }
    pushdown(x);
    if (l <= mid) update(2 * x, l, r, c);
    if (r > mid) update(2 * x + 1, l, r, c);
    pushup(x);
  }

  void addR(int x, int pos, ll c) {
    int L = tree[x].l, R = tree[x].r, mid = (L + R) / 2;
    if ((L == R) && (L == pos)) {
      tree[x].R += c;
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

  void addR(int x, int pos, ll c) {}
} tree;



int main() {
  n = read();
  getline(cin, s);
  tree.build(1, 0, n / 2 - 1);
  for (int i = 0; i < n; i++) t += ' ';
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') pos++, len = max(len, pos);
    if (s[i] == 'L') pos = max(0, pos - 1);
    if (s[i] == '(') {
      if (t[pos] == ')') tree.addR(1, pos, -1);
      else if (t[pos] == '(') continue;
      tree.addL(1, pos, 1);
    }
    if (s[i] == ')') {
      if (t[pos] == '(') tree.addL(1, pos, -1);
      else if (t[pos] == ')') continue;
      tree.addR(1, pos, 1);
    }
    else {
      if (t[pos] == ')') tree.addR(1, pos, -1);
      else if (t[pos] == '(') tree.addL(1, pos, -1);
    }
    printf("%d ", tree.queryBal(1, 0, pos));
  }
  return 0;
}