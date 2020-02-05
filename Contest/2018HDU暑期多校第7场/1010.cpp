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

//typedef struct node matrix;
ll a,b,c,d,p,n;
const int mod = 1e9+7;

struct matrix{
    ll mat[3][3];
    void init(){
    	memset(mat,0,sizeof(mat));
        //mes(mat, 0);
        for(int i = 0; i < 3; ++i){
            mat[i][i] = 1;
        }
    }
    void clear(){
        memset(mat,0,sizeof(mat));
    }
    void output(){
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                //  printf("%lld ", mat[i][j]);
                cout << mat[i][j] << " ";
            }
            printf("\n");
        }
    }
    matrix operator *(const matrix &base){
        matrix tmp;
        tmp.clear();
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 3; ++k){
                    tmp.mat[i][j] = (tmp.mat[i][j] + mat[i][k]*base.mat[k][j]);
                    if(tmp.mat[i][j] > mod){ //指数循环节运用
                        tmp.mat[i][j] %= mod;
                    }
                }
            }
        }
        return tmp;
    }
};

matrix matrix_fast_mod(ll m, matrix base) //矩阵快速幂
{
    matrix res;
    //  res.output();
    res.init();
    while(m){
        if(m&1){
            res = res*base;
        }
        base = base*base;
        m >>= 1;
    }
    return res;
}

// //系数矩阵的初始化
// void Init_orgin(matrix &temp){
//     temp._matrix[0][0] = 1;
//     temp._matrix[0][1] = 1;
//     temp._matrix[1][0] = 1;
//     temp._matrix[1][1] = (a+b) % mod;
// }
 
// //指数矩阵的初始化
// void Init(matrix &temp){
//     temp._matrix[0][0] = 0;
//     temp._matrix[0][1] = b;
//     temp._matrix[1][0] = 1;
//     temp._matrix[1][1] = a;
// }
 

 
void solve(){
    if(n - 2 <= 0){
        printf("%lld\n",n==1?a:b);
    }
    else{
    	ll ans=0;
    	for(int i=3;i<=n;i++){
    		//cout<<a<<' '<<b<<endl;
    		ll P=p/i;
    		ll j;
    		if(P==0) j=n;
    		else j=p/P;
    		int temp = min(j,n)-i+1;
    		if(temp<=2){
    			for(int k=1;k<=temp;k++){
    				ans=(c*a)%mod+(d*b)%mod+P;
    				ans%=mod;
    				a=b;
    				b=ans;
    			}
    		}
    		else{
    			for(int k=1;k<=2;k++){
    				ans=(c*a)%mod+(d*b)%mod+P;
    				ans%=mod;
    				a=b;
    				b=ans;
    			}
    			temp-=2;
    			matrix A,B,C;
    			A.clear(),B.clear();
    			A.mat[0][0]=b;
    			A.mat[0][1]=a;
    			A.mat[0][2]=P;

    			B.mat[0][0]=c;
    			B.mat[1][0]=d;
    			B.mat[2][0]=1;
    			B.mat[0][2]=1;
    			B.mat[2][2]=1;
    			B=matrix_fast_mod(temp,B);
    			C=A*B;
    			b=ans=C.mat[0][1];
    			a=C.mat[0][2];
    		}
    		i=j;

    	}
    	cout<<ans<<endl;
        //int temp = n - 3;   //利用一个初始的ans矩阵
        
        //printf("%I64d\n",ans._matrix[0][1]);
    }
}
int main(){
	map<int,int>mp;
	int N=1e8,P=1e8,cnt=0;
	for(int i=1;i<=N;i++){
		int t=P/i;
		if(mp[t]==0){
			cnt++;
			mp[t]=1;
			cout<<i<<" "<<t<<" "<<P/t<<endl;
		}
	}
	cout<<"sum= "<<cnt<<endl;
    for(int _=read(); _; _--){
    	a=read(), b=read(), c=read(), d=read(), p=read(), n=read();
    	solve();
    }
    return 0;
}
