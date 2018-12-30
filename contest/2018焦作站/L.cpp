#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 1e5+5;           //   \____| |_| |_|   |_|     
const ll mod = 1000000007; 
const ll maxn=12;              
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}
ll n;
struct Matrix{
    ll a[maxn][maxn];
    void init(){    //初始化为单位矩阵 
        memset(a, 0, sizeof(a));
        for(int i=0;i<maxn;++i){
            a[i][i] = 1;
        }
    }
};

//矩阵乘法 
Matrix mul(Matrix a, Matrix b){
    Matrix ans;
    for(int i=0;i<maxn;++i){
        for(int j=0;j<maxn;++j){
            ans.a[i][j] = 0;
            for(int k=0;k<maxn;++k){
                ans.a[i][j] = (ans.a[i][j]+(a.a[i][k]%mod * b.a[k][j]%mod)%mod)%mod;
                //ans.a[i][j] %= mod; 
            }
        }
    } 
    return ans;
}

//矩阵快速幂 
Matrix qpow(Matrix a, ll n){
    Matrix ans;
    ans.init();
    while(n){
        if(n&1) ans = mul(ans, a);
        a = mul(a, a);
        n /= 2;
    } 
    return ans;
}

void output(Matrix a){
    for(int i=0;i<maxn;++i){
        for(int j=0;j<maxn;++j){
            cout << a.a[i][j] << " ";
        }
        cout << endl;
    }
    cout<< "-----END-----"<<endl;
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        Matrix A,B;
        for(int i=0;i<9;i++) A.a[0][i]=1;
        B.a[0][0]=0;B.a[0][1]=1;B.a[0][2]=1;B.a[0][3]=0;B.a[0][4]=0;B.a[0][5]=0;B.a[0][6]=0;B.a[0][7]=0;B.a[0][8]=0;
        B.a[1][0]=0;B.a[1][1]=0;B.a[1][2]=0;B.a[1][3]=1;B.a[1][4]=1;B.a[1][5]=0;B.a[1][6]=0;B.a[1][7]=0;B.a[1][8]=0;
        B.a[2][0]=0;B.a[2][1]=0;B.a[2][2]=0;B.a[2][3]=0;B.a[2][4]=0;B.a[2][5]=0;B.a[2][6]=1;B.a[2][7]=1;B.a[2][8]=1;
        B.a[3][0]=1;B.a[3][1]=0;B.a[3][2]=1;B.a[3][3]=0;B.a[3][4]=0;B.a[3][5]=0;B.a[3][6]=0;B.a[3][7]=0;B.a[3][8]=0;
        B.a[4][0]=0;B.a[4][1]=0;B.a[4][2]=0;B.a[4][3]=1;B.a[4][4]=0;B.a[4][5]=1;B.a[4][6]=0;B.a[4][7]=0;B.a[4][8]=0;
        B.a[5][0]=0;B.a[5][1]=0;B.a[5][2]=0;B.a[5][3]=0;B.a[5][4]=0;B.a[5][5]=0;B.a[5][6]=1;B.a[5][7]=0;B.a[5][8]=1;
        B.a[6][0]=1;B.a[6][1]=1;B.a[6][2]=1;B.a[6][3]=0;B.a[6][4]=0;B.a[6][5]=0;B.a[6][6]=0;B.a[6][7]=0;B.a[6][8]=0;
        B.a[7][0]=0;B.a[7][1]=0;B.a[7][2]=0;B.a[7][3]=0;B.a[7][4]=1;B.a[7][5]=1;B.a[7][6]=0;B.a[7][7]=0;B.a[7][8]=0;
        B.a[8][0]=0;B.a[8][1]=0;B.a[8][2]=0;B.a[8][3]=0;B.a[8][4]=0;B.a[8][5]=0;B.a[8][6]=1;B.a[8][7]=1;B.a[8][8]=0;
        cin>>n;
        if(n==1) cout<<3<<endl;
        else{
            B=qpow(B,n-2);
            A=mul(A,B);
            ll ans=0;
            for(int i=0;i<9;i++) ans=(ans+A.a[0][i])%mod;
            cout<< ans%mod <<endl;
        }
        
    }
    
}
