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

int n,m;
int a[1005];
int b[1005];

int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int j=1;j<=m;j++) b[j]=read();
    int ans=0;
    int pos=1;
    for(int i=1;i<=n;i++){
        if(b[pos]>=a[i]){
            ans++;
            pos++;
        }
        if(pos==m+1) break; 
    }
    cout<<ans<<endl;
    return 0;
}
