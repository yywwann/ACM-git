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



ll n,k;
ll ans;

int main(){
    cin>>n>>k;
    ans=n*k;
    ll a,b;
    for(int i=1;i<=n;i=b+1){
        a=k/i;
        if(a==0) break;
        b=k/a;
        if(b>n) b=n;
        ans-=a*(i+b)*(b-i+1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
