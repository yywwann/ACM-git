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
vector <LL> p;

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
    p.clear();
    for(LL i=2;i*i<=m;i++){
        if(m%i==0){
            p.push_back(i);
            while(m%i==0) m/=i;
        }
    }
    if(m>1) p.push_back(m);
    int len=p.size();
    for(LL i=1;i<(1<<len);i++){
        LL num=1;
        for(LL j=0;j<len;j++){
            if(i&(1<<j)){
                num*=p[j];
            }
        }
        LL tmp=num;
        while(num<=n){
            ans=(ans+MOD-(num*(num+1)%MOD))%MOD;
            num=num+tmp;
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