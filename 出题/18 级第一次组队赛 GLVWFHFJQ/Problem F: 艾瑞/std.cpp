#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INFL(0x3f3f3f3f3f3f3f3f);
const int N(1e5+5);

void tomax(ll& a, ll b) {a = max(a, b);}

struct segt {
    struct seg {
        int l, r;
        ll mx, lz;
        void update(ll v) {mx += v; lz += v;}
    };

    #define lc x<<1
    #define rc x<<1|1
    #define mid ((t[x].l+t[x].r)/2)

    ll * a;
    seg t[N<<2];

    void modify(ll * arr) {a = arr;}
    void push_up(int x) {t[x].mx = max(t[lc].mx, t[rc].mx);}
    void push_down(int x) {
        ll lz = t[x].lz;
        t[lc].update(lz); t[rc].update(lz);
        t[x].lz = 0;
    }
    void build(int x, int l, int r) {
        t[x] = seg({l, r, -INFL, 0ll});
        if(l == r) {
            t[x].mx = a[l];
            return;
        }
        build(lc, l, mid);
        build(rc, mid+1, r);
        push_up(x);
    }
    void update(int x, int l, int r, ll v) {
        if (l > r) return;
        int L(t[x].l), R(t[x].r);
        if(l <= L && R <= r) {
            t[x].update(v);
            return;
        }
        push_down(x);
        if(l <= mid) update(lc, l, r, v);
        if(r >  mid) update(rc, l, r, v);
        push_up(x);
    }
    ll query(int x, int l, int r) {
        int L(t[x].l), R(t[x].r);
        if(l <= L && R <= r) return t[x].mx;
        push_down(x);
        ll res(-INFL);
        if(l <= mid) tomax(res, query(lc, l, r));
        if(r >  mid) tomax(res, query(rc, l, r));
        return res;
    }
};

int n, m, op, l, r, val;
ll a[N], s[N];
segt tree;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) a[i] += a[i-1];
    for (int i = 1; i <= n - 2; ++i) s[i] = a[i + 2] - a[i - 1];
    tree.modify(s);
    tree.build(1,1,n-2);
    while (m--) {
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> val;
            tree.update(1, l, r - 2, val);
            tree.update(1, max(1, l - 1), min(n - 2, r - 1), val);
            tree.update(1, max(1, l - 2), min(n - 2, r), val);
        }
        else {
            cout << tree.query(1, l, r - 2) << endl;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
