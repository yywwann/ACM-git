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

string s, t;
int    nex[500][26], pre[500][26], used[500], idx[26], n, m;


int main() {
  for (int _ = read(); _; _--) {
    cin >> s >> t;
    n = s.size();
    m = t.size();
    for (int i = 0; i < 500; i++) used[i] = 0;
    for (int i = 0; i < 26; i++) idx[i] = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 26; j++) pre[i][j] = idx[j];
      idx[s[i] - 'a'] = i;
    }
    for (int j = 0; j < 26; j++) pre[n][j] = idx[j];
    for (int i = 0; i < 26; i++) idx[i] = -1;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < 26; j++) nex[i][j] = idx[j];
      idx[s[i] - 'a'] = i;
    }
    string t1 = "", t2 = "";
    int    st = -1, en = n;
    int    ST = 0, EN = m - 1;
    int    flg1 = 1, flg2 = 1;
    int    IDX = pre[en][t[EN] - 'a'];
    if (IDX == -1) flg2 = 0;
    else t2 = s[IDX] + t2, en = IDX, EN--, used[IDX] = 1;
    if (EN < ST) flg1 = flg2 = 0;
    if (flg1) {
      IDX = idx[t[ST] - 'a'];
      if (IDX == -1) flg1 = 0;
      else {
        while (IDX != -1 && used[IDX] == 1) {
          IDX = nex[IDX][t[ST] - 'a'];
        }
        if (IDX == -1) flg1 = 0;
        else t1 = t1 + s[IDX], st = IDX, ST++, used[IDX] = 1;
      }
    }
    while ((flg1 || flg2) && ST <= EN) {
      if (flg2) {
        IDX = pre[en][t[EN] - 'a'];
        if (IDX == -1) flg2 = 0;
        else {
          while (IDX != -1 && used[IDX] == 1) {
            IDX = pre[IDX][t[EN] - 'a'];
          }
          if (IDX == -1) flg2 = 0;
          else t2 = s[IDX] + t2, en = IDX, EN--, used[IDX] = 1;
        }
      }
      if (EN < ST) break;
      if (flg1) {
        IDX = nex[st][t[ST] - 'a'];
        if (IDX == -1) flg1 = 0;
        else {
          st = IDX;
          while (IDX != -1 && used[IDX] == 1) {
            IDX = nex[IDX][t[ST] - 'a'];
          }
          if (IDX == -1) flg1 = 0;
          else t1 = t1 + s[IDX], st = IDX, ST++, used[IDX] = 1;
        }
      }
    }

    cout << t1 << endl;
    cout << t2 << endl;
    if (t1 + t2 == t) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}