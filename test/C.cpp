#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>        		//    ____   _   _  __   __
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

int n;
string s[N];
int l[10*N], r[10*N], _0;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		stack<char>st;
		for(int j = 0; j <s[i].size(); j++){
			if(st.empty()){
				st.push(s[i][j]);
			}
			else{
				if(s[i][j] == ')' && st.top() == '(') st.pop();
				else st.push(s[i][j]);
			}
		}
		int len = 0;
		if(st.empty()){
			_0++;
		}
		else{
			if(st.top() == '('){
				len = st.size();
				while(!st.empty() && st.top() == '(') st.pop();
				if(st.empty()) l[len]++;
			}
			else{
				len = st.size();
				while(!st.empty() && st.top() == ')') st.pop();
				if(st.empty()) r[len]++;
			}
		}
	}
	int ans = _0 / 2;
	for(int i = 1; i <= 500000; i++){
		ans += min(l[i], r[i]);
	}
	cout << ans << endl;
	return 0;
}
