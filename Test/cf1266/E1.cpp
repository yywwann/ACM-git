#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 100;
char s[maxn];
int  len;
int  T;
struct SAM {
  int last, cnt, nxt[maxn * 2][26], fa[maxn * 2], l[maxn * 2];
  int ans;
  void init() {
    last = cnt = 1;
    memset(nxt[1], 0, sizeof nxt[1]);
    fa[1] = 0; ans = 0; l[1] = 0;
  }

  int inline newnode() {
    ++cnt;
    memset(nxt[cnt], 0, sizeof nxt[cnt]);
    fa[cnt] = l[cnt] = 0;
    return cnt;
  }

  void add(int c) {
    int p  = last;
    int np = newnode();
    last  = np;
    l[np] = l[p] + 1;
    while (p && !nxt[p][c]) {
      nxt[p][c] = np;
      p         = fa[p];
    }
    if (!p) {
      fa[np] = 1;
    } else {
      int q = nxt[p][c];
      if (l[q] == l[p] + 1) {
        fa[np] = q;
      } else {
        int nq = newnode();
        memcpy(nxt[nq], nxt[q], sizeof nxt[q]);
        fa[nq] = fa[q];
        l[nq]  = l[p] + 1;
        fa[np] = fa[q] = nq;
        while (nxt[p][c] == q) {
          nxt[p][c] = nq;
          p         = fa[p];
        }
      }
    }

    //		cout<<fa[last]<<endl;
    ans += l[last] - l[fa[last]];
  }

  void query() {
    int l, r;

    // scanf("%d%d", &l, &r);
    l = 1, r = strlen(s + 1);
    init();
    for (int i = l; i <= r; i++) {
      //			cout<<s[i]<<" ";
      add(s[i] - '0');
    }
    printf("%d\n", ans);
  }
} sam;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s + 1);
    int Q;
    sam.query();
  }
  return 0;
}