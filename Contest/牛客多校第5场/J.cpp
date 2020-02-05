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

ll n,p2,p3;
vector<ll>ans;
int main(){
	n=read();p2=read();p3=read();
	ans.push_back(((n+1)/2)*p2);
	ans.push_back(((n+2)/3)*p3);
	ans.push_back((n/3)*p3+p2);
	if(n>=3){
		ans.push_back(p3+((n-3)+1)/2*p2);
	}
	if(n>=4){
		ans.push_back(2*p2+((n-4)+2)/3*p3);
	}
	cout<<*min_element(ans.begin(),ans.end())<<endl;
	return 0;
}
