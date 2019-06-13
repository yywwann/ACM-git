#include <bits/stdc++.h>
using namespace std;

string a[150],b[150],c[150];

int main() {
  freopen("/Users/cccccccccchy/Desktop/NBUT2019 校赛/账号密码/in.txt", "r", stdin);
  freopen("/Users/cccccccccchy/Desktop/NBUT2019 校赛/账号密码/out.txt", "w", stdout);
  for(int i = 0; i < 120; i++) {
    cin >> a[i] >> b[i] >> c[i];
    cout << "名称\t" << "账号\t" << "密码" << endl;
    cout << a[i] << '\t' << b[i] << '\t' << c[i] << endl;
    // cout << b[i] << endl;
  }
}
