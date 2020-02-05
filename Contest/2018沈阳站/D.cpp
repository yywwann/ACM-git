#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 1e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}
ll dis[N];
struct node {
    ll v, c;
    node (ll _v = 0, ll _c = 0) : v(_v), c(_c) {}
    bool operator < (const node &rhs) const {
        return c + dis[v] > rhs.c + dis[rhs.v];
    }
};
 
struct edge {
    ll v, cost;
    edge (ll _v = 0, ll _cost = 0) : v(_v), cost(_cost) {}
};

ll s, t, k, ti;
bool vis[N];

vector<edge>E[N], revE[N];


void addedge(ll u, ll v, ll w) {
    revE[u].push_back(edge(v, w));
    E[v].push_back(edge(u, w));
}

ll astar(ll s) {
    priority_queue<node> q;
    q.push(node(s, 0)); k--;
    while (!q.empty()) {
        node pre = q.top(); q.pop();
        ll u = pre.v;
        if (u == t) {
            if (k) k--;
            else return pre.c;
        }
        for (ll i = 0; i < (ll)revE[u].size(); i++) {
            ll v = revE[u][i].v;
            ll c = revE[u][i].cost;
            q.push(node(v, pre.c + c));
        }
    }
    return -1;
}
 
void CHYdafa(ll n, ll s) {
    memset(vis, false, sizeof(vis));
    for (ll i = 1; i <= n; i++) dis[i] = INF;
    priority_queue<node>q;
    dis[s] = 0;
    q.push(node(s, 0));
    while (!q.empty()) {
        node tep = q.top(); q.pop();
        ll u = tep.v;
        if (vis[u]) continue;
        vis[u] = true;
        for (ll i = 0; i < (ll)E[u].size(); i++) {
            ll v = E[u][i].v;
            ll cost = E[u][i].cost;
            if (!vis[v] && dis[v] > dis[u] + cost) {
                dis[v] = dis[u] + cost;
                q.push(node(v, dis[v]));
            }
        }
    }
}
 

void init(int n){
    for (ll i = 0; i <= n; i++) {
        E[i].clear();
        revE[i].clear();
    }
} 
int main() {
    ll n, m, u, v, w;
    while(cin>>n){
        m=read();
        init(n);
        s=read(), t=read(), k=read(), ti=read();
        for (ll i = 0; i < m; i++) {
            u=read(), v=read(), w=read();
            addedge(u, v, w);
        }
        if (s == t) k++;
        CHYdafa(n, t);
        if (dis[s] == INF) {
            cout<<"Whitesnake!"<<endl;
            continue;
        }
        ll ans=astar(s);
        //cout<<ans<<endl;
        if(ans==-1||ans>ti)  cout<<"Whitesnake!"<<endl;
        else cout<<"yareyaredawa"<<endl;
    }
    return 0;
}