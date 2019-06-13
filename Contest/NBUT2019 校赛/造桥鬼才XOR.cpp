#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, vis[505][505];
char pic[505][505];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct node {
  int x, y, step;
  node(int x, int y, int step) {
    this->x = x;
    this->y = y;
    this->step = step;
  }
  friend bool operator < (node a, node b) {
    return a.step > b.step; // step小的优先
  }
};


int bfs(int sx, int sy) {
  priority_queue<node>q;
  vis[sx][sy] = 1;
  q.push(node(sx, sy, 0));
  //int t = 0;
  while (!q.empty()) {
    node u = q.top();
    q.pop();
    //t++;
    for (int i = 0; i < 4; i++) {
      int x = u.x + dx[i];
      int y = u.y + dy[i];
      int s = u.step;

      if (x < 1 || x > n || y < 1 || y > m || vis[x][y] == 1) continue;
      //cout << x << ' ' << y << ' ' << s << endl;
      vis[x][y] = 1;
      if (pic[u.x][u.y] != 'I' && pic[x][y] == 'I') {
        //cout << t << endl;
        return s;
      }
      else if (pic[x][y] == 'I' || pic[x][y] == 'S') {
        q.push(node(x, y, s));
      }
      else if (pic[x][y] == '.') {
        q.push(node(x, y, s+1));
      }
    }
  }
  //cout << t << endl;
  return 0;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", pic[i]+1);
      // for (int j = 1; j <= m; j++) {
      //   vis[i][j] = 0;
      // }
    }
    memset(vis, 0, sizeof(vis));
    //while (!q.empty()) q.pop();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int f = 0;
      for (int j = 1; j <= m; j++) {
        if (pic[i][j] == 'I') {
          ans = bfs(i, j);
          f = 1;
          break;
        }
      }
      if (f) break;
    }
    printf("%d\n", ans);

  }
}
