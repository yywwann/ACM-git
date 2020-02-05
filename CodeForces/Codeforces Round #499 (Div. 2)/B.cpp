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

int n,m;
int a[105];
int num[105];

bool check(int x){
	int t=0;
	for(int i=1;i<=100;i++){
		if(num[i]>=x){
			t+=num[i]/x;
		}
	}
	if(t>=n) return true;
	return false;
}

int main(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		a[i]=read();
		num[a[i]]++;
	}
	for(int i=100;i>=1;i--){
		if(check(i)){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}
