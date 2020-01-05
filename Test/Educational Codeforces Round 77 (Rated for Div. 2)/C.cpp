#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
const ll  INF  = 0x3f3f3f3f3f3f3f3f;

int main() {
  ll n, r, b, k;
  scanf("%lld", &n);
  while (n--) {
    scanf("%lld%lld%lld", &r, &b, &k);
    if (r > b) {
      swap(r, b);
    }
    if (b % r == 0) {
      if ((b / r) - 1 < k) {
        printf("OBEY\n"); continue;
      }
      else {
        printf("REBEL\n"); continue;
      }
    }
    else {
      ll c = __gcd(b, r);
      if ((b - c) % r == 0) {
        if ((b - c) / r < k) {
          printf("OBEY\n"); continue;
        }
        else {
          printf("REBEL\n"); continue;
        }
      }
      else {
        if (1 + (b - c) / r < k) {
          printf("OBEY\n"); continue;
        }
        else {
          printf("REBEL\n"); continue;
        }
      }
    }
  }
  return 0;
}