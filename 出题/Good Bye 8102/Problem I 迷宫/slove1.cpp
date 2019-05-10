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
 
int n, m, sx, sy, tx, ty, vis[50][50];
char g[50][50];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 2, 0, -2};
 
struct node{
    int x, y, step;
    node(int _x, int _y, int _step){
        x = _x, y = _y, step = _step;
    }
};
 
int bfs(int sx, int sy){
    queue<node>q;
    q.push(node(sx, sy, 0));
    vis[sx][sy] = 1;
    while(!q.empty()){
        node u = q.front(); q.pop();
        int x = u.x;
        int y = u.y;
        int step = u.step;
        if(g[x][y] == 'T') return u.step;
        for(int i = 0; i < 4 ;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(g[xx][yy] == ' ' && vis[xx][yy] == 0){
                vis[xx][yy] = 1;
 
                q.push(node(xx+dx[i], yy+dy[i], step+1));
            }
        }
    }
    return -1;
}
 
int main(){
    for(int _ = read(); _; _--){
        scanf("%d %d",&n, &m);
        getchar();
        for(int i = 0; i < 2*n+1; i++){
            gets(g[i]);
            for(int j = 0; j < 4*m+1; j++){
                vis[i][j] = 0;
                if(g[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                if(g[i][j] == 'T'){
                    tx = i;
                    ty = j;
                }
            }
        }
        cout << bfs(sx, sy) << endl;
 
 
    }
    return 0;
}