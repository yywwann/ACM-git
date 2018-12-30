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

int n,x;
int a[maxn];
int num[maxn];
int cnt[maxn];
int cnt1[maxn];
int MAX;
int MIN[maxn];
int main(){
	n=read();x=read();
	for(int i=1;i<=100;i++){
		//MIN[i]=inf;
		num[i]=i&x;
		cout<<i<<' '<<num[i]<<endl;
	}
	for(int i=1;i<=n;i++){
		a[i]=read();
		cnt[a[i]]++;
		if(cnt[a[i]]==2){
			cout<<0<<endl;
			return 0;
		}
	} 
	for(int i=1;i<=n;i++){
		if(a[i]!=num[a[i]]&&cnt[num[a[i]]]==1){
			cout<<1<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=num[a[i]]){
			cnt1[num[a[i]]]++;
			if(cnt1[num[a[i]]]==2){
				cout<<2<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;

	return 0;
}
