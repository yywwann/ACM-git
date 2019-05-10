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
#include<algorithm>             //    ____   _   _  __   __
using namespace std;            //   / ___| | | | | \ \ / /
#define ll long long            //  | |     | |_| |  \ V /
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |
const ll N   = 1e5+5;           //   \____| |_| |_|   |_|
const ll MOD = 1e9+7;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
ll n, k;
ll a[N], b[N], dp[N];
struct node{
    ll x, y;
    node(ll _x, ll _y){
        x = _x, y = _y;
    }
    friend bool operator < (node a, node b)
    {
        return a.x > b.x;//结构体中，x小的优先级高
        //return a.x < b.x;//结构体中，x大的优先级高
    }
};
 
priority_queue<node>q;
 
int main(){
    for(int _ = read(); _; _--){
        while(!q.empty()) q.pop();
        n = read();
        for(int i = 1; i <= n; i++) a[i] = read();
        for(int i = 1; i <= n; i++) b[i] = read();
        dp[1] = a[1];
        q.push(node(dp[1], 1+b[1]));
        for(int i = 2; i <= n; i++){
            node t = q.top();
            dp[i] = a[i] + t.x;
            ll x = dp[i];
            ll y = i+b[i];
            while(!q.empty()){
                t = q.top();
                if(t.y <= i) q.pop();
                else if(x < t.x){ q.push(node(x, y)); break; }
                else if(y <= t.y) break;
                else{ q.push(node(x, y)); break; }
            }
            if(q.empty()) q.push(node(x, y));
        }
        cout << dp[n] << endl;
    }
    return 0;
}