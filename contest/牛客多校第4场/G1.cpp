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
 
int t;
int n,m;
map<ll,ll>num;
std::vector<ll> v[maxn];
std::vector<ll> a;
ll sum[maxn];
ll cnt[maxn];
int main(){
    t=read();
    while(t--){
        num.clear();
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        a.clear();
        n=read(),m=read();
        for(int i=0;i<n;i++){
            v[i+1].clear();
            ll aa=read();
            a.push_back(aa);
            num[aa]++;
        }
        //cout<<a.size()<<endl;
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        //cout<<a.size()<<endl;
        ll MAXN=0;
        for(int i=a.size()-1;i>=0;i--){
            //cout<<a[i]<<' ';
            cnt[i]=num[a[i]];
            MAXN=max(MAXN,cnt[i]);
            v[cnt[i]].push_back(a[i]);
        }//cout<<endl;
        for(int i=MAXN;i>=1;i--){
            sum[i]=sum[i+1]+i*v[i].size();
        }
        for(int i=a.size()-1;i>=0;i--){
            if(sum[cnt[i]+1]+((sum[cnt[i]]-sum[cnt[i]+1])/cnt[i])-1<=m){
                cout<<a[i]<<endl;
                break;
            }
            if(i==0){
                cout<<-1<<endl;
            }
        }
 
    }
    return 0;
}