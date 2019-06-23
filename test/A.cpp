// #include <bits/stdc++.h>

// using namespace std;       //     ____   _   _  __   __
// #define ll long long       //    / ___| | |_| |   / /
// const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
// const ll N   = 1e5 + 5;    //   | |___  | | | |   | |
// const ll MOD = 1e9 + 7;    //    ____| |_| |_|   |_|
// ll read() {
//   ll   x = 0, f = 1;
//   char ch = getchar();
//
//   while (ch < '0' || ch > '9') {
//     if (ch == '-') f = -1; ch = getchar();
//   }
//
//   while (ch >= '0' && ch <= '9') {
//     x = x * 10 + ch - '0'; ch = getchar();
//   }
//   return x * f;
// }
//
// int a[N], b[N];
// int n, m;
// int numa[N], numb[N];
//
// void fun(int cnt[], int x) {
//   int cn = cnt[x];
//
//   cnt[x] = 0;
//
//   for (int i = 2; i * i <= x; i++) {
//     while (x % i == 0) {
//       x      /= i;
//       cnt[i] += cn;
//     }
//   }
//   cnt[x] += cn;
// }
//
// int main() {
//   for (int _ = read(); _; _--) {
//     n = read(), m = read();
//
//     for (int i = 0; i < N; i++) numa[i] = numb[i] = 0;
//
//     for (int i = 1; i <= n; i++) {
//       a[i]            = read();
//       numa[0]        += 1;
//       numa[a[i] + 1] -= 1;
//     }
//
//     for (int i = 1; i <= m; i++) {
//       b[i]            = read();
//       numb[0]        += 1;
//       numb[b[i] + 1] -= 1;
//     }
//
//     for (int i = 1; i <= 100000; i++) {
//       numa[i] += numa[i - 1];
//       numb[i] += numb[i - 1];
//     }
//     int f = 1;
//
//     for (int i = 100000; i >= 2; i--) {
//       fun(numa, i);
//       fun(numb, i);
//
//       if (numa[i] != numb[i]) {
//         f = 0;
//         break;
//       }
//     }
//
//     if (f) printf("equal\n");
//     else printf("unequal\n");
//   }
//   return 0;
// }
#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 1e5 + 5;    //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    ____| |_| |_|   |_|
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1; ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0'; ch = getchar();
  }
  return x * f;
}

const ll mod = 998244353;
pair<ll, ll> Hash[N];
int n, m, a[N], b[N];

int main() {
  Hash[0] = make_pair(1, 1);

  for (int i = 1; i <= 100000; i++) {
    Hash[i] =
      make_pair(Hash[i - 1].first * i % MOD, Hash[i - 1].second * i % mod);
  }

  for (int _ = read(); _; _--) {
    n = read(), m = read();
    pair<ll, ll> A(1, 1), B(1, 1);

    for (int i = 1; i <= n; i++) {
      a[i] = read();
      A    = make_pair(A.first * Hash[a[i]].first % MOD,
                       A.second * Hash[a[i]].second % mod);
    }

    for (int i = 1; i <= m; i++) {
      b[i] = read();
      B    = make_pair(B.first * Hash[b[i]].first % MOD,
                       B.second * Hash[b[i]].second % mod);
    }

    if (A == B) printf("equal\n");
    else printf("unequal\n");
  }
  return 0;
}
