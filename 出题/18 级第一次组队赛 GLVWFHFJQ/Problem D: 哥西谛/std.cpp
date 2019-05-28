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
#include<algorithm>               //    ____   _   _  __   __
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

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

ll PowerMod(ll a,ll b,ll c){
    ll ans = 1;
    a = a % c;
    while(b > 0){
        if(b % 2 == 1) ans = (ans * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return ans;
}

//欧拉函数
ll phi(ll x){
    ll ans = x;
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0){
            ans = ans / i * (i-1);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) ans = ans / x * (x-1);
    return ans;
}

ll n, k;

int main(){
    for(int _ = read(); _; _--) {
        n = read(), k = read();
        if(k > 2) {
            cout << 0 << endl;
            continue;
        }
        if(k == 2) {
            cout << 1 << endl;
            continue;
        }
        ll sum = 0;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                ll t = phi(i) * phi(n / i) % MOD;
                if(i != n / i){
                    t = t * 2 % MOD;
                }
                sum = (sum + t) % MOD;


            }
        }
        cout << sum << endl;
    }
    return 0;
}
