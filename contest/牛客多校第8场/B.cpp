// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const ll inf  = 0x3f3f3f3f;
// const ll maxn = 1e5+5;
// ll read(){
//     ll x=0,f=1;char ch=getchar();
//     while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
//     while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
//     return x*f; 
// }

// int g[100][100];
// int n;
// int a[100];

// bool isok(int x,int y){
// 	if(g[x+1][y]==1&&g[x][y-1]==1) return 1;
// 	if(g[x+1][y]==1&&g[x][y+1]==1) return 1;
// 	if(g[x-1][y]==1&&g[x][y-1]==1) return 1;
// 	if(g[x-1][y]==1&&g[x][y+1]==1) return 1;
// 	return 0;
// }

// int check(){
// 	int sum=n;
// 	int t=1;
// 	while(t==1){
// 		t=0;
// 		for(int i=1; i<=n; i++){
// 			for(int j=1; j<=n; j++){
// 				if(g[i][j]==0&&isok(i,j)){
// 					t=1;
// 					g[i][j]=1;
// 					sum++;
// 				}
// 			}
// 		}
// 	}
// 	//cout<<sum<<endl;
// 	return sum==n*n;
// }

// int main(){
// 	for(int _=1; _<=9; _++){
// 		n=_; 
// 		ll ans=0;
// 		for(int i=1; i<=n; i++) { a[i]=i; }
// 		do{
// 			//ans=0;
// 			memset(g,0,sizeof(g));
// 			for(int i=1; i<=n; i++){
// 				g[i][a[i]]=1;
// 				//cout<<a[i]<<' ';
// 			}//cout<<endl;
// 			// for(int i=1;i<=n;i++){
// 			// 	for(int j=1;j<=n;j++){
// 			// 		cout<<g[i][j];
// 			// 	}cout<<endl;
// 			// }
// 			ans+=check();
// 		}while(next_permutation(a + 1, a + n + 1));
// 		cout<<n<<' '<<ans<<endl;
// 	}	
// 	return 0;
// }
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

ll n,ans;
const ll mod = 998244353;

void Euild(ll a, ll b, ll &x, ll &y)  // x 是 a 关于 b 的乘法逆元
{
    if(0 == b){
        x = 1, y = 0;
        return ;
    }
    Euild(b, a%b, x, y);
    ll flag = x;
    x = y;
    y = flag - a/b * y;
}

int main(){
	n=read();
	ll x,y;
	Euild(2*n , mod, x, y);
	ans = 1;
	ans = ans - n + mod; ans %= mod;
	ans = ans - sqrt(1-6*n+n*n) + mod; ans %= mod;
	ans *= x; ans %= mod;
	cout<<ans<<endl;
	return 0;
}
