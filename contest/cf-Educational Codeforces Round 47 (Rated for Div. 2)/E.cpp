#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf  = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}
const ll mod=998244353;
int n;
ll a[maxn*10];
ll _2[maxn*10];

int main(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    ll ans=0;
    _2[0]=1;
    for(int i=1;i<=n;i++){
        _2[i]=(2*_2[i-1])%mod;
    }
    ll p=0;
    for(int i=1;i<=n;i++){
        p+=(a[i]*_2[n-i])%mod;
        p%=mod;
        p+=(a[i]*(_2[n-i-1]*(n-i)%mod))%mod;
        p%=mod;
    }
    cout<<p<<endl;
    return 0;
}
