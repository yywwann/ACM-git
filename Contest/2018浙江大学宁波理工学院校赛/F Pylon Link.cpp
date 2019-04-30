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
#include<algorithm>               //    ____   _   _  __   __
using namespace std;            //   / ___| | | | | \ \ / /
#define ll long long            //  | |     | |_| |  \ V /
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |
const ll N   = 500+5;           //   \____| |_| |_|   |_|
const ll MOD = 1e9+7;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

ll n;
ll x[N], y[N];

struct Dsu{
    int size,set_num;
    int fa[N],num[N];//集合个数，father

    void modify(int n){
        size = set_num = n;
        for(int i=0;i<=n;i++) fa[i] = i,num[i] = 1;
    }
    int fd(int x){
        return x == fa[x] ? x : fa[x] = fd(fa[x]);
    }
    bool join(int x,int y){
        int u = fd(x), v = fd(y);
        if(u==v) return 0;
        fa[u] = v;
        num[v] += num[u];
        set_num--;
        return 1;
    }
    bool same(int x,int y){
        return fd(x) == fd(y);
    }
};

Dsu dsu;

double dis(ll a, ll b){
    return sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));
}

const double EPS = 1e-8;

bool check(ll r){
    dsu.modify(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(dis(i, j) - r*2 > EPS) continue;
            dsu.join(i, j);
        }
    }
    if(dsu.set_num == 1) return 1;
    return 0;
}

int main(){
    for(ll _ = read(); _; _--){
        n = read();
        for(ll i=0;i<n;i++){
            x[i] = read();
            y[i] = read();
        }
        ll l = 0, r = 2*MOD, mid;
        for(ll i=1;i<=50;i++){
            mid = (l+r)/2;
            if(check(mid)){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        printf("%lld\n", r);
    }
    return 0;
}
