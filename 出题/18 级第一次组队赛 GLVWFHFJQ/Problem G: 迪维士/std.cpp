#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    int n;
    while(t--){
        cin >> n;
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ans += n/i;
        }
        cout << ans << endl;
    }
    return 0;
}
