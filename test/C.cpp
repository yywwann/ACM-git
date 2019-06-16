#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |  \ V /
const ll N   = 1e5 + 5;    //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    \____| |_| |_|   |_|
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

int n, m, m1, m2;
int g[50][50];
int vis[50][50];
vector<int> dx, dy;

struct node {
  int x, y, step;
  node(int x, int y, int step) {
    this->x    = x;
    this->y    = y;
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
      int x    = u.x + dx[i];
      int y    = u.y + dy[i];
      int step = u.step + 1;

      if ((x < 1) || (x > n) || (y < 1) || (y > m)) continue;

      if ((vis[x][y] == 1) || (g[x][y] == 0) || (g[x][y] == 2)) continue;

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
