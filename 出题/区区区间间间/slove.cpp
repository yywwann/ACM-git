#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define x first
#define y second
#define umap unordered_map
#define FIN freopen("in.txt","r",stdin);
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<int, LL>PIL;
typedef pair<LL, int> PLI;
typedef pair<LL, LL> PLL;
typedef pair<int, string>PIS;

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}


const int MX = 1e6 + 5;
int a[MX], l[MX], r[MX];
int main() {
    //FIN;
    int n;
    int t;
    scanf("%d\n", &t);
    while (t-- ) {
        scanf ("%d", &n);
        LL ans = 0;
        stack<int>s;
        for (int i = 1; i <= n; i++) scan_d(a[i]), r[i] = n + 1;
        for (int i = 1; i <= n; i++) {
            while (!s.empty() && a[s.top()] < a[i]) {
                r[s.top()] = i;
                s.pop();
            }
            l[i] = s.empty() ? 0 : s.top();
            s.push (i);
        }
        for (int i = 1; i <= n; i++) {
            ans += (LL) (i - l[i]) * (r[i] - i) * a[i];
            //printf ("[%d %d %d]\n", (i - l[i]) , (r[i] - i) , a[i]);
        }
        while (!s.empty() ) s.pop();
        for (int i = 1; i <= n; i++) r[i] = n + 1;
        for (int i = 1; i <= n; i++) {
            while (!s.empty() && a[s.top()] > a[i]) {
                r[s.top()] = i;
                s.pop();
            }
            l[i] = s.empty() ? 0 : s.top();
            s.push (i);
        }
        for (int i = 1; i <= n; i++) {
            ans -= (LL) (i - l[i]) * (r[i] - i) * a[i];
            //printf ("[%d %d %d]\n", (i - l[i]) , (r[i] - i) , a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
