#include <cstdio>
#include <algorithm>
using namespace std;

bool ff;
int  T;
long long a, b, ans;
int main()
{
  scanf("%d", &T);
  while (T--)
  {
    scanf("%lld%lld", &a, &b);
    ans = 0;
    ff  = 0;
    while (b) {
      ans++;
      if (b % 10 != 9) ff = 1;
      b /= 10;
    }
    if (ff) ans--;
    printf("%lld\n", max(0ll, ans * a));
  }
}