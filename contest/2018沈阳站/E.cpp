#include <iostream>
#include <cmath>
#include <algorithm>
#define FAST_IO ios::sync_with_stdio(false)
using namespace std;
string sum;
int main(){
	FAST_IO;
	int t;
	cin>>t;
	string s;
	char c;
	int n;
	int ans=0;
	while(t--){
		//cin>>n;
		sum="";
		ans=0;
		int a;
		cin>>a>>c;
		cin>>s;
		int gg=0;
		for(int i=0;i<s.length();i++){
			gg=abs(c-s[i]);
			if(gg<10){
				sum+='0';
				sum+=(gg+'0');
			}
			else{
				while(gg){
					sum+=(gg%10+'0');
					gg=gg/10;
				}
			}
		}
		int k=1;
		for(int i=0;i<sum.length();i++){
			if(sum[i]=='0'&&k){
				continue;
			}
			else if(sum[i]!='0'){
				ans++;
				k=0;
			}
			else{
				ans++;
			}
		}
		if(ans==0) cout<<1<<endl;
		else
		cout<<ans<<endl;
	}
	return 0;
} 