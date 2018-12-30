//J
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define eps 1e-8
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define FAST_IO ios::sync_with_stdio(false)

typedef long long LL;
const LL N=2e7+5;
LL ans[N];
bool vis[N];
//vector<LL>v;
vector<LL>v;
int cnt=0;
int main(){
  
    LL sum=0;
    for(int i=2;i*i<=N;i++){
        int dij=i*i;
        if(vis[dij]) continue;
        for(int j=dij;j<=N;j+=dij) vis[j]=true;
    }

	for(int i=1;i<=N;i++) if(!vis[i]) v.push_back(i);

	// for(int i=0;i<v.size();i++){
	// 	for(int j=i;j<v.size();j++){
	// 		sum++;
	// 		LL t=v[i]*v[j];
	// 		if(t>N) break;
 //            ans[t]+=(j==i?1:2);
	// 	}
	// }
	// cout<<sum<<endl;
    
 //    ans[0]=0;ans[1]=1;
 //    for(int i=1;i<N;i++) ans[i]+=ans[i-1];

    int t;
    scanf("%d",&t);
    while(t--){
       	//for(int n=19999990;n<=20000000;n++){
    		int n;
    		cin>>n;
       		int p=lower_bound(v.begin(),v.end(),n)-v.begin();
	        while(v[p]>n){
	        	p--;
	        }
	        //cout<<p<<endl;
			LL tans=0;
			for(int i=0; v[i]*v[i]<=n && i<v.size(); i++){
				//cout<<"case: "<<i<<endl;
				int pos=lower_bound(v.begin()+i, v.end(), n/v[i])-v.begin();
				while(v[pos]> (n/v[i]) ){
		        	pos--;
		        }
				LL len=pos-(i-1)-1;
				tans+=1;
				tans+=len*2;
			}
	        printf("%lld\n",tans);
        
    }
    return 0;
}