#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;        //    ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 0x3f3f3f3f;//    | |     |  _  |  \ V /
const ll N   = 1e5+5;    //     | |___  | | | |   | |
const ll MOD = 1e9+7;   //       \____| |_| |_|   |_|
ll read() {
  ll x=0,f=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
  return x*f;
}

map<pair<int,int>, int> mp[2];
int n, m, x, y, ans, flg;

int main(){
  for (int _ = read(); _; _--) {
      n = read();
      flg = 0;
      ans = 0;
      for (int i = 1; i <= n; i++) {
        m = read();
        mp[flg].clear();
        for (int j = 1; j <= m; j++) {
          x = read(), y = read();
          pair<int, int> p = make_pair(x, y);
          if (mp[flg^1].count(p)) {
            int t = mp[flg^1][p] + 1;
            mp[flg][p] = t;
            ans = max(ans, t);
          } else {
            mp[flg][p] = 1;
            ans = max(ans, 1);
          }
        }
        flg ^= 1;
      }
      cout << ans << endl;
  }
  return 0;
}
