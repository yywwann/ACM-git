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
ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
  return x*f;
}

int n, m;
string s;

int main(){
	for (int _ = read(); _; _--) {
    n = read(), m = read();
    int x, y, len;
    len = 0;
    for (int i = 1; i <= n; i++) {
      cin >> s;
      int tlen, tx, ty;
      tlen = tx = ty = 0;
      for (int j = 0; j < s.size(); j++) {
        if (s[j] == '.') {
          tlen++;
          tx = i;
          ty = j + 1;
        }
      }
      if (tlen > len) {
        len = tlen;
        x = tx;
        y = ty;
      }
    }
    cout << len / 2 << ' ' << x << ' ' << y - len / 2 << endl;
	}
	return 0;
}
