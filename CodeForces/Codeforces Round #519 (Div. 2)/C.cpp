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

string str;
int a[N];
int main(){
	cin>>str;
	str+='b';
	int len=str.size();
	for(int i=1;i<len;i++){
		if(str[i]=='a'&&str[i-1]=='b'){
			string t1="",t2="";
			for(int j=i-1;j>=0;j--) t1+=str[j],t2+=str[i-j-1];
			//cout<<t1<<" "<<t2<<endl;
			if(t1>t2){
				a[i]=1;
				for(int k=0;k<=i-1;k++) str[k]=t1[k];
			}
			else a[i]=0;
		}
		if(str[i]=='b'&&str[i-1]=='a'){
			string t1="",t2="";
			for(int j=i-1;j>=0;j--) t1+=str[j],t2+=str[i-j-1];
				//cout<<t1<<" "<<t2<<endl;
			if(t1<t2){
				a[i]=1;
				for(int k=0;k<=i-1;k++) str[k]=t1[k];
			}
			else a[i]=0;
		}
		//cout<<str<<endl;
		// if(str[i]!=str[i-1]||str[i]=='#'){
		// 	string t1="",t2;
		// 	for(int j=i-1;j>=0;j--) t1+=str[j],t2+=str[i-j-1];
		// 	if(t1<t2){
		// 		a[i]=1;
		// 		for(int k=0;k<=i-1;k++) str[k]=t1[k];
		// 	}
		// 	else a[i]=0;
		// }
	}
	for(int i=1;i<len;i++) cout<<a[i]<<' ';
	return 0;
}
