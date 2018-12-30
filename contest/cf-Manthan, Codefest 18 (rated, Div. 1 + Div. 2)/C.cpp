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

int n, ans;
char a[10*N], b[10*N];

int main(){
	n = read();
	cin >> a >> b;
	for(int i=0; i<n-1; i++){
		if(a[i]=='1'&&a[i+1]=='0'&&b[i]=='0'&&b[i+1]=='1'){
			swap(a[i], a[i+1]);
			ans++;
		}
		else if(b[i]=='1'&&b[i+1]=='0'&&a[i]=='0'&&a[i+1]=='1'){
			swap(a[i], a[i+1]);
			ans++;
		}
	}
	for(int i=0; i<n; i++){
		if(a[i] != b[i]) ans++;
	}
	cout<< ans <<endl;
	return 0;
}
