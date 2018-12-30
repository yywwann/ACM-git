#include<iostream>
#include<string>
#include<cstdio>
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

string Find,a;
int NEXT[4*maxn];
int ans[4*maxn];

void getNEXT() {
	int i = 0, j = NEXT[0] =-1;
	while (i<Find.size()){
		if (j == -1 || Find[i] == Find[j]) {
			i++;j++;
			NEXT[i] = j;
			
		}
		else {
			j = NEXT[j];
		}
	}
}

int main(){
	while(cin>>Find){
		getNEXT();
		//for(int i=0;i<=Find.size();i++) cout<<NEXT[i]<<' '; cout<<endl;
		int len=Find.size();
		int t=NEXT[len-1];
		int cnt=1;
		ans[0]=len;
		while(t!=-1){
			if(Find[t]==Find[len-1]) ans[cnt++]=t+1;
			t=NEXT[t];
		}
		for(int i=cnt-1;i>=0;i--) cout<<ans[i]<<' '; cout<<endl;
	}
	
	

	return 0;
}
