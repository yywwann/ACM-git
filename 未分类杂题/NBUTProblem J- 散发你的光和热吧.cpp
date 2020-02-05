#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>       //    ____   _   _  __   __
using namespace std;       //   / ___| | | | | \ \ / /
#define ll long long       //  | |     | |_| |  \ V /
const ll INF = 0x3f3f3f3f; //  | |___  |  _  |   | |
const ll N   = 1e5 + 5;    //   \____| |_| |_|   |_|
const ll MOD = 1e9 + 7;
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

const double PI = acos(-1.0);
double torad(double deg) {
  return deg / 180 * PI;
}

struct Point
{
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator+(const Vector& A, const Vector& B) {
  return Vector(A.x + B.x, A.y + B.y);
}

Vector operator-(const Point& A, const Point& B) {
  return Vector(A.x - B.x, A.y - B.y);
}

Vector operator*(const Vector& A, double p) {
  return Vector(A.x * p, A.y * p);
}

Vector operator/(const Vector& A, double p) {
  return Vector(A.x / p, A.y / p);
}

bool operator<(const Point& a, const Point& b) // 结构体运算符的重载
{
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const double eps = 1e-8;
int dcmp(double x) {
  if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
} // 判断double 的正负

bool operator==(const Point& a, const Point& b)
{
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

// 基本运算：
double dist(const Vector& A, const Vector& B) {
  return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

double Dot(const Vector& A, const Vector& B) {
  return A.x * B.x + A.y * B.y;
} // 点积

double Length(const Vector& A) {
  return sqrt(Dot(A, A));
}

double Angle(const Vector& A, const Vector& B) {
  return acos(Dot(A, B) / Length(A) / Length(B));
}

double Cross(const Vector& A, const Vector& B) {
  return A.x * B.y - A.y * B.x;
} // 叉积

double Area2(Point A, Point B, Point C) {
  return Cross(B - A, C - A);
}

// 向量旋转 rad是弧度
Vector Rotate(const Vector& A, double rad)
{
  return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

// 点和直线：
// 两直线的交点
Point GetLineIntersection(const Point& P,
                          const Point& v,
                          const Point& Q,
                          const Point& w)
{
  Vector u = P - Q;
  double t = Cross(w, u) / Cross(v, w);

  return P + v * t;
}

// 点到直线的距离
double DistanceToLine(const Point& P, const Point& A, const Point& B)
{
  Vector v1 = B - A, v2 = P - A;

  return fabs(Cross(v1, v2)) / Length(v1);
}

// 点到线段的距离
double DistanceToSegment(const Point& P, const Point& A, const Point& B)
{
  if (A == B) return Length(P - A);

  Vector v1 = B - A, v2 = P - A, v3 = P - B;

  if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
  else if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
  else return fabs(Cross(v1, v2)) / Length(v1);
}

// 点在直线上的投影
Point GetLineProjection(const Point& P, const Point& A, const Point& B)
{
  Vector v = B - A;

  return A + v * (Dot(v, P - A) / Dot(v, v));
}

// 判断点在线段上(两个端点除外)
bool OnSegment(const Point& p, const Point& a1, const Point& a2)
{
  return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

// 线段相交判定
bool SegmentProperIntersection(const Point& a1,
                               const Point& a2,
                               const Point& b1,
                               const Point& b2)
{
  double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
         c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);

  if (!dcmp(c1) || !dcmp(c2) || !dcmp(c3) || !dcmp(c4)) {
    bool f1 = OnSegment(b1, a1, a2);
    bool f2 = OnSegment(b2, a1, a2);
    bool f3 = OnSegment(a1, b1, b2);
    bool f4 = OnSegment(a1, b1, b2);
    bool f  = (f1 | f2 | f3 | f4);
    return f;
  }
  return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

int    n, m;
Point  p[1005];
Vector lx[1005], ly[1005];
int    vis[1005];
int main() {
  for (int _ = read(); _; _--) {
    Point zero;
    zero.x = zero.y = 0;
    n      = read(); m = read();

    for (int i = 1; i <= n; i++) p[i].x = read(), p[i].y = read(), vis[i] = 0;

    for (int i = 1; i <= m;
         i++) lx[i].x = read(), lx[i].y = read(), ly[i].x = read(),
      ly[i].y         = read();
    double ans = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (SegmentProperIntersection(zero, p[i], lx[j], ly[j])) {
          ans   += dist(zero, p[i]);
          vis[i] = 1;
          break;
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      if (vis[i] == 1) continue;

      for (int j = 1; j <= n; j++) {
        if (i == j) continue;

        if (OnSegment(p[j], zero, p[i])) {
          ans += dist(zero, p[i]);
          break;
        }
      }
    }
    printf("%.2f\n", ans);
  }
  return 0;
}
