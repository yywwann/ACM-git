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

ll n, a[N];
priority_queue<ll, vector<ll>, greater<ll> >q;

int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), q.push(a[i]);

  ll ans = 0;
  while (q.size() > 1) {
    ll t1 = q.top(); q.pop();
    ll t2 = q.top(); q.pop();
    ans += t1 + t2;
    q.push(t1 + t2);
  }

  cout << ans << endl;
  return 0;
}

/**
 * 链接：https://ac.nowcoder.com/acm/contest/924/C
来源：牛客网

修围栏
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述
农民 John 希望修复围绕农场的一小段围栏。他测量了一下，发现需要N (1 <= N <= 20,000) 根木头，每根都有某一个整数长度 Li (1 <= Li <= 50,000) 单位长度。他买了一根很长的很长的木头，正好能够锯出他所需要的N根木头。(即它的长度正好等于Li的总和) FJ 忽略锯口，锯掉的木屑产生的长度损失忽略不计，你也可以忽略它。
FJ 遗憾的发现他自己没有用于切木头的锯子，所以他就带着那根很长的木头来到了农民 Don的农场，想问他借一个锯子。
农民 Don是一个保守的资本家，他不愿意借锯子给 FJ ，但愿意自己来切这N-1刀，每一次都向FJ收取费用。每次的收费正好等于你要锯的那根木头的总长度。例如，你要锯一根长度为21的木头，就花费21分钱。
农民 Don 然后让农民 John 自己决定每次锯木头的顺序和位置。帮助农民 John 确定锯出这N根木头的最小总花费。 FJ 知道可以有很多种不同的切割方式，不同的方式可能得到不同的总花费，这是因为木头在锯的过程中的长度不一。
输入描述:
Line 1: 一个整数 N，表示要锯出的木头数
Lines 2..N+1: 每行一个整数，表示每根木头的长度。
输出描述:
Line 1: 一个整数，表示他最少需要多少分钱，锯N-1下，锯出所有需要的木头。
示例1
输入
复制
3
8
5
8
输出
复制
34
说明
他需要从总长度为 21 的木头中锯出三根长度分别是 8, 5和8的木头。
原本的木头长度为 8+5+8=21。第一次锯的花费是 21，应该切成两段长度分别是13和8。第二次花费是13，把长度是13的木头锯成8和5。总花费是21+13=34。但如果先将21锯成16和5，第二次将花费16，导致总花费达到37 (大于34)。
 */
