#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;
const ll  INF = 0x3f3f3f3f3f3f3f3f;
int x[maxn], y[maxn];
int n, sx, sy;
int pd(int xx, int yy, int x1, int y1) {
  // xx-=sx;yy-=sy;x1-=sx;y1-=sy;
  // if(xx>=0&&x1>=0){
  //     if(yy>=0&&y1>=0)return 1;
  //     else if(yy<=0&&y1<=0)return 1;
  // }
  // if(xx<=0&&x1<=0){
  //     if(yy>=0&&y1>=0)return 1;
  //     else if(yy<=0&&y1<=0)return 1;
  // }
  if (abs(x1 - sx) + abs(y1 - sy) ==
      abs(xx - x1) + abs(yy - y1) + abs(xx - sx) + abs(yy - sy)) return 1;


  return 0;
}

int main() {
  scanf("%d%d%d", &n, &sx, &sy);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  int ans = 0, ansx, ansy;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int num = 0;
      int xx = sx + i, yy = sy + j;
      if ((xx == sx) && (yy == sy)) continue;
      for (int k = 0; k < n; k++) {
        if (pd(xx, yy, x[k], y[k])) num++;
      }
      // cout<<i<<" "<<j<<" "<<num<<endl;
      if (num > ans) ans = num, ansx = xx, ansy = yy;
    }
  }
  cout << ans << endl;
  cout << ansx << " " << ansy << endl;



  return 0;
}