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

int n, m;
ll  t[4][N];
ll  ans[4][N];

int main() {
  for (int _ = read(); _; _--) {
    n = read(), m = read();
    memset(ans, 0, sizeof(ans));
    memset(t,   0, sizeof(t));

    while (m--) {
      int ty = read(), p = read();
      t[ty][p] += 1;
    }
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
      cnt       += t[1][i];
      cnt       %= MOD;
      ans[1][i] += cnt;
      ans[1][i] %= MOD;
    }
    cnt = 0;

    for (int i = 1; i <= n; i++) {
      cnt       += t[2][i];
      cnt       %= MOD;
      ans[2][i] += ans[2][i - 1] + cnt;
      ans[2][i] %= MOD;
    }
    cnt = 0;

    for (int i = 1; i <= n; i++) {
      cnt       += t[3][i];
      cnt       %= MOD;
      ans[3][i] += cnt;
      ans[3][i] %= MOD;

      // cout << ans[3][i] << ' ';
    }

    for (int i = 1; i <= n; i++) {
      ans[3][i] += ans[3][i - 1];
      ans[3][i] %= MOD;

      // cout << ans[3][i] << ' ';
    }

    for (int i = 1; i <= n; i++) {
      ans[3][i] += ans[3][i - 1];
      ans[3][i] %= MOD;

      // cout << ans[3][i] << ' ';
    }

    for (int i = n; i >= 1; i--) {
      ans[3][i] += ans[3][i - 1];
      ans[3][i] %= MOD;

      // cout << ans[3][i] << ' ';
    }

    for (int i = 1; i <= n; i++) {
      if (i == 1) printf("%lld", (ans[1][i] + ans[2][i] + ans[3][i]) % MOD);
      else printf(" %lld", (ans[1][i] + ans[2][i] + ans[3][i]) % MOD);
    } cout << endl;
  }
  return 0;
}

/**
 * 链接：https://ac.nowcoder.com/acm/contest/923/C
   来源：牛客网

   小w的糖果
   时间限制：C/C++ 1秒，其他语言2秒
   空间限制：C/C++ 262144K，其他语言524288K
   64bit IO Format: %lld
   题目描述
   小w和他的两位队友teito、tokitsukaze准备为大家发点福利，到底发点什么呢？思考良久之后他们三个人准备了很多很多的糖果。他们让n个小朋友们排成一长排并且从左到右依次标号为1,2,3,4,5,6,7,8,9.....n。

   三人每次发糖果，都是从某一个位置开始，只把糖果发给这个人以及这个人右侧的所有人。但是他们发糖果的规则有所不同。

   1、如果某轮发糖果的是tokitsukaze，她将会从一个位置pos开始，依次向右给每个人1个糖果。

   2、如果某轮发糖果的是teito，他将会从一个位置pos开始，依次向右，他将会给他碰到的第一个人发1个糖果，给他碰到的第二个人发2个糖果，给他碰到的第三个人发3个糖果...碰到的第k个人发k个糖果，直到向右走到编号为n的人为止。

   3、如果某轮发糖果的是winterzz1，众所周知小w是个大方的人，所以他发的糖最多，他将会从一个位置pos开始，依次向右，它将会给他碰到的第一个人发1个糖果，给他碰到的第二个人发4个糖果，给他碰到的第三个人发9个糖果...碰到的第k个人发
   k
   2
   k2个糖果直到向右走到编号为n的人为止。

   发糖的福利一共进行了m轮，现在告诉你这m轮发糖的人和他们该轮发糖的起始位置pos，请你告诉我这m轮发糖结束后1到n每个人手中糖果的数量，为了避免这个数字过大，你只用输出每一个人手中糖的数量
   m
   o
   d
   10
   9
 +
   7
   mod109+7后的结果即可。



   输入描述:
   第一行是一个正整数T
   (
   1
   ⩽
   T
   ⩽
   10
   )
   (1⩽T⩽10)，表示有T组测试案例。对于每组案例：
   第一行是两个正整数n,m
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
   (1⩽n,m⩽105)表示现在有一排n个人并且进行了m轮发糖果。
   接下来m行，每行两个正整数type
   (
   1
   ⩽
   t
   y
   p
   e
   ⩽
   3
   )
   (1⩽type⩽3),pos
   (
   1
   ⩽
   p
   o
   s
   ⩽
   n
   )
   (1⩽pos⩽n)分别表示该轮发糖果的人，以及这个人开始发糖果的位置。
   type=1时发糖果的人为tokitsukaze，type=2时发糖果的人为teito，type=3时发糖果的人为winterzz1。pos表示位置，并且最左边的人pos为1，最右边的人pos为n。
   输出描述:
   对于每组测试案例，输出一行n个非负整数，表示每个人手中的糖果数量
   m
   o
   d
   10
   9
 +
   7
   mod109+7后的结果。数字与数字之间用空格隔开并且行末不允许有多余空格。
   示例1
   输入
   复制
   4
   10 1
   1 1
   10 1
   2 2
   10 1
   3 3
   10 3
   1 1
   2 2
   3 3
   输出
   复制
   1 1 1 1 1 1 1 1 1 1
   0 1 2 3 4 5 6 7 8 9
   0 0 1 4 9 16 25 36 49 64
   1 2 4 8 14 22 32 44 58 74
   备注:
   由于输入量和输出量比较大，请勿使用cin,cout进行输入输出。
   本题不会卡常数，不用特地使用输入输出挂。
 */
