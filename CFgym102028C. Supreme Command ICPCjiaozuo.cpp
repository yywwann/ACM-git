#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;       //    ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 0x3f3f3f3f; //    | |     |  _  |  \ V /
const ll N   = 3e5 + 5;    //     | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //       \____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

ll  C[N];
ll  n, m;
ll  cll, clr, crl, crr;
int vis[N];

void Cnt(int id);
void init() {
  for (ll i = 0; i < N; i++) C[i] = i * (i - 1) / 2;
}

struct node {
  int pos[N], id[N];
  int l, r, d;

  void initLR() {
    l = 1, r = n, d = 0;
  }

  void initCnt() {
    Cnt(id[1]), Cnt(id[n]);
  }

  void setPos(int p, int i) {
    pos[i] = p, id[p] = i;
  }

  void left(int k) {
    while (l < r && l + d - k <= 0) Cnt(id[++l]);

    if (l + d - k <= 0) d = 1 - l;
    else d -= k;
  }

  void right(int k) {
    while (l < r && r + d + k > n) Cnt(id[--r]);

    if (r + d + k > n) d = n - r;
    else d += k;
  }

  int ask(int id) {
    if (pos[id] <= l) return l + d;

    if (pos[id] >= r) return r + d;

    return pos[id] + d;
  }
} A, B;

void Cnt(int id) {
  if (vis[id]) return;
  else if ((A.pos[id] <= A.l) && (B.pos[id] <= B.l)) cll++, vis[id] = 1;
  else if ((A.pos[id] <= A.l) && (B.pos[id] >= B.r)) clr++, vis[id] = 1;
  else if ((A.pos[id] >= A.r) && (B.pos[id] <= B.l)) crl++, vis[id] = 1;
  else if ((A.pos[id] >= A.r) && (B.pos[id] >= B.r)) crr++, vis[id] = 1;
}

ll query() {
  if ((A.l == A.r) && (B.l == B.r)) return C[cll + clr + crl + crr];
  else if (A.l == A.r) return C[cll + crl] + C[clr + crr];
  else if (B.l == B.r) return C[cll + clr] + C[crl + crr];
  else return C[cll] + C[clr] + C[crl] + C[crr];
}

int main() {
  init();

  for (int _ = read(); _; _--) {
    n = read(), m = read();
    A.initLR(), B.initLR();

    for (int i = 1; i <= n; i++) {
      int x = read(), y = read();
      A.setPos(x, i);
      B.setPos(y, i);
    }
    cll = clr = crl = crr = 0;
    memset(vis, 0, sizeof(vis));
    A.initCnt(), B.initCnt();

    char ope[3];
    int  k;

    while (m--) {
      scanf("%s", ope);

      if (ope[0] == '!') printf("%I64d\n", query());
      else {
        k = read();

        if (ope[0] == 'U') A.left(k);

        if (ope[0] == 'D') A.right(k);

        if (ope[0] == 'L') B.left(k);

        if (ope[0] == 'R') B.right(k);

        if (ope[0] == '?') printf("%d %d\n", A.ask(k), B.ask(k));
      }
    }
  }
  return 0;
}
