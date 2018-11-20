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

int n, q, a[N];
vector<int> v;
int root[N], cnt;
struct node{
    int l,r;
    int sum;
}T[N*40];

int getid(int x){
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void update(int l, int r, int &cur, int pre, int pos){
    T[++cnt] = T[pre], T[cnt].sum++, cur = cnt;
    if(l == r) return;
    int mid = (l+r) / 2;
    if(mid >= pos) update(l, mid, T[cur].l, T[pre].l, pos);
    else update(mid+1, r, T[cur].r, T[pre].r, pos);
}

int queryNUM(int l,int r,int x,int y,int A,int B){
        if(r < A || l > B) return 0;
        //cout<<"l="<<l<<" r="<<r<<" "<<tree[y].sum-tree[x].sum<<endl;
        if(A <= l && r <= B) return T[y].sum - T[x].sum;
        int mid = (l+r) >> 1;
        return queryNUM(l, mid, T[x].l, T[y].l, A, B) + queryNUM(mid+1, r, T[x].r, T[y].r, A, B);
}

int main(){
    //for(int _ = read(), CASE = 1; _; _--){

        n = read(), q = read();
        cnt = 0 ;
        v.clear();
        for(int i = 1; i <= n; i ++){
            a[i] = read();
            v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        root[0]=0;
        for(int i = 1; i <= n; i++){
            update(1, n, root[i], root[i-1], getid(a[i]));
        }
        //printf("Case %d:\n", CASE++);
        while(q--){
            int l = read(), r=read(), val=read();
            
            int A = 1, B = getid(val);
            if(v[B-1] > val) B--;
            if(B < 1) printf("0\n");
            else printf("%d\n", queryNUM(1, n, root[l-1], root[r], A, B));
        }
    //}

    return 0;
}
