#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
const ll MOD = 1e9+7;

int T;
int n;
int s, e;
int vis[1005];
int ans;

int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i <= 1000; i++) vis[i] = 0;
    while (n--) {
      cin >> s >> e;
      for (int i = s; i < e; i++) {
        vis[i] = 1;
      }
    }
    ans = 0;
    for (int i = 1; i <= 1000; i++) {
      if(vis[i] == 1) ans ++;
    }
    cout << ans << endl;
  }
}
