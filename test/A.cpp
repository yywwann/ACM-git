#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int  L, R, C;
int  ans, flag;
int  vis[40][40][40];
int  dx[] = { 0, 0, 1, -1, 0, 0 };
int  dy[] = { 1, -1, 0, 0, 0, 0 };
int  dz[] = { 0, 0, 0, 0, 1, -1 };
char s[40][40][40];
void dfs(int x, int y, int z)
{
  cout << x << " " << y << " " << z << endl;
  vis[x][y][z] = 1;
  if (s[x][y][z] == 'E')
  {
    cout << "Find" << endl;
    flag = 1;
    cout << x << " " << y << " " << z << endl;
    return;
  }
  for (int i = 0; i < 6; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    int nz = z + dz[i];
    if ((nx >= 0) && (ny >= 0) && (nz >= 0) && (nx < L)
        && (ny < R) && (nz < C) && (s[nx][ny][nz] == '.')
        && (vis[nx][ny][nz] == 0))
    {
      cout << "QAQ" << endl;
      dfs(nx, ny, nz);
      ans++;
    }
  }
}

int main()
{
  while (cin >> L >> R >> C)
  {
    flag = 0;
    ans  = 0;
    memset(vis, 0, sizeof(vis));
    if ((L == 0) && (R == 0) && (C == 0)) break;
    for (int i = 0; i < L; i++)
    {
      for (int j = 0; j < R; j++)
      {
        for (int z = 0; z < C; z++)
        {
          cin >> s[i][j][z];
        }
      }
    }
    for (int i = 0; i < L; i++)
    {
      for (int j = 0; j < R; j++)
      {
        for (int z = 0; z < C; z++)
        {
          if (s[i][j][z] == 'S')
          {
            cout << "QWQ" << endl;
            ans++;
            dfs(i, j, z);
          }
        }
      }
    }
    if (flag == 1) cout << "Escaped in " << ans << " minute(s)." << endl;
    else cout << "Trapped!" << endl;
  }
  return 0;
}