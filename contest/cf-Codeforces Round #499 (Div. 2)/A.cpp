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

int n,k;
string s;
int mp[200];
int main(){
	n=read();k=read();
	cin>>s;
	sort(s.begin(),s.end());
	//cout<<s<<endl;
	ll ans=0;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(mp[s[i]]==0&&mp[s[i]-1]==0&&t<k){
			t++;
			ans+=s[i]-'a'+1;
			//cout<<s[i]<<' '<<ans<<endl;
			for(int j='a';j<=s[i];j++) mp[j]=1;
		}
	}
	if(t==k) cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}
