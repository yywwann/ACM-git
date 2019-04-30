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

ll n;


int main(){
  for (int _ = read(); _; _--) {
    n = read();
    if (n % 2 == 0) {
      printf("%d %d\n", 4, 4 + n);
      // cout << 4 << ' ' <<  4 + n << endl;
    } else {
      printf("%d %d\n", 9, 9 + n);
      // cout << 9 << ' ' << 9 + n << endl;
    }
  }
  return 0;
}
