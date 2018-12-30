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

int n;
char g[5][5];
char op[2];

void C(int x,int y){
	swap(g[x][y], g[x+1][y+1]);//for(int i=0;i<3;i++) cout<<g[i]<<endl;
	//swap(g[x][y+1], g[x+1][y]);for(int i=0;i<3;i++) cout<<g[i]<<endl;
	swap(g[x][y], g[x+1][y]);//for(int i=0;i<3;i++) cout<<g[i]<<endl;
	swap(g[x][y+1], g[x+1][y+1]);//for(int i=0;i<3;i++) cout<<g[i]<<endl;
}

void R(int x,int y){
	swap(g[x][y], g[x+1][y+1]);
	//swap(g[x][y+1], g[x+1][y]);
	swap(g[x][y], g[x][y+1]);
	swap(g[x+1][y], g[x+1][y+1]);
}

int main(){
	for(int _=read(); _; _--){
		cin>>n;
		for(int i=0;i<3;i++) cin>>g[i];	
		
		while(n--){
			scanf("%s",op);
			int x,y;
			if(op[0]-'0'==1) x=0,y=0;
			if(op[0]-'0'==2) x=0,y=1;
			if(op[0]-'0'==3) x=1,y=0;
			if(op[0]-'0'==4) x=1,y=1;
			if(op[1]=='C') C(x,y);
			else R(x,y);

		}
		for(int i=0;i<3;i++) printf("%s\n",g[i]);
	}
	return 0;
}
