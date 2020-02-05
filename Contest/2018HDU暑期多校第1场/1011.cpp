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

int t;
int h,m;
char s[100];
int main(){
	t=read();
	while(t--){
		h=read(),m=read();
		scanf("%s",s);
		
		char o=s[3];
		int th=0,tm=0;
		int pos=4;
		int len=strlen(s);
		while(pos<=len){
			if(pos<=5&&s[pos]>='0'&&s[pos]<='9'){
				th=th*10+(s[pos]-'0');
			}
			if(pos>5&&s[pos]>='0'&&s[pos]<='9'){
				tm=tm*10+(s[pos]-'0');
			}
			pos++; 
		}
		h-=8;
		if(o=='+'){
			h+=th;m+=tm*6;
			if(m>=60) m-=60,h+=1;
			if(h<0) h+=24;
			if(h>=24) h-=24;
			if(h<10) cout<<0;
			cout<<h<<":";
			if(m<10) cout<<0;
			cout<<m<<endl;
		}
		else{
			h-=th;m-=tm*6;
			if(m<0) m+=60,h-=1;
			if(h<0) h+=24;
			if(h>=24) h-=24;
			if(h<10) cout<<0;
			cout<<h<<":";
			if(m<10) cout<<0;
			cout<<m<<endl;
		}
	}
	return 0;
}
