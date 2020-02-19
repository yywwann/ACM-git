#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
const ll  INF  = 0x3f3f3f3f3f3f3f3f;
char s[maxn];
ll   eng[30];
ll   num[30][30];
int main() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  ll  ma  = 0;
  for (int i = 1; i <= len; i++) {
    for (int j = 0; j < 26; j++) {
      num[j][s[i] - 'a'] += eng[j];
    }
    eng[s[i] - 'a']++;
    if (eng[s[i] - 'a'] > ma) ma = eng[s[i] - 'a'];
  }
  ll ans = ma;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      ans = max(ans, num[i][j]);
    }
  }
  cout << ans << endl;

  return 0;
}