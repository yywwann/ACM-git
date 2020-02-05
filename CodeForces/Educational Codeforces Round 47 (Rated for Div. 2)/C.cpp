// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const ll inf  = 0x3f3f3f3f;
// const ll maxn = 1e5+5;
// ll read(){
//     ll x=0,f=1;char ch=getchar();
//     while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
//     while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
//     return x*f; 
// }

// ll n,m;
// ll x[maxn],d[maxn];

// int main(){
// 	n=read();
// 	m=read();
// 	for(int i=1;i<=m;i++) x[i]=read(),d[i]=read();
// 	double ans=0;
// 	for(int i=1;i<=m;i++){
// 		if(d[i]>0){
// 			ans+=(n*x[i])+d[i]*(0+n-1)*n/2;
// 		}
// 		else{
// 			ans+=n*x[i];
// 			if(n%2==0){
// 				ans+=d[i]*((0+n/2)*(n/2+1)-n/2);
// 			}
// 			else{
// 				ans+=d[i]*(0+n/2)*(n/2+1);
// 			}
// 		}
// 	}
// 	printf("%.10lf\n",ans/n); 
// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long a[100005];
long long b[100005];
//int ans[100005];

int main()
{
	long long n,m;
	cin>>n>>m;
	long long sum=0;
	long long ans=0;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<n;i++){
		sum+=i;
	}
	long long summ=0;
	summ=(n+1)/2;
	long long op=0;
	for(int i=1;i<=n;i++){
		op+=abs(summ-i);
	}
	for(int i=1;i<=m;i++){
		if(b[i]<0) ans+=a[i]*n+op*b[i];
		else
			ans+=a[i]*(n)+sum*(b[i]);
	}
	double anss=ans*1.0/n;
	cout<<fixed<<setprecision(9)<<anss<<endl;
	return 0;
}