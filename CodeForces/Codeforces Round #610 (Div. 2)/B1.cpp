#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 5;
const ll  INF = 0x3f3f3f3f3f3f3f3f;
int t, n, k, p;
int a[maxn];
ll  ji[maxn], ou[maxn];
int check(int x) {
  if (x % 2 == 1) {
    // cout<<x<<" "<<ji[x]<<endl;
    if (p >= ji[x]) return 1;
    else return 0;
  }
  else {
    // cout<<x<<" "<<ou[x]<<endl;
    if (p >= ou[x]) return 1;
    else return 0;
  }
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);

    ji[1] = a[1]; for (int i = 3; i <= n; i += 2) ji[i] = a[i] + ji[i - 2];
    ou[2] = a[2]; for (int i = 4; i <= n; i += 2) ou[i] = a[i] + ou[i - 2];

    // for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)cout<<ji[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)cout<<ou[i]<<" ";
    // cout<<endl;

    int min = 0, max = n;
    while (min <= max)
    {
      int mid = (min + max) / 2;
      if (check(mid)) min = mid + 1;
      else max = mid - 1;
    }
    printf("%d\n", max);
  }

  return 0;
}

/*
   6
   5 6 2
   2 4 3 5 7

 */