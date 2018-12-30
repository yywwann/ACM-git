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

string s;

int main(){
	ll _=read();
	while(_--){
		cin>>s;
		stack<int>st;
		while(!st.empty()) st.pop();
		bool flg=true;
		for(int i=0;i<s.size();i++){
			if(s[i]=='?'){
				if(st.empty()){
					s[i]='1';
					st.push(1);
				}
				else{
					if(st.top()==1){
						s[i]='1';
					}
					else if(st.top()==0){
						s[i]='+';
						st.push(2);
					}
					else{
						s[i]='1';
						st.push(1);
					}
				}
			}
			else if(s[i]=='+'||s[i]=='*'){
				if(st.empty()){
					flg=false;
				}
				else{
					if(st.top()==2){
						flg=false;
					}
					else{
						st.push(2);
					}
				}
			}
			else if(s[i]=='0'){
				if(st.empty()){
					st.push(0);
				}
				else{
					if(st.top()==0){
						flg=false;
					}
					if(st.top()==2){
						st.push(0);
					}
				}
			}
			else{
				if(st.empty()){
					st.push(1);
				}
				else{
					if(st.top()==0){
						flg=false;
					}
					if(st.top()==2){
						st.push(1);
					}
				}
			}
			if(!flg) break;
		}
		if(!st.empty()&&st.top()==2) flg=false;
		if(flg) cout<<s<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
		
	}
	return 0;
}
