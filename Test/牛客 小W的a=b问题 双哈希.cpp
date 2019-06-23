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

/**
 * 链接：https://ac.nowcoder.com/acm/contest/923/B
   来源：牛客网

   小w的a=b问题
   时间限制：C/C++ 1秒，其他语言2秒
   空间限制：C/C++ 262144K，其他语言524288K
   64bit IO Format: %lld
   题目描述
   给你两个数组，一个
   a
   [
   ]
   a[]数组，长度为n，另一个是
   b
   [
   ]
   b[]数组，长度为m。
   现在问你
   ∏
   n
   i
   =
   1
   a
   [
   i
   ]
   !
   ∏i=1na[i]!是否等于
   ∏
   m
   i
   =
   1
   b
   [
   i
   ]
   !
   ∏i=1mb[i]!
   其中
   ∏
   ∏是连乘符，它表示n个元素的乘积。"!"为阶乘运算，表示小于等于该数所有正整数的积，并且规定0!=1。
   我们认为阶乘运算"!"的优先级大于连乘运算"
   ∏
   ∏"。
   输入描述:
   第一行是一个正整数T，
   (
   1
   ⩽
   T
   ⩽
   2
   ∗
   10
   2
   )
   (1⩽T⩽2∗102)表示案例的数目
   对于每组案例，第一行是两个正整数n,m，
   (
   1
   ⩽
   n
   ,
   m
   ⩽
   10
   5
   )
   (1⩽n,m⩽105)。
   接下来一行输入n个整数a[i]，
   (
   0
   ⩽
   a
   [
   i
   ]
   ⩽
   10
   5
   )
   (0⩽a[i]⩽105)。
   接下来一行输入m个整数b[i]，
   (
   0
   ⩽
   b
   [
   i
   ]
   ⩽
   10
   5
   )
   (0⩽b[i]⩽105)。
   保证n,m的总和不多于
   2
   ∗
   10
   6
   2∗106
   输出描述:
   对于每组案例，输出一行一个字符串，如果
   ∏
   n
   i
   =
   1
   a
   [
   i
   ]
   !
   ∏i=1na[i]!等于
   ∏
   m
   i
   =
   1
   b
   [
   i
   ]
   !
   ∏i=1mb[i]!，请输出"equal"。
   反之请输出"unequal"。
   示例1
   输入
   复制
   3
   2 1
   5 3
   6
   4 6
   4 2 3 0
   2 3 2 2 1 3
   3 4
   5 6 7
   3 4 5 6
   输出
   复制
   equal
   equal
   unequal
   说明
   对于第一组案例：
   5!*3!=1*2*3*4*5*1*2*3=720
   6!=1*2*3*4*5*6=720
   完全相等。
   对于第二组案例：
   4!*2!*3!*0!=1*2*3*4*1*2*1*2*3*1=288
   2!*3!*2!*2!*1!*3!=1*2*1*2*3*1*2*1*2*1*1*2*3=288
   完全相等。
   对于第三组案例：
   5!*6!*7!=435456000
   3!*4!*5!*6!=12441600
   两者不等。
 */
