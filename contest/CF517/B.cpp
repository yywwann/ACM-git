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

int n,a[N],b[N],t[N],flg;

//ai=ti|ti+1
//bi=ti&ti+1
// ti [0,3]

int main(){
// 	for(int i=0;i<=3;i++){
// 		for(int j=0;j<=3;j++){
// 			if((i|j)>=0&&(i|j)<=3){
// 				cout<<i<<' '<<j<<' '<<(i|j)<<endl;
// 			}
// 		}
// 	}
// 	cout<<endl;
// 	for(int i=0;i<=3;i++){
// 		for(int j=0;j<=3;j++){
// 			if((i&j)>=0&&(i&j)<=3){
// 				cout<<i<<' '<<j<<' '<<(i&j)<<endl;
// 			}
// 		}
// 	}
	n=read();
	for(int i=1;i<n;i++) a[i]=read();
	for(int i=1;i<n;i++) b[i]=read();
	for(int i=0;i<=3;i++){
		t[0]=i;
		flg=1;
		for(int j=1;j<n;j++){
			for(int k=0;k<=3;k++){
				if((t[j-1]|k)==a[j]&&(t[j-1]&k)==b[j]){
					t[j]=k;
					break;
				}
				if(k==3) flg=0;
			}
			if(flg==0) break;
		}
		if(flg==1) break;
	}
	if(flg){
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++) cout<<t[i]<<' ';
	}
	else cout<<"NO"<<endl;
	return 0;
}
