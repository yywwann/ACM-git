#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#include<algorithm>
using namespace std;
#define ll long long
#define PI acos(-1)
#define eps 1e-10
#define mem(x) memset(x,0,sizeof(x))
#define _for(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define __for(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD){ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}

const int INF=0x3f3f3f3f;
const int MAX=1.5*1e6+5;
const int MOD=1e9+7;

struct node{
	int sum,pos;
}dp[25][20000];

int n;
int a[25][25];
int size;
int ans[25][20000];
int vis[25];
int max_pos=-INF;
void dfs(int x,int cnt,int pos,int sum){
	if(cnt==n+1){
		dp[x][size].sum=sum;
		dp[x][size].pos=pos;
		size++;
		max_pos=max(max_pos,pos);
	}
	else{
		dfs(x,cnt+1,pos<<1,sum);
		if(vis[cnt-1]==0){
			vis[cnt]=1;
			dfs(x,cnt+1,pos<<1|1,sum+a[x][cnt]);
			vis[cnt]=0;
		}
	}
}

int main(){
    while(scanf("%d",&n)!=EOF){
    	mem(ans);
    	mem(dp);
    	size=0;
    	_for(i,1,n){
    		_for(j,1,n){
    			scanf("%d",&a[i][j]);
    		}
    	}
    	_for(i,1,n){
    		mem(vis);
    		size=0;
    		dfs(i,1,0,0);
    	}
    	_for(i,2,n){
    		_for(j,0,size-1){
    			int t=0;
    			_for(k,0,size-1){
    				if((dp[i-1][k].pos&dp[i][j].pos)==0){
    					t=max(t,dp[i-1][k].sum);
    				}
    			}
    			dp[i][j].sum+=t;
    		}    	
        }
        
    	int res=0;
    	_for(i,0,size-1){
    		res=max(res,dp[n][i].sum);
    	}
    	printf("%d\n",res);
    }


    return 0;
}