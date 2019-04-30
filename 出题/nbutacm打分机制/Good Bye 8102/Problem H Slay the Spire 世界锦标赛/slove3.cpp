#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
const int MAXN = 1E5L+3;
int a[MAXN], b[MAXN];
using namespace std;
//找到大于key的个数 
int fun(int n, int key)
{
    int low = 0, high = n - 1;
    int ret = n;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (b[mid] > key)
        {
            ret = mid;
            high = mid - 1; 
        }
        else
            low = mid + 1;
    }
     
    return n - ret;
}
 
int main(void)
{
    int T, n, i;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b+n);
        for (i = 0; i < n; i++)
        {
            printf(i == 0 ? "%d" : " %d", fun(n, a[i] - 1) - fun(n, 2 * a[i]) - 1);
        }
        printf("\n"); 
    }
     
    return 0;   
}