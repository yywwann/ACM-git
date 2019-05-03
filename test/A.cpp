#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, flag = 7, flap;
  int a[8], b[8];
  cin >> T;
  while (T--) {
    while (flag) {
      flap = 0, flag = 7;
      for (int i = 1; i <= 7; i++)
        cin >> a[i];
      for (int i = 1; i <= 7; i++)
        cin >> b[i];
      for (int i = 1; i <= 7; i++) {
        if (b[i] == 0)
          flag--;
        if (b[i] == 1 || b[i] == 2)
          b[i] += 4;
        if (b[i] == 3)
          b[i] -= 2;
        if (b[i] == 4)
          b[i]--;
        if (a[i] == 0)
          flap++;
        if (a[i] == 1 || a[i] == 2)
          a[i] += 4;
        if (a[i] == 3)
          a[i] -= 2;
        if (a[i] == 4)
          a[i]--;
      }
      if (flap == 0) {
        cout << "NO" << endl;
        break;
      } else if (flap >= 1) {
        int flay = 0;
        while (!flay) {
          flag = 7;
          flap = 7;
          for (int i = 1; i <= 7; i++) {
            a[i] -= 2;
            b[i] -= 2;
          }
          for (int i = 1; i <= 7; i++) {
            if (b[i] == 0)
              flag--;
            if (a[i] == 0)
              flap--;
          }
          if (flag == 7 && flap == 7) {
            flay = 1;
          }
        }
      }
      flag = 7;
      for (int i = 1; i <= 7; i++) {
        if (b[i] <= 0)
          flag--;
      }
      if (flag != 0) {
        cout << "NO" << endl;
        break;
      }
    }
    if (flag == 0)
      cout << "YES" << endl;
    flag = 7;
  }
}
