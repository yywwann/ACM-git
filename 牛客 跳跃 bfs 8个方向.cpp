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

int n, m, m1, m2;
int g[50][50];
int vis[50][50];
vector<int> dx, dy;

struct node{
  int x, y, step;
  node(int x, int y, int step) {
    this->x = x;
    this->y = y;
    this->step = step;
  }
};

queue<node> q;
int bfs(int sx, int sy) {
  vis[sx][sy] = 1;
  q.push(node(sx, sy, 0));
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int x = u.x + dx[i];
      int y = u.y + dy[i];
      int step = u.step + 1;
      if (x < 1 || x > n || y < 1 || y > m) continue;
      if (vis[x][y] == 1 || g[x][y] == 0 || g[x][y] == 2) continue;
      if (g[x][y] == 4) {
        return step;
      }
      vis[x][y] = 1;
      q.push(node(x, y, step));
    }
  }
  return 0;
}

int main() {
  n = read(), m = read(), m1 = read(), m2 = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      g[i][j] = read();
    }
  }

  dx.push_back(m1); dy.push_back(m2);
  dx.push_back(m1); dy.push_back(-m2);
  dx.push_back(-m1); dy.push_back(m2);
  dx.push_back(-m1); dy.push_back(-m2);
  dx.push_back(m2); dy.push_back(m1);
  dx.push_back(m2); dy.push_back(-m1);
  dx.push_back(-m2); dy.push_back(m1);
  dx.push_back(-m2); dy.push_back(-m1);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (g[i][j] == 3) {
        cout << bfs(i, j) << endl;
      }
    }
  }
  return 0;
}

// 八个方向
// 

/**
 * 链接：https://ac.nowcoder.com/acm/contest/924/F
来源：牛客网

跳跃
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述
Farmer John为了满足奶牛对美的享受而安装了人工湖。矩形的人工湖分成M行N列(1 <= M <= 30; 1 <= N <= 30)的方形小格子。有些格子有美丽的荷叶，有些有岩石，剩下的格子有的只是美丽的蓝色湖水。
Bessie通过从一片荷叶跳到另一片荷叶上来练习芭蕾。它现在正站在一片荷叶上（看输入数据了解具体位置）。它希望通过在荷叶上跳跃来到达另一片荷叶。它既不能跳到水里也不能跳到岩石上。
只有新手才会感到吃惊：Bessie的跳跃有点类似国际象棋中马那样的移动，在一个方向上移动M1(1 <= M1 <= 30)“格”，然后再在斜方向上移动M2 (1 <= M2 <= 30; M1 != M2)格（或者也许在一个方向上移动M2格，然后在斜方向上移动M1格）。Bessie有时可能有多达8中的跳跃选择。
给出池塘的构造以及Bessie跳跃的形式，找出Bessie从一个位置移动到另一个位置所需的最小的跳跃次数。这个跳跃对于所给的测试数据总是可能的。
输入描述:
第 1 行: 四个空格分开的整数： M, N, M1, 和 M2
第 2 至 M+1行: 第i+1行用N个空格分开的整数描述池塘第i行，0表示水，1表示 荷叶，2表示岩石，3表示Bessie现在站的那块荷叶，4表示跳跃的 终点。
输出描述:
第 1 行: 一个整数，是Bessie从一块荷叶跳到另一块荷叶所需的最小的跳跃数。
示例1
输入
复制
4 5 1 2
1 0 1 0 1
3 0 2 0 4
0 1 2 0 0
0 0 0 1 0
输出
复制
2
说明
Bessie在第二行的左边开始；她的目的地在第二行的右边。池塘中有几块荷叶和岩石。
Bessie聪明的跳到了(1,3)的荷叶上，再跳到目的地。
 */
