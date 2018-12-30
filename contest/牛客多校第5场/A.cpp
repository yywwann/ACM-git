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

ll n,k;
struct node{
	double s,c;
}a[maxn];
double t[maxn];

bool c(double x){
	for(int i=1;i<=n;i++){
		t[i]=a[i].c-x*a[i].s;
	}
	sort(t+1,t+1+n);
	double sum=0;
	for(int i=1;i<=n-k;i++){
		sum+=t[n-i+1];
	}
	return sum>=0;
}

int main(){
	n=read();k=read();
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i].s);
	}
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i].c);
		a[i].c*=a[i].s;
	}
	double l=0,r=1e9;
	double ans=0;
	for(int _=0;_<50;_++){
		double mid=(l+r)/2;
		if(c(mid)){
			ans=mid;
			l=mid;
		}
		else{
			r=mid;
		} 
	}
	printf("%.10f",ans);
	return 0;
}
