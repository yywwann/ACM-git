#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf  = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

int t;
int n;
struct node{
	ll x,y,id;
}a[3000+5];

int cmp(node a,node b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

int main(){
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++){
			a[(i-1)*3+1].x=read();a[(i-1)*3+1].y=read();a[(i-1)*3+1].id=(i-1)*3+1;
			a[(i-1)*3+2].x=read();a[(i-1)*3+2].y=read();a[(i-1)*3+2].id=(i-1)*3+2;
			a[(i-1)*3+3].x=read();a[(i-1)*3+3].y=read();a[(i-1)*3+3].id=(i-1)*3+3;
		}
		sort(a+1,a+1+3*n,cmp);
		for(int i=1;i<=n;i++){
			cout<<a[(i-1)*3+1].id<<" "<<a[(i-1)*3+2].id<<" "<<a[(i-1)*3+3].id<<endl;
		}
	}
	return 0;
}
