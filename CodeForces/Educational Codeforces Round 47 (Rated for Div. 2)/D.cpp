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

ll n,m;
vector<int>v[maxn];
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    while(cin>>n>>m){
        if(m<n-1){
            cout<<"Impossible"<<endl;
            continue;
        }
        int M=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(gcd(i,j)==1){
                    M++;
                    v[i].push_back(j);
                }
                if(M==m) break;
            }
            if(M==m) break;
        }
        if(M==m){
            cout<<"Possible"<<endl;
            for(int i=1;i<=n;i++){
                for(int j=0;j<v[i].size();j++){
                    cout<<i<<' '<<v[i][j]<<endl;
                    M--;
                    if(M==0) break;
                }
                if(M==0) break;
            }
        }
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
