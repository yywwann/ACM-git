#include<bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 1<<30
#define MAXN 0x7fffffff
#define eps 1e-8
#define MOD 1000000007
#define ll long long
typedef struct
{
    ll data[4][4];
} M;

M I={1,0,0,0,
     0,1,0,0,
     0,0,1,0,
     0,0,0,1};

M matrixmul(M a,M b)
{
    M res=I;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            ll temp=0;
            for(int k=0;k<4;k++)
                temp=(temp+(a.data[i][k]*b.data[k][j])%MOD)%MOD;
            res.data[i][j]=temp;
        }
    }
    return res;
}
ll f[4];
ll pow_mod(M a,ll n)
{
    M res=I;
    while(n>0)
    {
        if(n&1)
            res=matrixmul(res,a);
        a=matrixmul(a,a);
        n>>=1;
    }
    ll ans=0;
    for(int j=0;j<4;j++)
        ans+=(f[j]*res.data[0][j])%MOD;
    return ans;
}

int main()
{
        ll n,x,y,f1,f2;
        int t;
        cin>>t;
        while(t--)
        {
            scanf("%lld%lld%lld%lld%lld",&n,&x,&y,&f1,&f2);
            x=x%MOD;y=y%MOD;f1=f1%MOD;f2=f2%MOD;

            if(n==1)
            {
                printf("%lld\n",f1%MOD);continue;
            }
            else if(n==2)
            {
                printf("%lld\n",((f1*f2)%MOD+f1)%MOD);continue;
            }
            M a={1,x%MOD,0,y%MOD,
                 0,(x*x)%MOD,(y*y)%MOD,(2*x*y)%MOD,
                 0,1,0,0,
                 0,x,0,y};
            f[0]=((f1*f2)%MOD+f1)%MOD;
            f[1]=f2*f2%MOD;
            f[2]=f1*f1%MOD;
            f[3]=f1*f2%MOD;
            printf("%lld\n",(pow_mod(a,n-2))%MOD);
        }
    return 0;
}
