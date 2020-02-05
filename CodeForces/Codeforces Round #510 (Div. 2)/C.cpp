#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 2e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

ll n;
struct node{
    ll val,id,flg;
}a[N];
vector<node>_1,_0;
int cmp(node a,node b){
    if(a.val==b.val) return a.id<b.id;
    return a.val<b.val;
}

int cmp1(node a,node b){
    return a.id<b.id;
}

int main(){
    n=read();
    int fu=0;
    for(int i=1;i<=n;i++){
        a[i].val=read();
        a[i].id=i;
        if(a[i].val<0) fu++;
    }
    if(fu%2==1){
        int pos=0;
        ll MIN=-INF;
        for(int i=1;i<=n;i++){
            if(a[i].val<0&&MIN<a[i].val){
                MIN=a[i].val;
                pos=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i].val==0||a[i].id==pos) _0.push_back(a[i]);
            else _1.push_back(a[i]);
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i].val==0) _0.push_back(a[i]);
            else _1.push_back(a[i]);
        }
    }
    
    if(_0.size()>=1){
        int last=_0[0].id;
        for(int i=1;i<_0.size();i++){
            cout<<1<<" "<<last<<" "<<_0[i].id<<endl;
            last=_0[i].id;
        }
        if(_1.size()>=1){
            cout<<2<<' '<<last<<endl;
            last=_1[0].id;
            for(int i=1;i<_1.size();i++){
                cout<<1<<" "<<last<<" "<<_1[i].id<<endl;
                last=_1[i].id;
            }
        }
        
    }
    else{
        int last=_1[0].id;
        for(int i=1;i<_1.size();i++){
                cout<<1<<" "<<last<<" "<<_1[i].id<<endl;
                last=_1[i].id;
            }
    }
    


    return 0;
}
