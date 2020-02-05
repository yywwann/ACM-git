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

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int a,b,x,y;
const double g=9.8;
void solve(){
	a=read(),b=read(),x=read(),y=read();
	a=a/gcd(a,b);
	b=b/gcd(a,b);
	x*=-1.0;
	a*=1.0;
	b*=1.0;
	y*=1.0;
	int ans=1;
	double vx=0,vy=0;
	double v0x=0,v0y=0;
	double _1y=y-x*1.0*b/a;
	v0y=sqrt(2*g*_1y);
	cout<<_1y<<' '<<v0y<<endl;
	while(1){
		cout<<v0x<<" "<<v0y<<endl;
		double _y=sqrt(v0y*v0y/(1+b*b/a/a))*b/a*2;
		double __y=sqrt(_y*_y/(1+b*b/a/a));
		vx=__y;
		vy=-1.0*sqrt(v0y*v0y-vx*vx);
		//vy=-1.0*sqrt(v0y*v0y/(1+b*b/a/a))*b/a+sqrt(v0x*v0x/(1+b*b/a/a));
		//vx=sqrt(v0y*v0y/(1+b*b/a/a))+sqrt(v0x*v0x/(1+b*b/a/a))*b/a;
		
		double A=0.5*g;
		double B=vy+b/a*vx;
		double C=0;
		double t=(-B+sqrt(B*B-4*A*C))/(2*A);
		double X=vx*t;
		x-=X;
		cout<<vx<<' '<<vy<<endl;
		cout<<A<<' '<<B<<' '<<C<<' '<<t<<' '<<x<<endl;
		if(x>0) ans++;
		else break;
		v0x=vx;
		v0y=vy+g*t;
		getchar();
	}
	cout<<ans<<endl;
}

int main(){
	for(int _=read();_;_--){
		solve();
	}
	return 0;
}
