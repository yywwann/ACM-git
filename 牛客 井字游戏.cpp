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

char mp[4][4];
int  ans1, ans2;
map<char, map<char, int> > mmp;
void check(char a, char b, char c) {
  int vis[26] = { 0 };
  int flg     = 0;
  vector<char> v;

  if (vis[a - 'A'] == 0) {
    vis[a - 'A']++;
    flg++;
    v.push_back(a);
  }

  if (vis[b - 'A'] == 0) {
    vis[b - 'A']++;
    flg++;
    v.push_back(b);
  }

  if (vis[c - 'A'] == 0) {
    vis[c - 'A']++;
    flg++;
    v.push_back(c);
  }

  if (flg == 1) {
    char A = v[0];

    if (mmp[A][A] == 0) {
      mmp[A][A]++;
      ans1++;
    }
  }

  if (flg == 2) {
    char A = v[0];
    char B = v[1];

    if (A > B) swap(A, B);

    if (mmp[A][B] == 0) {
      mmp[A][B]++;
      ans2++;
    }
  }
}

int main() {
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> mp[i][j];
    }
  }

  check(mp[1][1], mp[1][2], mp[1][3]);
  check(mp[2][1], mp[2][2], mp[2][3]);
  check(mp[3][1], mp[3][2], mp[3][3]);

  check(mp[1][1], mp[2][1], mp[3][1]);
  check(mp[1][2], mp[2][2], mp[3][2]);
  check(mp[1][3], mp[2][3], mp[3][3]);

  check(mp[1][1], mp[2][2], mp[3][3]);
  check(mp[1][3], mp[2][2], mp[3][1]);

  cout << ans1 << endl << ans2 << endl;
  return 0;
}

/**
 * 链接：https://ac.nowcoder.com/acm/contest/947/G
   来源：牛客网

   井字游戏
   时间限制：C/C++ 1秒，其他语言2秒
   空间限制：C/C++ 131072K，其他语言262144K
   64bit IO Format: %lld
   题目描述
   Farmer John有26头奶牛，恰好她们名字都以不同的字母开头，所以Farmer John用每头奶牛的名字的首字母来指代她——一个A…Z之间的字母。
   这些奶牛最近沉迷于井字游戏，但是由于她们并不满足只有两头奶牛可以一起玩，她们改编了这个游戏，可以让许多奶牛可以一块儿玩！就像常规的井字游戏一样，这个游戏是在一块3×3的棋盘上进行的，只是与仅用X和O不同，每个格子用一个A…Z之间的字母标记，表示占有这个格子的奶牛名字的首字母。

   以下是一个棋盘的例子：

   COW
   XXO
   ABC
   这些奶牛会在她们迷惑于如何判断胜负之前就占满这九个格子。显然，就像常规的井字游戏一样，如果任何一头奶牛占有了一整行、一整列，或是一整条对角线，那么这头奶牛就获胜了。然而，由于奶牛认为多牛游戏中这并不容易出现，所以她们决定允许奶牛组成两牛一队，如果某一行、一列，或是一条对角线仅包含一队的两头奶牛的字母，并且同时包含了这两头奶牛（不仅仅是一头）的字母，那么这一队就获胜。
   链接：https://ac.nowcoder.com/acm/contest/947/G
   来源：牛客网

   请帮助奶牛们判断有多少头奶牛或是两头奶牛组成的队伍可以获胜。注意棋盘上的同一个格子可能在不同奶牛或队伍的获胜中均被用到。

   输入描述:
   输入包含三行，每行三个A…Z之间的字符。
   输出描述:
   输出包含两行。第一行，输出能够获胜的单独的奶牛的数量。第二行，输出能够获胜的两头奶牛组成的队伍的数量。
   示例1
   输入
   复制
   COW
   XXO
   ABC
   输出
   复制
   0
   2
   说明
   在这个例子中，没有单独的奶牛可以获得胜利。但是，如果奶牛C和奶牛X组队，她们可以通过C-X-C对角线获胜。同样地，如果奶牛X和O组队，她们可以通过中间一行取胜。
 */
