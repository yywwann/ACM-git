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

ll n;
struct node{
	ll c;
	string v;
}a[1005];

map<string,ll>mp;
ll num[10];

bool check(string s){
	num[0]=num[1]=num[2]=0;
	for(int i=0;i<s.size();i++){
		num[s[i]-'A']++;
	}
	if(num[0]==0||num[1]==0||num[2]==0) return false;
	return true;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].c=read();
		cin>>a[i].v;
		sort(a[i].v.begin(),a[i].v.end());
		if(mp[a[i].v]==0) mp[a[i].v]=a[i].c;
		else mp[a[i].v]=min(mp[a[i].v],a[i].c);
		//cout<<mp[a[i].v]<<endl;
	}
	// int cnt=1;
	// for(auto i:mp){
	// 	num[cnt++]=i;
	// }
	ll ans=INF;
	for(int _1=0;_1<=1;_1++)
		for(int _2=0;_2<=1;_2++)
			for(int _3=0;_3<=1;_3++)
				for(int _4=0;_4<=1;_4++)
					for(int _5=0;_5<=1;_5++)
						for(int _6=0;_6<=1;_6++)
							for(int _7=0;_7<=1;_7++){
								string t="";
								ll anst=0;
								if(_1&&mp["A"]>0) t+="A",anst+=mp["A"];
								if(_2&&mp["B"]>0) t+="B",anst+=mp["B"];
								if(_3&&mp["C"]>0) t+="C",anst+=mp["C"];
								if(_4&&mp["AB"]>0) t+="AB",anst+=mp["AB"];
								if(_5&&mp["AC"]>0) t+="AC",anst+=mp["AC"];
								if(_6&&mp["BC"]>0) t+="BC",anst+=mp["BC"];
								if(_7&&mp["ABC"]>0) t+="ABC",anst+=mp["ABC"];
								if(check(t)) ans=min(ans,anst);//,cout<<t<<' '<<anst<<endl;;

							}
	if(ans==INF) cout<<-1<<endl;
	else cout<<ans<<endl;
	// ll t1,t2,t4,t3,t5,t6,t7,t8;
	// if(mp["A"]==0||mp["B"]==0||mp["C"]==0) t1=INF;
	// else t1=mp["A"]+mp["B"]+mp["C"];
	// if(mp["AB"]==0||mp["BC"]==0) t2=INF;
	// else t2=mp["AB"]+mp["BC"];
	// if(mp["AC"]==0||mp["BC"]==0) t3=INF;
	// else t3=mp["AC"]+mp["BC"];
	// if(mp["AC"]==0||mp["AB"]==0) t4=INF;
	// else t4=mp["AC"]+mp["AB"];
	// if(mp["ABC"]==0) t5=INF;
	// else t5=mp["ABC"];
	// if(mp["A"]==0||mp["BC"]==0) t6=INF;
	// else t6=mp["A"]+mp["BC"];
	// if(mp["AC"]==0||mp["AB"]==0) t7=INF;
	// else t7=mp["AC"]+mp["AB"];
	// if(mp["AC"]==0||mp["AB"]==0) t8=INF;
	// else t8=mp["AC"]+mp["AB"];
	// //cout<<t1<<' '<<t2<<" "<<t3<<' '<<t4<<' '<<t5<<endl;
	// if(t1==INF&&t2==INF&&t3==INF&&t4==INF&&t5==INF) cout<<-1<<endl;
	// else cout<<min({t1,t2,t3,t4,t5})<<endl;
	return 0;
}
