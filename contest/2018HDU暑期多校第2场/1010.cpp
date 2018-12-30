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

ll n,x,y;
ll a[maxn];
//逆序对
ll ans,c[maxn]; 
void f(int l,int r) 
{ 
    int mid=(l+r)/2,i,j,tmp; 
    if(r>l) 
    { 
        f(l,mid); 
        f(mid+1,r); 
        tmp=l; 
        for(i=l,j=mid+1;i<=mid&&j<=r;) 
        { 
            if(a[i]>a[j]) 
            { 
                c[tmp++]=a[j++]; 
                ans+=mid-i+1; 
            } 
            else c[tmp++]=a[i++]; 
        } 
        if(i<=mid) for(;i<=mid;) c[tmp++]=a[i++]; 
        if(j<=r) for(;j<=r;) c[tmp++]=a[j++]; 
        for(i=l;i<=r;i++) a[i]=c[i]; 
    } 
}
int main(){
	while(cin>>n){
		ans=0;
		memset(c,0,sizeof(c));
		x=read(),y=read();
		for(int i=1;i<=n;i++) a[i]=read();
		f(1,n);
		cout<<min(x*ans,y*ans)<<endl;
	}
	return 0;
}
