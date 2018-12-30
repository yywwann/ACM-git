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

ll n,k;
vector<int>v,ans;
int main(){
	n=read(),k=read();
	if(k==0){
		for(int i=1;i<=n;i++){
			ans.push_back(i);
		}
	}
	else{
		int a=1+k,b=1+2*k;
		if(n<=a){
			ans.push_back(1);
		}
		else{
			for(int i=a;i<=b-1;i++) v.push_back(i);
			int m=n%b;
			while(m!=0&&m<v[0]) m+=b;

			if(m==0){
				ans.push_back(k+1);
				for(int i=b;i+k<=n;i+=b){
					ans.push_back(i+k+1);
				}
			}
			else{
				int flg1=-1,flg2=-1,flg3=-1;
				for(int i=0;i<v.size();i++){
					if(v[i]==m){
						flg1=i;break;
					}
				}
				if(flg1==-1){
					for(int i=0;i<v.size();i++){
						for(int j=0;j<v.size();j++){
							if(v[i]+v[j]==m){
								flg2=i;flg3=j;break;
							}
						}
					}
				}
				if(flg1!=-1){
					ans.push_back(flg1+1);
					for(int i=flg1+1+k;i+k<=n;i+=b){
						ans.push_back(i+k+1);
					}
				}
				else{
					ans.push_back(flg2+1);
					for(int i=flg2+1+k;i+k<=n-flg3-k;i+=b){
						ans.push_back(i+k+1);
					}
					ans.push_back(n-flg3);
				}
			}
		}
		
	}
	
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
	
	return 0;
}
