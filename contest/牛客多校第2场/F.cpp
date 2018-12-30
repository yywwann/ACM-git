#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1000000+5;

ll n,m,t,blo;
ll bl[maxn],a[maxn],tag[maxn];
ll MAX[maxn];

void update(ll l,ll r,ll c){
    for(int i=l;i<=min(bl[l]*blo,r);i++){
        if(a[i]!=c) a[i]=0;
    }
    for(int i=bl[l]+1;i<=bl[r]-1;i++){
        if(MAX[i]==0) continue;
        else{
            ll T=0;
            for(int j=i*blo;j<=(blo+1)*i-1;j++){
                if(a[j]!=c) a[j]=0;
                T=max(T,a[j]);
            }
            MAX[i]=T;
        }
    } 
    if (bl[l]!=bl[r]) for(int i=(bl[r]-1)*blo+1;i<=r;i++){
        if(a[i]!=c) a[i]=0;
    }
}

// ll val(ll x){ return a[x]+tag[bl[x]]; }

// ll querymin(ll l,ll r,ll c){
//     for(int i=l;i<=min(bl[l]*blo,r);i++){
//         if(val(i)==c) return i;
//     }

//     for(int i=bl[l]+1;i<=bl[r]-1;i++){
//         if(st[i].find(c-tag[i])==st[i].end()) continue;
//         for(int j=(i-1)*blo+1;j<=i*blo;j++){
//             if(val(j)==c) return j;
//         }
//     }

//     if (bl[l]!=bl[r]) for(int i=(bl[r]-1)*blo+1;i<=r;i++){
//         if(val(i)==c) return i;
//     }

//     return -1;
// }

// ll querymax(ll l,ll r,ll c){
//     for(int i=r;i>=max((bl[r]-1)*blo+1,l);i--){
//         if(val(i)==c) return i;
//     }

//     for(int i=bl[r]-1;i>=bl[l]+1;i--){
//         if(st[i].find(c-tag[i])==st[i].end()) continue;
//         for(int j=i*blo;j>=(i-1)*blo+1;j--){
//             if(val(j)==c) return j;
//         }
//     }

//     if (bl[l]!=bl[r]) for(int i=bl[l]*blo;i>=l;i--){
//         if(val(i)==c) return i;
//     }

//     return -1;
// }

ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main() {
    n=read();m=read();t=read();
    blo=sqrt(n);
    for(int i=1;i<=n*m;i++){
        a[i] = read();
        bl[i]=(i-1)/blo+1;//1...2..
        MAX[bl[i]]=max(MAX[bl[i]],a[i]);
    }
    while(t--){
        int x1=read(),y1=read(),x2=read(),y2=read(),tt=read();
        int M=y2-y1;
        for(int i=x1;i<=x2;i++){
            //cout<<(i-1)*m+y1<<' '<<(i-1)*m+y1+M<<endl;
            update((i-1)*m+y1,(i-1)*m+y2,tt);
            //cout<<n*m-tree[1].num<<endl;
        }
    }
    ll ans=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}