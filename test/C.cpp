#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int dp[10][10005];
int a[10005];
int main()
{
    freopen("/Users/cccccccccchy/Documents/GitHub/ACM-git/test/in.txt", "r", stdin);
    freopen("/Users/cccccccccchy/Documents/GitHub/ACM-git/test/out.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        if(n<=5)
        {
            int sum=0;
            for(int i=1;i<=n;i++)
                sum+=a[i];
            printf("%d\n",sum);
            continue;
        }
        dp[4][1]=a[1];
        dp[4][2]=max(a[1],a[2]);
        dp[3][2]=a[1]+a[2];
        dp[4][3]=max(max(a[1],a[2]),a[3]);
        dp[3][3]=max(max(a[1]+a[2],a[2]+a[3]),a[1]+a[3]);
        dp[2][3]=a[1]+a[2]+a[3];
        for(int i=4;i<=n;i++)
        {
            for(int j=0;j<=5;j++)
            {
                if(j==0)
                {
                    dp[j][i]=max(dp[j][i],dp[j][i-1]);
                    dp[j][i]=max(dp[j][i],dp[j+1][i-1]+a[i]);
                    dp[j][i]=max(dp[j][i],dp[j][i-3]+a[i]);
                }
                else if(j==5)
                {
                    dp[j][i]=max(dp[j][i],dp[j-1][i-3]);
                    dp[j][i]=max(dp[j][i],dp[j][i-1]);
                }
                else
                {
                    dp[j][i]=max(dp[j][i],dp[j-1][i-3]);
                    dp[j][i]=max(dp[j][i],dp[j][i-1]);
                    dp[j][i]=max(dp[j][i],dp[j+1][i-1]+a[i]);
                    dp[j][i]=max(dp[j][i],dp[j][i-3]+a[i]);
                }
            }
        }
        int maxnum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=5;j++)
            {
                //cout<<dp[j][i]<<" ";
                if(dp[j][i]>maxnum)
                    maxnum=dp[j][i];
            }
            //cout<<endl;
        }
        printf("%d\n",maxnum);
    }
    return 0;
}
