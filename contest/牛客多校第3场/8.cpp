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

//时间复杂度 O(NlogN)   
const int N = 10000000 + 5;
bool isprime[N];//isprime[i]表示i是不是质数 
int prime[N];//prime[N]用来存质数  从0开始
int tot;//tot表示[2，N]之间质数的数量 
void init(){
    for(int i = 2; i < N; i ++) isprime[i] = true;//初始化为质数 
    for(int i = 2; i < N; i++){
        if(isprime[i]) prime[tot ++] = i;//把质数存起来 
        for(int j = 0; j < tot && i * prime[j] < N; j++){
            isprime[i * prime[j]] = false;//质数的倍数一定不是质数
            if(i % prime[j] == 0) break;//保证每个合数被它最小的质因数筛去 
        }
    }    
}

int n,t;
ll ans;
int main(){
	init();
	n=read();

	for(int i=0;i<=tot;i++){
		if(prime[i]<=n){
			t++;
			ans+=2*(n/prime[i]-1)*i;
		} 
		else break;
	}
	ans+=1LL*(t-1+1)*(t-1);
	cout<<ans<<endl;
	return 0;
}


