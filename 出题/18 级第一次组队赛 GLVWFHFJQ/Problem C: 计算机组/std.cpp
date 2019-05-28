#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> e;
const int N(1e5+5);

int n, f;
long long ans;
vector<vector<int>>g(N);
int d[N];
vector<int>dis;

void init() {
    ans = 0;
    for (int i = 0; i < N; i++) g[i].clear();
}

void dfs(int u) {
    dis.push_back(d[u]);
    for (int v:g[u]) {
        d[v] += d[u];
        dfs(v);
    }
    int p = lower_bound(dis.begin(), dis.end(), d[u] - ((int)dis.size() - 1) * 200) - dis.begin();
    if (p > 0) p--;
    ans += (int)dis.size() - 1 - p;
    dis.pop_back();
}

void solve() {
    init();
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> f;
        g[f].push_back(i);
    }
    for (int i = 2; i <= n; i++) cin >> d[i];
    dfs(1);
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
