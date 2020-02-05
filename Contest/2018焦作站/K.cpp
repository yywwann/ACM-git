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

ll dp[10000+5],vv[25],c[25];
ll v=10000,s;
void ZeroOnePack(int cost){//01
	for(int j=v;j>=cost;j--){
		dp[j]=(dp[j]+dp[j-cost]+1)%MOD; 
	}
}

void CompletePack(int cost){//完全 
	for(int j=cost;j<=v;j++){
		dp[j]=(dp[j]+dp[j-cost]+1)%MOD; 
	}
}
 
void MultiplePack(int cost,int cnt){//多重 
	if(v<=cnt*cost){//如果总容量比这个物品的容量要小,那么这个物品可以直到取完,相当于完全背包.
		CompletePack(cost);
		return ;
	}
	else{//否则就将多重背包转化为01背包 
		int k=1;
		while(k<=cnt){
			ZeroOnePack(k*cost);
			cnt=cnt-k;
			k=2*k;
		}
		if(cnt>0)
		ZeroOnePack(cnt*cost);
	}
}

int n,q;

int main(){
	for(int _=read();_;_--){
		memset(dp,0,sizeof(dp));
		n=read(),q=read();
		for(int i=1;i<=n;i++){
			vv[i]=read(),c[i]=read();
			if(v/vv[i]<(1LL<<c[i])-1) c[i]=v/vv[i];
			else c[i]=(1LL<<c[i])-1;

			for(int b=0;b<v;b++){//枚举余数b
                head=tail=1;//清空队列，加在这里是因为只能从余数相同的状态转移来，之前队列中的元素都不需要了
                for(int j=0;j<=(N-b)/v;j++){
                    int tmp=dp[j*v+b]-j*w;//这里的dp是上一轮的，j代表s
                    while(head<tail&&tmp>=Q[tail-1][0]) --tail;//先插入以满足s≤min(n,a)的条件
                    Q[tail][0]=tmp,Q[tail++][1]=j;//这里j还是代表s
                    while(Q[head][1]<j-min(n,j)) ++head;//以下j代表a，删除队首以去除不满足a−min(n,a)≤s的状态
                    dp[j*v+b]=Q[head][0]+j*w;//队首即为最优
                }
            }
		}
		while(q--){
			s=read();
			cout<<dp[s]<<endl;
		}
	}	
	return 0;
}
