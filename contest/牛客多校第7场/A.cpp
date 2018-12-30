#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf  = 0x3f3f3f3f;
const ll maxn = 5e5;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

vector<int>_2;
int bit[500000+5];
vector<int>ans[500000];
void init(){
	int t=1;
	_2.push_back(t);
	while(t<=maxn){
		t*=2;
		_2.push_back(t);
	}
	int pos=0;
	for(int i=0;i<=500000;i++){
		bit[i]=pos+1;
		if(i+1==_2[pos+1]) pos++;
	}
}

int main(){

	init();
	int n=read(); n--
	 
	int pos=0;
	int i;
	for(i=n;i>0;){
		int j=i;
		while(j>=0&&bit[j]==bit[i]) j--;
		int cnt=i-j;
		for(j=i;j>=i-cnt*2+1&&j>=0;j--){
 			ans[pos].push_back(j);
		}
		pos++;
		i=j;
	}	
	if(i==0) ans[pos].push_back(0);
	for(i=pos;i>=0;i--){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<' ';
		}
	}
	return 0;
}
