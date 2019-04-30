#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 2e5+5;
 
int t;
int n, m, k;
int col[N], root[N];
int vis[N];
vector<int>v[N];
int find(int x){
    return x == root[x] ? x : root[x] = find(root[x]);
}
 
void Union(int x, int y){
    int fx = find(x);
    int fy = find(y);
    root[fx] = fy;
}
 
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++){
            scanf("%d", &col[i]);
            root[i] = i;
            vis[i] = 0;
            v[i].clear();
        }
        while(m--){
            int u, v;
            scanf("%d%d", &u, &v);
            Union(u, v);
        }
        for(int i = 1; i <= n; i++){
            root[i] = find(i);
            //cout << root[i] << endl;
            if(vis[root[i]]==0){
                vis[root[i]] = 1;
            }
            v[root[i]].push_back(col[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i] == 1 && v[i].size() > 1){
                sort(v[i].begin(), v[i].end());
                int tans = 0;
                for(int j = 0; j < v[i].size(); j++){
                    int x = v[i][j];
                    int pos = lower_bound(v[i].begin()+j, v[i].end(), x+1) - v[i].begin();
                    tans = max(tans, pos - j);
                    //cout << x << ' ' << pos << endl;
                }
                ans += v[i].size() - tans;
            }
        }
        cout << ans << endl;
    }
}
 