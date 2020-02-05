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

int main(){
	for(int _=read(); _; _--){
		n=read(), m=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j+=2){
				if(i%2==0){
					if(j==m){
						cout<<')';
					}
					else{
						if(j%4==1) cout<<"((";
						else cout<<"))";
					}
				}
				else{
					if(j==m) cout<<"(";
					else{
						cout<<"()";
					}
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
