#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 1e4+5;           //   \____| |_| |_|   |_|     
const ll MOD = 256;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

bool Num[N][256],Flg;
int n,Now,Val;
struct Node{
	int a,b;
	string ope;
}a[N];

void solve(){
	Now=1,Val=0;
	Flg=true;
	while(Now<=n){
		if(!Num[Now][Val]) Num[Now][Val]=true;
		else{
			Flg=false; break;
		}
		if(a[Now].ope=="add"){
			Val=(Val+a[Now].a)%MOD;
			Now++;
		}	
		else{
			if(a[Now].ope=="beq"){
				if(Val==a[Now].a) Now=a[Now].b;
				else Now++;
			}
			else if(a[Now].ope=="bne"){
				if(Val!=a[Now].a) Now=a[Now].b;
				else Now++;
			}
			else if(a[Now].ope=="blt"){
				if(Val<a[Now].a) Now=a[Now].b;
				else Now++;
			}
			else if(a[Now].ope=="bgt"){
				if(Val>a[Now].a) Now=a[Now].b;
				else Now++;
			}
		}
	}
	if(!Flg) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}

void input(){
	memset(Num,false,sizeof(Num));
	n=read();
	for(int i=1;i<=n;i++){
		cin>>a[i].ope;
		if(a[i].ope=="add") a[i].a=read();
		else a[i].a=read(), a[i].b=read();
	}
}

int main(){
	for(int _=read();_;_--){
		input();
		solve();
	}
	return 0;
}

