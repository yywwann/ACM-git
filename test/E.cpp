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
const ll N   = 5e5+5;    //     | |___  | | | |   | |
const ll MOD = 1e9+7;   //       \____| |_| |_|   |_|
ll read() {
  ll x=0,f=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
  return x*f;
}

ll n;
ll sum[N], lef[N], rig[N], ans;
ll a[N];
struct node{
    ll v, i;
}stk[N];
int main(){
  n = read();
  for(int i = 1; i <= n; i++) a[i] = read();
  for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  for(int i = 1, top = 0; i <= n; i++) {
    while(top && stk[top].v >= a[i]) top--;
    if(top == 0) lef[i] = 0;
    else lef[i] = stk[top].i;
    stk[++top].i = i;
    stk[top].v = a[i];
  }
  for(int i = n, top = 0; i >= 1; i--) {
    while(top && stk[top].v >= a[i]) top--;
    if(top == 0) rig[i] = n+1;
    else rig[i] = stk[top].i;
    stk[++top].i = i;
    stk[top].v = a[i];
  }
  for(int i = 1; i <= n; i++) {
    ans = max(ans, (sum[rig[i]-1] - sum[lef[i]]) * a[i]);
  }
  cout << ans << endl;
  return 0;
}
