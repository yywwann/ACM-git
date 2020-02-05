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

double a,b;
char s[1000];
const double arcsin1=asin(1.0);
int main(){
	int _=read();
	while(_--){
		cin>>a>>b;
		double ans=2*a*(arcsin1+0.5*sin(2*arcsin1))+2*b;
		sprintf(s,"%.10f",ans);
		for(int i=0;s[i];i++){
			if(s[i]=='.'){
				for(int j=i;j<=i+6;j++){
					cout<<s[j];
				}cout<<endl;
				break;
			}
			cout<<s[i];
		}
		//cout << fixed << setprecision(6) << 2*b+a*pi << endl;
		//cout<<a<<' '<<b<<endl;
		//printf("%.6f\n",2*a*(arcsin1+0.5*sin(2*arcsin1))+2*b);
	}
	return 0;
}
