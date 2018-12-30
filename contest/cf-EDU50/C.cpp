#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 1e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,_10=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')_10=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*_10; 
}

ll l,r;
ll _100[50],_10[50];
vector<ll>v;
void init(){
	_10[0]=1;
	for(ll _1=1;_1<20;_1++) _10[_1]=_10[_1-1]*10;
	for(ll _1=17;_1>=0;_1--){
		for(ll _2=1;_2<=9;_2++){
			v.push_back(_2*_10[_1]);
		}
	}
	for(ll _1=17;_1>=0;_1--){
		for(ll _2=_1-1;_2>=0;_2--){
			for(ll _3=1;_3<=9;_3++){
				for(ll _4=1;_4<=9;_4++){
					v.push_back(_3*_10[_1]+_4*_10[_2]);
				}
			}
		}
	}
	for(ll _1=17;_1>=0;_1--){
		for(ll _2=_1-1;_2>=0;_2--){
			for(ll _3=_2-1;_3>=0;_3--){
				for(ll _4=1;_4<=9;_4++){
					for(ll _6=1;_6<=9;_6++){
						for(ll _5=1;_5<=9;_5++){
							v.push_back(_4*_10[_1]+_6*_10[_2]+_5*_10[_3]);
						}
					}
				}
			}
		}
	}
	v.push_back(1e18);
	sort(v.begin(),v.end());
}

int main(){
	init();
	for(int _=read();_;_--){
		l=read(),r=read();
		ll posl=lower_bound(v.begin(),v.end(),l)-v.begin();
		ll posr=lower_bound(v.begin(),v.end(),r+1)-v.begin();
		cout<< posr-posl <<endl;
	}	
	return 0;
}
