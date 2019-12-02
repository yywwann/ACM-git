#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 2e18;    //   | |     |  _  |   V /
const ll N   = 1e5 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

struct point {
  ll x, y;
} a[4];

double dis(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
  for (int _ = read(); _; _--) {
    for (int i = 1; i <= 3; i++) a[i].x = read(), a[i].y = read();
    double A, B, C;
    A = dis(a[1], a[2]);
    B = dis(a[1], a[3]);
    C = dis(a[2], a[3]);
    double COS, SIN;
    COS = (A * A + B * B - C * C) / (2 * A * B);
    if (COS == 1) cout << 0 << endl;
    else {
      SIN = sqrt(1 - COS * COS);
      printf("%.1f\n", A * B * SIN / 2);
    }
  }
  return 0;
}