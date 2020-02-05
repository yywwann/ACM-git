#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+7;
ll n, c = 1;
int main()
{
    ll n;
    int k;
    char ch[10];
    srand(time(0));
    scanf("%lld%d", &n, &k);
    ll l = 1, r = n, c = 1;
    while(l<r)
    {
        l = max(c, l-k);
        r = min(n, r+k);
        while(r-l+1<=5*k)
        {
            ll p = l+rand()%(r-l+1);
            printf("%lld %lld\n", p, p);
            fflush(stdout);
            scanf("%s", ch);
            if(ch[0]=='Y')
            {
                return 0;
            }
            l = max(c, l-k);
            r = min(n, r+k);
        }
        ll mid = (l+r)>>1;
        printf("%lld %lld\n", l, mid);
        fflush(stdout);
        scanf("%s", ch);
        if(ch[0]=='Y')
        {
            r = mid;
        }
        else
        {
            l = mid+1;
        }
    }
    if(l==r)
    {
        printf("%lld %lld\n", l, l);
        fflush(stdout);
    }
    return 0;
}