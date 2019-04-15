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

ll n, a[N];

int check(ll x) {
  for (int i = 1; i <= n; i++) {
    //cout << a[i] << ' ' << x << endl;
    if (a[i] > x) {
      x -= a[i] - x;
    } else {
      x += x - a[i];
    }
    //cout << a[i] << ' ' << x << endl;
    if (x <= 0) return false;
  }
  return true;
}

int main(){
  for (int _ = 1; _; _--) {
    n = read();
    for (int i = 1; i <= n; i++) {
      a[i] = read();
    }
    ll l = 1, r = 1e5, ans = 1e5;
    // while (l+1<r) {
    //   ll mid = (l + r) / 2;
    //   //cout << l << ' ' << r << ' ' << mid << endl;
    //   if (check(mid)) {
    //     //cout << "YES" << endl;
    //     ans = min(ans, mid);
    //     r = mid + 1;
    //   } else {
    //     //cout << "NO" << endl;
    //     l = mid;
    //   }
    // }
    for (int i = 1; i <= 50; i++) {
      ll mid = (l + r) / 2;
      //cout << l << ' ' << r << ' ' << mid << endl;
      if (check(mid)) {
        //cout << "YES" << endl;
        ans = min(ans, mid);
        r = mid + 1;
      } else {
        //cout << "NO" << endl;
        l = mid - 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
