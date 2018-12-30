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

int n;
int m;
double a[1005],b[1005];
const double eps=1e-9;

bool is0(double x,double m){
	if(x-m<eps) return true;
	return false;
}

bool check(double x){
	double all=m+x;
	double t;
	for(int i=1;i<=n;i++){
		if(i==1){
			t=all/a[i];
			all-=t;

		}
		else if(i==n){
			t=all/b[i];
			all-=t;
		}
		else{
			t=all/b[i];
			all-=t;
			if(is0(all,m)) return false;
			t=all/a[i];
			all-=t;
		}
		if(is0(all,m)) return false;
	}
	t=all/a[n];
	all-=t;
	if(is0(all,m)) return false;
	t=all/b[1];
	all-=t;
	if(is0(all,m)) return false;
	return true;
}

int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
		if(a[i]==1){
			cout<<-1<<endl;
			return 0;
		}

	}
	for(int i=1;i<=n;i++){
		scanf("%lf",&b[i]);
		if(b[i]==1){
			cout<<-1<<endl;
			return 0;
		}
	}
	double l=0,r=1e9;
	double ans=-1;
	for(int t=1;t<=1000;t++){
		double mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid;
		}
		else{
			l=mid;
		}
	}
	//if(!is0(ans,1e9)) cout<<-1<<endl;
	printf("%.10f",ans);
	return 0;
}
