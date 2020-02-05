#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define pi acos(-1)
#define eps 1e-10
#define mem(x) memset(x,0,sizeof(x))
#define si(n) scanf("%d",&n)
#define _for(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define __for(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD)
{ll ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
template< typename T > inline void read(T &x) {
    static bool fr_f; static char fr_ch;
   fr_f=0; x=0; fr_ch=getchar();
    while(fr_ch<'0' || '9'<fr_ch) {if(fr_ch=='-') fr_f=1; fr_ch=getchar();}
    while('0'<=fr_ch && fr_ch<='9') {x=(x<<1)+(x<<3)+fr_ch-'0'; fr_ch=getchar();}
    if(fr_f) x=-x;
}
const int inf=0x3f3f3f3f;
const int N=1000005;
const int MOD=1e9+7;

int a[1000][10];

int main ()
{
    for(int i=1;i<=9;i++)
    {
        a[2][i]=1;
    }
    for(int i=3;i<=1000;i++)
    {
        a[i][1]=a[i-1][4]+a[i-1][7];
        a[i][2]=a[i-1][1]+a[i-1][7];
        a[i][3]=a[i-1][1]+a[i-1][4]+a[i-1][7];
        a[i][4]=a[i-1][2]+a[i-1][5];
        a[i][5]=a[i-1][2]+a[i-1][8];
        a[i][6]=a[i-1][5]+a[i-1][8];
        a[i][7]=a[i-1][3]+a[i-1][6]+a[i-1][9];
        a[i][8]=a[i-1][3]+a[i-1][9];
        a[i][9]=a[i-1][3]+a[i-1][6];
        //for(int j=1;j<=9;j++) a[i][j]%=MOD;
    }
	Find[0]=3;
	len=100000;
    for(int i=2;i<len;i++)
    {
        ll num=0;
        for(int j=1;j<=9;j++)
        {
            num+=a[i][j];
            num%=MOD;
        }
        //Find[i-1]=num;
        cout<<num<<endl;
    }

    getNEXT();
    cout<< len%(len-NEXT[len])<<endl;

    return 0;
}