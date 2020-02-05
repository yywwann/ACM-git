#include <bits/stdc++.h>
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

int n;
struct node{
  int x, y;
}a[N];
int ans;

int cmp(node a, node b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i].x = read();
    a[i].y = read() + a[i].x;
  }
  sort(a+1, a+1+n, cmp);

  ans = 1;
  int end = a[1].y;
  for (int i = 2; i <= n; i++) {
    if (a[i].x >= end) {
      end = a[i].y;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}


/**
 * 链接：https://ac.nowcoder.com/acm/contest/924/G
来源：牛客网

County Fair Events
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述
Farmer John has returned to the County Fair so he can attend the special events (concerts, rodeos, cooking shows, etc.). He wants to attend as many of the N (1 <= N <= 10,000) special events as he possibly can.
He's rented a bicycle so he can speed from one event to the next in absolutely no time at all (0 time units to go from one event to the next!).
Given a list of the events that FJ might wish to attend, with their start times (1 <= T <= 100,000) and their durations (1 <= L <= 100,000), determine the maximum number of events that FJ can attend. FJ never leaves an event early.

输入描述:
Line 1: A single integer, N.
Lines 2..N+1: Each line contains two space-separated integers, T and L, that describe an event that FJ might attend.
输出描述:
Line 1: A single integer that is the maximum number of events FJ can attend.
示例1
输入
复制
7
1 6
8 6
14 5
19 2
1 8
18 3
10 6
输出
复制
4
说明
Graphic picture of the schedule:

FJ can do no better than to attend events 1, 2, 3, and 4.
 */
