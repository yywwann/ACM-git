//G
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define eps 1e-8
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define FAST_IO ios::sync_with_stdio(false)

typedef long long LL;
const LL MOD=1e9+7;
const int N=1e4+10;
bool vis[N];

LL fast_power(LL x,LL n,LL mod){
    LL ans=1;
    x%=mod;
    while(n){
        if(n&1) ans=(ans*x)%mod;
        n>>=1;
        x=(x*x)%mod;
    }
    return ans;
}

LL solve(LL n,LL m){
     LL ans=n*(n+1)%MOD;
     ans=(ans*(2*n+4)%MOD)*fast_power(6,MOD-2,MOD)%MOD;

    memset(vis,0,sizeof(vis));
    //LL ans=1;
    for(LL i=2;i*i<=m;i++){
        if(vis[i]) continue;
        if(m%i==0){
            for(LL j=i;j<=n;j+=i){
                if(j<N) vis[j]=true;
                ans=(ans+MOD-(j*(j+1)%MOD))%MOD;
                //cout<<j<<endl;
            }
        }
    }
    return ans%MOD;
}

int main(){
    LL n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        printf("%lld\n",solve(n,m));
    }
    return 0;
}
