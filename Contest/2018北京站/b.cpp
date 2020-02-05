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

int n;
string str[20],t[20];
vector<string>v,ans;

int num[20000];
void dfs(string s,int pos,string t){
	if(pos==s.size()) v.push_back(t); 
	else{
		dfs(s,pos+1,t+s[pos]);
		dfs(s,pos+1,t);
	}
}
bool check(string t,string s){
	int len=0,pos=0;
	for(int i=0;i<t.size();i++){
		while(pos<s.size()){
			if(s[pos]==t[i]){
				len++;pos++;break;
			}
			pos++;
		}
	}
	return len==t.size();
}
int cmp(string a,string b){
	if(a.size()==b.size()) return a<b;
	return a.size()>b.size();
}
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(num,0,sizeof(num));
		v.clear();
		ans.clear();
		for(int i=1;i<=n;i++) cin>>str[i]; 
		string p=str[1]+str[1];
		for(int i=1;i<=str[1].size();i++){
			t[i]="";
			for(int j=0;j<str[1].size();j++) t[i]+=p[j+i-1]; 
			dfs(t[i],0,"");
		}
		for(int i=1;i<=n;i++) str[i]+=str[i]; 
		for(int i=0;i<v.size();i++){
			if(v[i]=="") continue;
			for(int j=1;j<=n;j++){
				for(int k=0;k<str[j].size()/2;k++){
					string T="";
					for(int l=0;l<str[j].size()/2;l++) T+=str[j][l+k]; 
					if(check(v[i],T)){
						num[i]++;break;
					} 
				}
			} 
			if(num[i]==n) ans.push_back(v[i]);
		}

		sort(ans.begin(),ans.end(),cmp);
		if(ans.size()==0) cout<<0<<endl;
		else cout<<ans[0]<<endl;
	}
	return 0;
}
