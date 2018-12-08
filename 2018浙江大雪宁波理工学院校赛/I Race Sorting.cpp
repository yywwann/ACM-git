#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>               //    ____   _   _  __   __
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

ll n;
map<string, int> mp;
struct node{
    ll pos;
    ll id;
    string type;
}a[1005];

bool cmp(node a, node b){
    if(a.type == b.type){
        return a.pos < b.pos;
    }
    return mp[a.type] < mp[b.type];
}

int main(){
    for(int _ = read(); _; _--){
        n = read();
        string t ;
        mp.clear();
        for(int i = 1; i <= n; i++){
            a[i].pos = i;
            a[i].id = read();
            cin >> t;
            cin >> t;
            a[i].type = t;
        }
        cin >> t;
        string s = "";
        int cnt = 1;
        for(int i = 0; i < t.size(); i++){
            s = "";
            while(t[i] != ',' && i < t.size()){
                s += t[i];
                i++;
            }
            mp[s] = cnt++;
            //cout << s << endl;
        }
        sort(a+1, a+1+n, cmp);
        for(int i = 1; i <= n; i++){
            if(i == 1) cout << a[i].id;
            else cout << " " << a[i].id;
        }cout << endl;
    }
    return 0;
}
