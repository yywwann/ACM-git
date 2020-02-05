#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int N=2e6+20;
const ll inf=2e15;
ll n,m,num;
map<ll,ll> mp[N];
vector<ii> e[N];
ll inq[N],d[N];
queue<int> q;
int getid(int u,int c)
{
	if(mp[u][c]==0)
		mp[u][c]=++num;
	return mp[u][c];
}
void SPFA(int s,int t)
{
	for(int i=1;i<=num;i++)
		d[i]=inf,inq[i]=0;
	q.push(s);
	d[s]=0,inq[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop(),inq[u]=0;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].first,w=e[u][i].second;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!inq[v])
					inq[v]=1,q.push(v);
			}
		}
	}
	printf("%lld\n",d[t]>=inf?-1:d[t]/2);
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<=n;i++)
			e[i].clear();
		int u,v,c;
		num=n;
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&c);
			int uc=getid(u,c);
			int vc=getid(v,c);
			e[u].push_back(ii(uc,1));
			e[uc].push_back(ii(u,1));
			e[v].push_back(ii(vc,1));
			e[vc].push_back(ii(v,1));
			
			e[uc].push_back(ii(vc,0));
			e[vc].push_back(ii(uc,0));		
		}
		SPFA(1,n);
		
		for(int i=0;i<=num;i++)
			mp[i].clear();
	}
	return 0;
}
