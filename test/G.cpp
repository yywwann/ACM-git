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
string str;
int l[5*N], r[5*N], _0;
int main(){
	cin >> n;
	while(n--){
		stack<char>st;
		while(!st.empty()) st.pop();
		cin >> str;
		for(int i = 0; i <str.size(); i++){
			if(st.empty()) st.push(str[i]);
			else{
				if(str[i] == ')' && st.top() == '(') st.pop();
				else st.push(str[i]);
			}
		}
		int len = 0;
		if(st.size() == 0) _0++;
		else{
			len = st.size();
			if(st.top() == '('){
				while(!st.empty() && st.top() == '(') st.pop();
				if(st.size() == 0) l[len]++;
			}
			else{
				while(!st.empty() && st.top() == ')') st.pop();
				if(st.size() == 0) r[len]++;
			}
		}
	}
	int res = _0 / 2;
	for(int i = 1; i <= 500000; i++) res += min(l[i], r[i]);
	cout << res << endl;
	return 0;
}
