#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
const ll N=500010;
ll n,p;
ll high[N],sum[N];
int main() {
    cin >> n >> p;
    for(int i = 1; i <= n; i++) cin >> high[i];
    sort(high + 1, high + 1 + n);
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + high[i];
    ll res = INF;
    for(int i = p; i <= n; i++) res = min(res, p * high[i] - (sum[i] - sum[i-p]));
    cout << res << endl;
    return 0;
}
