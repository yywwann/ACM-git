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

char str1[N],str2[N];
ll dp1[N],dp2[N],len;
ll num1[N],num2[N];
int main(){
	for(int _=read();_;_--){
		scanf("%s",str1);
		len=strlen(str1);
		for(int i=0;i<len;i++){
			if(str1[i]=='0') str2[i]='1';
			else str2[i]='0';
		}
		for(int i=0;i<len;i++){
			if(str1[i]=='1') dp1[i]=1;
			else dp1[i]=2;
			if(str2[i]=='1') dp2[i]=1;
			else dp2[i]=2;
		}
		for(int i=0;i<len;i++){
			num1[i]=num2[i]=0;
			if(i==0) num1[i]=len-i,num2[i]=0;
			else{
				if(str1[i-1]=='1'){
					num2[i]+=num1[i-1]+num2[i-1]-i;
				}
				else{
					num1[i]+=num1[i-1]+num2[i-1]-i;
				}
				num1[i]+=len-i;
			}
		}
		// for(int i=0;i<len;i++) cout<<num1[i]<<' '; cout<<endl;
		// for(int i=0;i<len;i++) cout<<num2[i]<<' '; cout<<endl;

		
		ll ans=0;
		for(int i=0;i<len;i++){
			ans+=num1[i]*dp1[i]+num2[i]*dp2[i];
		}
		cout<< ans <<endl;
	}
	return 0;
}
