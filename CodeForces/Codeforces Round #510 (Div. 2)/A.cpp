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

ll n,m,a[N];
struct cmp1
{
     bool operator ()(int x, int y)
    {
        return x > y;//小的优先级高
    }
};
priority_queue<int, vector<int>, cmp1 >q;
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	ll MAX=a[n]+m;
	for(int i=1;i<=n;i++) q.push(a[i]);
	while(m--){
		ll t=q.top();
		q.pop();
		t++;
		q.push(t);
	}
	ll MIN=0;
	while(!q.empty()){
		ll t=q.top();
		q.pop();
		MIN=max(MIN,t);
	}
	cout<<MIN<<" "<<MAX<<endl;
	return 0;
}
