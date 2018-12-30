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
int a[200];
int main(){
	cin>>s;
	for(int i=1;i<=5;i++){
		cin>>s;
		a[s[i]-'a']++;
		cout<<s[i]<<' '<<a[s[i]-'a']<<endl;
	}
	return 0;
}
