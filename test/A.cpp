#include <iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000000005
int xi[]={-1,0,1,0};
int yi[]={0,-1,0,1};
int m,n;
struct cmp
{
    int x,y,juli;
    cmp(int x, int y, int juli){
      this->x = x;
      this->y = y;
      this->juli = juli;
    }
};
deque<cmp>Q;
int vis[505][505];
char dp[505][505];
void init()
{
    while(!Q.empty())
    Q.pop_front();
    memset(vis,0,sizeof(vis));
}
int cha(int x,int y)
{
    if(x<0||y<0||x>m-1||y>n-1||vis[x][y]==1)
    return 0;
    else
    return 1;
}
int bfs(int x,int y)
{
    Q.push_back(cmp(x,y,0));
    int i,xx,yy;
    vis[x][y]=1;
    while(!Q.empty())
    {
        cmp A=Q.front();
        Q.pop_front();
        for(i=0;i<4;i++)
        {
             xx=A.x+xi[i];
             yy=A.y+yi[i];
            if(cha(xx,yy)==1)
            {
                if(dp[xx][yy]=='I')
                {
                    if(A.juli==0)
                    Q.push_front(cmp(xx,yy,A.juli));
                    else
                    return A.juli;
                }
                else if(dp[xx][yy]=='S')
                Q.push_front(cmp(xx,yy,A.juli));
                else
                Q.push_back(cmp(xx,yy,A.juli+1));
                vis[xx][yy]=1;
            }
        }
    }
    return 0;
}
int main()
{
    int T;
    while(cin>>T)
    {
        while(T--)
        {
            init();
            int i,j,biaoji=0;
             cin>>m>>n;
             init();
             for(i=0;i<m;i++)
             {
                for(j=0;j<n;j++)
                 {
                    cin>>dp[i][j];
                 }
             }
             for(i=0;i<m;i++)
             {
                for(j=0;j<n;j++)
                {
                    if(dp[i][j]=='I'){
                      cout<<bfs(i,j)<<endl;
                      biaoji=1;
                      break;
                    }

                }
                if(biaoji==1)
                break;
             }

        }
    }
    return 0;
}
