// #include<cstdio>
// #include<cmath>
// #include<cstring>
// #include<string>
// #include<stack>
// #include<map>
// #include<set>
// #include<queue>
// #include<vector>
// #include<iostream>
// #include<algorithm>        		//    ____   _   _  __   __
// using namespace std;            //   / ___| | | | | \ \ / /
// #define ll long long            //  | |     | |_| |  \ V /
// const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |
// const ll N   = 1e5+5;           //   \____| |_| |_|   |_|
// const ll MOD = 1e9+7;
// ll read(){
//     ll x=0,f=1;char ch=getchar();
//     while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
//     while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
//     return x*f;
// }
//
// string s;
// map<string, int> mp;
//
// void f(int x) {
// 	if(x == s.size()) {
// 		s = s + "a";
// 	}
// 	else{
// 		s[x]++;
// 		if(s[x] == 'z' && x != 0) {
// 			f(x + 1);
// 			for(int i = s.size() - 2; i >= 0; i--)
// 				s[i] = s[i + 1] + 1;
// 		}
// 		if(s[x] > 'z') {
// 			f(x + 1);
// 			s[x] = s[x + 1] + 1;
// 		}
// 	}
// }
//
// void init() {
// 	s = "a";
// 	int idx = 1;
// 	while(s.size() < 4) {
// 		//cout << s << endl;
// 		mp[s] = idx++;
// 		f(0);
// 	}
// 	cout << s << endl;
// 	cout << idx << endl;
// }
//
// int main(){
// 	init();
// 	for(int _ = read(); _; _--) {
// 		cin >> s;
// 		reverse(s.begin(), s.end());
// 		cout << mp[s] << endl;
// 	}
// 	return 0;
// }
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

char str[11];
int c[30][30]={0};

void work(){
    c[0][0]=0;
    for(int i=0;i<=26;i++){
        for(int j=0;j<=i;j++){
            if(j==0||i==j) c[i][j]=1;
            else{
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
    }
}

int t;
int main(){
    work();
    cin>>t;
    getchar();
    for(int j=1;j<=t;j++){
        cin>>str;
        long long sum=0;
        int len=strlen(str);
        bool flag=true;
        for(int i=0;i<len-1;i++){
            if(str[i+1]<=str[i]){
                cout<<0<<endl;
                flag=false;
            }
        }
        if(!flag) continue;
        for(int i=1;i<len;i++){
            sum+=c[26][i];
        }
        int i;
        for(i=0;i<len;i++){
            char ch=(!i)?'a':str[i-1]+1;
            while(ch<=str[i]-1){
                sum+=c['z'-ch][len-i-1];
                ch++;
            }
        }
        cout<<sum+1<<endl;
    }
    return 0;
}
