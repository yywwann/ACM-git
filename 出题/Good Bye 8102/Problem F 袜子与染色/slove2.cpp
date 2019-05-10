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
#define pb push_back
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define clr(a,b) memset(a,b,sizeof(a)
#define bugc(_) cerr << (#_) << " = " << (_) << endl
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const int N=2e5+10;
typedef long long ll;
typedef unsigned long long ull;
int fa[N],col[N];
bool vis[N];
vector <int> V;
vector <int> E[N];
map <int,int> cnt;
 
int fi(int x){
    return fa[x]==x?x:fa[x]=fi(fa[x]);
}
 
void init(){
    V.clear();
    for(int i=0;i<N;i++) fa[i]=i,E[i].clear(),vis[i]=false;
}
 
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        int n,m,k,ans=0;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++) scanf("%d",&col[i]);
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            int fx=fi(u),fy=fi(v);
            if(fx!=fy){
                fa[fx]=fy;
            }
        }
        for(int i=1;i<=n;i++) fa[i]=fi(i);
        for(int i=1;i<=n;i++){
            if(!vis[fa[i]]) vis[fa[i]]=true,V.push_back(fa[i]);
            E[fa[i]].push_back(col[i]);
        }
        int sz=V.size();
        for(int i=0;i<sz;i++){
            int mx=0;
            int szz=E[V[i]].size();
            cnt.clear();
            for(int j=0;j<szz;j++){
                cnt[E[V[i]][j]]++;
                mx=max(mx,cnt[E[V[i]][j]]);
            }
            ans+=(szz-mx);
        }
        printf("%d\n",ans);
    }
    return 0;
}