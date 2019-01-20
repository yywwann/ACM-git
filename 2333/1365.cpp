#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 100000 + 16;

int link_x[MAX_N], link_y[MAX_N];			// 垂直方向相连的顶点

struct Point
{
	int x, y;
	int id;
	int get(const bool& is_x)
	{
		return is_x ? x : y;
	}
	int get_link(const bool& is_x)
	{
		return is_x ? link_x[id] : link_y[id];
	}
	void link(const bool& is_x, const Point& to)
	{
		(is_x ? link_x[id] : link_y[id])	   = to.id;
		(is_x ? link_x[to.id] : link_y[to.id]) = id;
	}
}ps[MAX_N];

struct Line
{
	int x, y1, y2;
	Line(int x, int y1, int y2) :x(x), y1(y1), y2(y2){}
}ls[MAX_N];

bool is_x;
int cmp(Point& a, Point& b)
{
	int ax = a.get(is_x);
	int bx = b.get(is_x);
	int ay = a.get(!is_x);
	int by = b.get(!is_x);
	if (ax == bx) return ay < by;
	return ax < bx;
}

bool check_intersect(const Point& a, const Point& b, const int& ln)
{
	int y = a.y, x1 = a.x, x2 = b.x;
	for (int i = 0; i < ln; i++)
	{
		if (x1 < ls[i].x && x2 > ls[i].x && ls[i].y1 < y && ls[i].y2 > y)
			return true;
	}
	return false;
}

int M, N;
int traverse(int& ln)
{
	sort(ps, ps + N, cmp);
	int count_same_line = 1;
	int sum = 0;
	for (int i = 1; i < N; ++i)
	{
		if (ps[i].get(is_x) != ps[i - 1].get(is_x))
		{
			// 扫描线移动
			if (count_same_line & 1)
			{
				return -1;
			}
			count_same_line = 1;
		}
		else
		{
			// 同一条扫描线上的点遍历
			++count_same_line;
			if (!(count_same_line & 1))
			{
				sum += ps[i].get(!is_x) - ps[i - 1].get(!is_x);
				ps[i].link(is_x, ps[i - 1]);
				if (is_x)
				{
					// 横向扫描记录竖向直线
					ls[ln++] = Line(ps[i].x, ps[i - 1].y, ps[i].y);
				}
				else
				{
					// 竖向扫描检查是否相交
					if (check_intersect(ps[i - 1], ps[i], ln))
					{
						return -1;
					}
				}
			}
		}
	}
	return sum;
}

int solve()
{
	int ln = 0;
	is_x = true;
	int x = traverse(ln);
	if (x == -1) return -1;
	is_x = false;
	int y = traverse(ln);
	if (y == -1) return -1;
	int cur = 0;
	int link_count = 0;
	do
	{
		cur = is_x ? link_x[cur] : link_y[cur];
		is_x = !is_x;
		++link_count;
	} while (cur != 0);
	if (link_count != N)
	{
		return -1;
	}
	return x + y;
}

int main()
{
	scanf("%d", &M);
	while (M--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d%d", &ps[i].x, &ps[i].y);
			ps[i].id = i;
		}
		printf("%d\n", solve());
	}
	return 0;
}
