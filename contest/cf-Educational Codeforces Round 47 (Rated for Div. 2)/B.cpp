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

string s;

int main(){
	while(cin>>s){
		int len=s.size();
		int _1=0;
		for(int i=0;i<len;i++){
			if(s[i]=='1') _1++;
		}
		for(int i=0;i<len;i++){
			if(_1>0&&s[i]=='2'){
				for(int j=0;j<_1;j++) cout<<1;
				_1=0;
			}
			if(s[i]!='1') cout<<s[i];
		}
		if(_1>0){
			for(int i=0;i<_1;i++){
				cout<<1;
			}
		}cout<<endl;
	}
	
	return 0;
}
