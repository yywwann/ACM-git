#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> perm[10][10];
int a[10];
int vis[10];
void init()
{
    for(int t = 1; t <= 9; t++)
    {
        for(int i = 1; i <= t; i++)
            a[i] = i;
        memset(vis, 0, sizeof(vis));
        do
        {
            int now = 0;
            for(int i = 1; i <= t; i++)
                now = now * 10 + a[i];
            int tmp = 0;
            for(int i = 1; i <= t; i++)
                if(vis[i] != now)
                {
                    vis[i] = now;
                    for(int j = a[i]; j != i; j = a[j])
                    {
                        vis[j] = now;
                        tmp++;
                    }
                }
            perm[t][tmp].push_back(now);
        }
        while(next_permutation(a + 1, a + t + 1));
    }
}
inline int apply(int mask)
{
    int ret = 0;
    int tmp = 1;
    while(mask)
    {
        ret += a[mask % 10] * tmp;
        mask /= 10;
        tmp *= 10;
    }
    return ret;
}
char n[12];
int t, k, mn, mx;
void solve()
{
    scanf("%s%d", n, &k);
    t = strlen(n);
    if(t == 10)
    {
        printf("1000000000 1000000000\n");
        return;
    }
    if(k >= t)
        k = t - 1;
    for(int i = 1; i <= t; i++)
        a[i] = n[i - 1] - '0';
    mn = 1000000000;
    mx = 0;
    int lj = 1;
    for(int i = 1; i < t; i++)
        lj *= 10;
    for(int i = 0; i <= k; i++)
        for(vector<int>::iterator it = perm[t][i].begin(); it != perm[t][i].end(); it++)
        {
            int now = apply(*it);
            if(now < lj)
                continue;
            now < mn ? mn = now : 0;
            now > mx ? mx = now : 0;
        }
    printf("%d %d\n", mn, mx);
}
int main()
{
    init();
    int T;
    scanf("%d", &T);
    for(int t1 = 1; t1 <= T; t1++)
        solve();
    return 0;
}
