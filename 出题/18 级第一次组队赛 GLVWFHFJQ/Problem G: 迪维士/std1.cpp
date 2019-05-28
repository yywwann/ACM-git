#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<cstring>
#include<vector>
#define M 1000000007
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        long long i=3;
        scanf("%d",&n);
        if(n==1) printf("3\n");
        else
        {
            for(int j=0;j<n-1;j++)
            {
                i=i*2%M;
            }
            printf("%lld\n",i);
        }
    }
}
