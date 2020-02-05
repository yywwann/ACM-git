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

vector<int>T;

int main(){
	for(int i=4;i<=75;i++){
		int t=1;
		for(int j=i;j>=i-3;j--){
			t*=j;
		}
		t/=24;
		T.push_back(t);
		cout<<i<<' '<<t<<endl;
	}
	for(int _=1;_<=1000000;_++){
		int n=_-1;
		while(n){
			int cnt=0;
			int t=0;
			int i=0;
			for(i=0;i<T.size();i++){
				if(T[i]<=n) t=T[i];
				else break; 
			}
			n-=t;
			if(cnt==0) cnt+=i;
			else cnt+=1;
		}cout<<endl;
	}
	
	return 0;
}
