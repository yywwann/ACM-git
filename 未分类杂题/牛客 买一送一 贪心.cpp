#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |  \ V /
const ll N = 1e5 + 5;      //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    \____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

int n, m;
int a[N], b[N];

int main() {
  n = read(); m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int j = 1; j <= m; j++) b[j] = read();

  sort(a+1, a+1+n);
  sort(b+1, b+1+m);
  int ans = 0;
  for (int i = n, j = m; i >= 1; i--) {
    ans += 1;
    for (j; j >= 1; j--) {
      if (a[i] > b[j]) {
        ans += 1;
        j--;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}

/**
 * 链接：https://ac.nowcoder.com/acm/contest/924/A
来源：牛客网

买一送一
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述
Farmer John在网上买干草。他发现了一笔特殊的买卖。他每买一捆大小为A(1 <= A <= 1,000,000)的干草，他就能免费获得一捆大小为B(1 <= B < A)的干草！
然而，这笔交易是有规定的：大的一捆干草必须是高质量的，小的一捆是低质量的。FJ是个吝啬鬼，他并不在意：随便什么质量，只要能省钱就好。
给出一组N(1 <= N <= 10,000)捆高质量干草的大小，M(1 <= M <= 10,000)捆低质量的干草的大小，找出Farmer John最多能买多少捆干草。他能买高质量的干草而不拿免费的低质量干草，但他不能买低质量的干草（就是说，他只能通过增送来获得）。
输入描述:
第 1 行: 两个用空格分开的整数，N和M
第 2 至 N+1 行: 第i+1行包含一个整数，是第i捆高质量干草的大小。
第 N+2 至 N+M+1 行: 第i+N+1行包含一个整数，是第i捆低质量干草的大小。
输出描述:
第 1 行: Farmer John能买的最大的干草的捆数。
示例1
输入
复制
3 4
6
1
3
1
5
3
4
输出
复制
5
说明
有3捆高质量干草，大小是6，1，3，4捆低质量的干草，大小是1，5，3，4
显然，Farmer John能买所有的高质量的干草。当他买了大小为6的高质量干草，他可以免费拿任何一捆低质量干草（例如大小为3的）。当他买了大小为3的高质量干草，他可以拿大小为1的免费低质量干草。然而当他买了大小为1的高质量干草，就不能拿不了免费干草了（因为大小必须严格小于）。这样，无论FJ有多聪明，最多也只能拿5捆干草了。
 * */
