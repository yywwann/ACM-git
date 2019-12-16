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

string s1, s2, ans;
int pos1, pos2;

void fun(int tpos, string s) {
  int pos = 0;
  for (int i = 0; i < ans.size(); i++) {
    if (s[pos] == ans[i]) pos++;
    else {
      if (s[pos] == '(')
    }
  }
}

int main() {
  cin >> s1 >> s2;
  while (pos1 < s1.size() && pos2 < s2.size()) {
    if (s1[pos1] == s2[pos2]) {
      ans += s1[pos1];
      pos1++, pos2++;
    }
    else {
      if (s1[pos1] == '(') {
        ans += s1[pos1];
        pos1++;
      }
      else {
        ans += s2[pos2];
        pos2++;
      }
    }
  }
  if (pos1 < s1.size()) fun(pos1, s1);
  else fun(pos2, s2);

  return 0;
}
