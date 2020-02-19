#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 4e5 + 5;    //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

ll k, kp[N], mpkp[N];
ll n, m, cnt = 0;
ll dis[N], vis[N], head[N], disa[N], disb[N], posa[N], posb[N];
ll pre[N], pre2[N];
struct node {
  ll next, to, w;
} x[N];
void add(ll start, ll endd, ll w) {
  x[cnt].to   = endd;
  x[cnt].w    = w;
  x[cnt].next = head[start];
  head[start] = cnt++;
}

void init() {
  cnt = 0;
  memset(head, -1, sizeof head);
  memset(x,     0, sizeof x);
  memset(pre,   0, sizeof pre);
  memset(pre2,  0, sizeof pre2);
}

void spfa(int st, ll *dis) {
  queue<ll> q;
  for (ll i = 1; i <= n; i++) {
    dis[i] = INF; // 初始化
    vis[i] = 0;
  }
  q.push(st);
  dis[st] = 0;
  vis[st] = 1;                                     // 第一个顶点入队，进行标记
  while (!q.empty()) {
    ll u = q.front();                              // 取出队首
    q.pop();
    vis[u] = 0;                                    // 出队标记
    for (ll i = head[u]; i != -1; i = x[i].next) { // 找这条边的同起点的上一条边
      ll v = x[i].to;
      if (dis[v] > dis[u] + x[i].w) {              // 如果有最短路就更改
        dis[v] = dis[u] + x[i].w;
        if (vis[v] == 0) {                         // 未入队则入队
          vis[v] = 1;                              // 标记入队
          q.push(v);
        }
        pre[v]  = u;
        pre2[v] = i;
      }
    }
  }
}

struct TAT {
  ll w, id;
};
vector<TAT> A, B;

int cmp(TAT a, TAT b) {
  return a.w < b.w;
}

int main() {
  init();
  n = read(), m = read(), k = read();
  int flg = 0;
  for (int i = 1; i <= k; i++) kp[i] = read(), mpkp[kp[i]] = 1;
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    add(u, v, 1);
    add(v, u, 1);
    if ((mpkp[v] == 1) && (mpkp[u] == 1)) flg = 1;
  }
  spfa(1, disa);
  if (flg) {
    cout << disa[n] << endl;
    return 0;
  }
  ll tans = disa[n];
  spfa(n, disb);
  for (int i = 1; i <= n; i++) {
    if (mpkp[i] == 1) {
      A.push_back(TAT{ disa[i], i });
      B.push_back(TAT{ disb[i], i });
    }
  }
  sort(A.begin(), A.end(), cmp);
  sort(B.begin(), B.end(), cmp);
  ll ans = 0;
  for (int i = 0; i < k; i++) {
    posa[A[i].id] = i;
    posb[B[i].id] = i;
  }
  for (int i = 0; i < k - 1; i++) {
    ans = max(ans, disa[A[i].id] + 1 + disb[A[i + 1].id]);
    ans = max(ans, disb[B[i].id] + 1 + disa[B[i + 1].id]);
  }
  cout << min(ans, tans) << endl;
  return 0;
}