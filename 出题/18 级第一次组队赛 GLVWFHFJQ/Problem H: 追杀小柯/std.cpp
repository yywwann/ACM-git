#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;
ll a[N][5];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        a[1][0] = a[1][1] = a[1][2] = 1;
        for(int i=2;i<=n;i++){
            a[i][0] = (a[i-1][1] + a[i-1][0])%MOD;
            a[i][1] = (a[i-1][0] + a[i-1][2])%MOD;
            a[i][2] = (a[i-1][1] + a[i-1][2])%MOD;
        }
        cout << (a[n][0] + a[n][1] + a[n][2])%MOD << endl;
    }
    return 0;
}
