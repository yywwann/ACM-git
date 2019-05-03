#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;       //    ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 0x3f3f3f3f; //    | |     |  _  |  \ V /
const ll N = 1e5 + 5;      //     | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //       \____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

char s[N], t[N];
int nxt[N][26];
int a[26];
int n;

int main() {
  scanf("%s", s);
  int lens = strlen(s);
  for (int i = 0; i < 26; i++)
    a[i] = -1;
  for (int i = lens - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      nxt[i][j] = a[j];
    }
    int idx = s[i] - 'a';
    a[idx] = i;
  }
  cin >> n;
  while (n--) {
    scanf("%s", t);
    int lent = strlen(t);
    bool flg = true;
    for (int i = 0, j = 0; i < lent && flg; i++) {
      int idx = t[i] - 'a';
      if (i == 0) {
        if (a[idx] == -1)
          flg = false;
        else
          j = a[idx];
      } else {
        if (nxt[j][idx] == -1)
          flg = false;
        else
          j = nxt[j][idx];
      }
    }
    if (flg)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
