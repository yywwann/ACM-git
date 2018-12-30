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

ll m,n;
int wa[35];
int ans;
int ask(int mid){
	cout<<mid<<endl;
	fflush(stdout);
	cin>>ans;
	return ans;
}


int main(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		int t=ask(1);
		if(t==0) exit(0);
		if(t==1) wa[i]=1;
		if(t==-1) wa[i]=-1;
	}
	//int L=1,R=m;
	int l=1,r=m;
	for(int t=0;t<30;t++){
		int mid=(l+r)/2;
		int tt=ask(mid);
		if(tt==0){
			exit(0);
		}
		tt*=wa[t%n];
		if(tt==1){
			l=mid+1;
			//L=mid+1;
		}
		if(tt==-1){
			r=mid-1;
			//R=mid-1;
		}
		
	}
	return 0;
}
