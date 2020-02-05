#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 1e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;   
const ll prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};            
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

// ll daan,jichushuzi,LOOP;
// void ffggdd(ll ooffcc,ll num,ll k){
//     if(k==0){
//         ll temp=pow(jichushuzi,1.0/num);
//         if(pow(temp,0.0+num)>jichushuzi)  temp--;
//         temp--;
//         if(temp>0) daan+=temp*(LOOP&1?1:-1);
//         return ;
//     }
//     if(ooffcc>=17) return; if(num*prime[ooffcc]<60)  ffggdd(ooffcc+1,num*prime[ooffcc],k-1); ffggdd(ooffcc+1,num,k);
// }
// int main(){
//     for(int _=read();_;_--){
//         jichushuzi=read();
//         daan=0;
//         for(LOOP=1;LOOP<=3;LOOP++) ffggdd(0,1,LOOP);
//         cout<< jichushuzi-(daan+1) <<endl;
//     }
//     return 0;
// } 

//const ll prime[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
const int len = 17;
const double eps = 1e-8;

ll ans;
double n;

void dfs(int cur, int num, int total, ll k)
{
    if(k > 60) return; //素因子连乘最多不能超过60次幂，因为2 ^ 60 > 10 ^ 18
    if(num == total) {
        ll p = (ll)(pow(n, 1.0 / (0.0 + k)) + eps) - 1; //先把1去掉,eps精度误差
        ans += p;
        return ; 
    }
    if(cur == len) return ;
    dfs(cur + 1, num, total, k); //第i个素数不选
    dfs(cur + 1, num + 1, total, k * prime[cur]); //第i个素数选择
}

int main()
{
    for(int _=read();_;_--){
        n=read();
        ll t=n;
        ll res = 0;
        for(int i = 1; i <= 3; ++i) {
            ans = 0;
            dfs(0, 0, i, 1); 
            //从下标0开始，当前选择素数个数为0,需要选择素数个数i个,选择素数乘积为1
            if(i & 1) res += ans;
            else res -= ans;
        } 
        res += 1; //1在dfs时都没有统计
        cout<<t-res;
    

    }
    return 0;
}
