#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;       //    ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 0x3f3f3f3f; //    | |     |  _  |  \ V /
const ll N   = 1e5 + 5;    //     | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //       \____| |_| |_|   |_|
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x  = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

ll n, m, k, a, b, c;

ll res;

ll f1(ll boy, ll girl, ll fff) {
  ll ans = 0;

  ans += fff * c;

  while (boy) {
    if (boy == 6) {
      boy  = 0;
      ans += min(2 * b, min(3 * a, 2 * a + b));
    } else if (boy == 5) {
      boy  = 0;
      ans += min(2 * b, min(3 * a, a + b));
    } else if (boy == 4) {
      boy  = 0;
      ans += min(2 * b, min(2 * a, a + b));
    } else if (boy == 3) {
      boy  = 0;
      ans += min(2 * a, b);
    } else if (boy <= 2) {
      boy  = 0;
      ans += min(a, b);
    }

    if (boy == 0) break;
    boy -= 2;
    ans += a;
  }

  while (girl) {
    if (girl == 6) {
      girl = 0;
      ans += min(2 * b, min(3 * a, 2 * a + b));
    } else if (girl == 5) {
      girl = 0;
      ans += min(2 * b, min(3 * a, a + b));
    } else if (girl == 4) {
      girl = 0;
      ans += min(2 * b, min(2 * a, a + b));
    } else if (girl == 3) {
      girl = 0;
      ans += min(2 * a, b);
    } else if (girl <= 2) {
      girl = 0;
      ans += min(a, b);
    }

    if (girl == 0) break;
    girl -= 2;
    ans  += a;
  }

  return ans;
}

ll f2(ll boy, ll girl, ll fff) {
  ll ans = 0;

  ans += fff * c;

  while (boy) {
    if (boy == 6) {
      boy  = 0;
      ans += min(2 * b, min(3 * a, 2 * a + b));
    } else if (boy == 5) {
      boy  = 0;
      ans += min(2 * b, min(3 * a, a + b));
    } else if (boy == 4) {
      boy  = 0;
      ans += min(2 * b, min(2 * a, a + b));
    } else if (boy == 3) {
      boy  = 0;
      ans += min(2 * a, b);
    } else if (boy <= 2) {
      boy  = 0;
      ans += min(a, b);
    }

    if (boy == 0) break;
    boy -= 3;
    ans += b;
  }

  while (girl) {
    if (girl == 6) {
      girl = 0;
      ans += min(2 * b, min(3 * a, 2 * a + b));
    } else if (girl == 5) {
      girl = 0;
      ans += min(2 * b, min(3 * a, a + b));
    } else if (girl == 4) {
      girl = 0;
      ans += min(2 * b, min(2 * a, a + b));
    } else if (girl == 3) {
      girl = 0;
      ans += min(2 * a, b);
    } else if (girl <= 2) {
      girl = 0;
      ans += min(a, b);
    }

    if (girl == 0) break;
    girl -= 3;
    ans  += b;
  }

  return ans;
}

int main() {
  for (int _ = read(); _; _--) {
    cin >> n >> m >> k >> a >> b >> c;
    res = 2e18;
    ll boy, girl, fff;

    for (int i = 0; i <= k; i++) {
      boy  = n + i;
      girl = m + i;
      fff  = k - i;
      res  = min(res, min(f1(boy, girl, fff), f2(boy, girl, fff)));
    }
    cout << res << endl;

    // 0
    // boy = n + k;
    // girl = m + k;
    // while (boy) {
    //   if (boy == 5) {
    //     boy = 0;
    //     ans[0] += min(2 * b, min(3 * a, a + b));
    //   } else if (boy == 4) {
    //     boy = 0;
    //     ans[0] += min(2 * b, min(2 * a, a + b));
    //   } else if (boy == 3) {
    //     boy = 0;
    //     ans[0] += min(2 * a, b);
    //   } else if (boy <= 2) {
    //     boy = 0;
    //     ans[0] += min(a, b);
    //   }
    //   if (boy == 0) break;
    //   boy -= 2;
    //   ans[0] += a;
    // }
    // while (girl) {
    //   if (girl == 5) {
    //     girl = 0;
    //     ans[0] += min(2 * b, min(3 * a, a + b));
    //   } else if (girl ==4) {
    //     girl = 0;
    //     ans[0] += min(2 * b, min(2 * a, a + b));
    //   } else if (girl == 3) {
    //     girl = 0;
    //     ans[0] += min(2 * a, b);
    //   } else if (girl <= 2) {
    //     girl = 0;
    //     ans[0] += min(a, b);
    //   }
    //   if (girl == 0) break;
    //   girl -= 2;
    //   ans[0] += a;
    // }
    //
    // // 1
    // boy = n + k;
    // girl = m + k;
    // while (boy) {
    //   if (boy == 5) {
    //     boy = 0;
    //     ans[1] += min(2 * b, min(3 * a, a + b));
    //   } else if (boy == 4) {
    //     boy = 0;
    //     ans[1] += min(2 * b, min(2 * a, a + b));
    //   } else if (boy == 3) {
    //     boy = 0;
    //     ans[1] += min(2 * a, b);
    //   } else if (boy <= 2) {
    //     boy = 0;
    //     ans[1] += min(a, b);
    //   }
    //   if (boy == 0) break;
    //   boy -= 3;
    //   ans[1] += b;
    // }
    // while (girl) {
    //   if (girl == 5) {
    //     girl = 0;
    //     ans[1] += min(2 * b, min(3 * a, a + b));
    //   } else if (girl == 4) {
    //     girl = 0;
    //     ans[1] += min(2 * b, min(2 * a, a + b));
    //   } else if (girl == 3) {
    //     girl = 0;
    //     ans[1] += min(2 * a, b);
    //   } else if (girl <= 2) {
    //     girl = 0;
    //     ans[1] += min(a, b);
    //   }
    //   if (girl == 0) break;
    //   girl -= 3;
    //   ans[1] += b;
    // }
    //
    // // 2
    // boy = n;
    // girl = m;
    // ans[2] += k * c;
    // while (boy) {
    //   if (boy == 5) {
    //     boy = 0;
    //     ans[2] += min(2 * b, min(3 * a, a + b));
    //   } else if (boy == 4) {
    //     boy = 0;
    //     ans[2] += min(2 * b, min(2 * a, a + b));
    //   } else if (boy == 3) {
    //     boy = 0;
    //     ans[2] += min(2 * a, b);
    //   } else if (boy <= 2) {
    //     boy = 0;
    //     ans[2] += min(a, b);
    //   }
    //   if (boy == 0) break;
    //   boy -= 2;
    //   ans[2] += a;
    // }
    // while (girl) {
    //   if (girl == 5) {
    //     girl = 0;
    //     ans[2] += min(2 * b, min(3 * a, a + b));
    //   } else if (girl == 4) {
    //     girl = 0;
    //     ans[2] += min(2 * b, min(2 * a, a + b));
    //   } else if (girl == 3) {
    //     girl = 0;
    //     ans[2] += min(2 * a, b);
    //   } else if (girl <= 2) {
    //     girl = 0;
    //     ans[2] += min(a, b);
    //   }
    //   if (girl == 0) break;
    //   girl -= 2;
    //   ans[2] += a;
    // }
    //
    // // 3
    // boy = n;
    // girl = m;
    // ans[3] += k * c;
    // while (boy) {
    //   if (boy == 5) {
    //     boy = 0;
    //     ans[3] += min(2 * b, min(3 * a, a + b));
    //   } else if (boy == 4) {
    //     boy = 0;
    //     ans[3] += min(2 * b, min(2 * a, a + b));
    //   } else if (boy == 3) {
    //     boy = 0;
    //     ans[3] += min(2 * a, b);
    //   } else if (boy <= 2) {
    //     boy = 0;
    //     ans[3] += min(a, b);
    //   }
    //   if (boy == 0) break;
    //   boy -= 3;
    //   ans[3] += b;
    // }
    // while (girl) {
    //   if (girl == 5) {
    //     girl = 0;
    //     ans[3] += min(2 * b, min(3 * a, a + b));
    //   } else if (girl == 4) {
    //     girl = 0;
    //     ans[3] += min(2 * b, min(2 * a, a + b));
    //   } else if (girl == 3) {
    //     girl = 0;
    //     ans[3] += min(2 * a, b);
    //   } else if (girl <= 2) {
    //     girl = 0;
    //     ans[3] += min(a, b);
    //   }
    //   if (girl == 0) break;
    //   girl -= 3;
    //   ans[3] += b;
    // }
    //
    // ll fff;
    // // 4
    // boy = n;
    // girl = m;
    // fff = k;
    // while (boy - 2 >= 5) {
    //   boy -= 2;
    //   ans[4] += a;
    // }
    // while (girl - 2 >= 5) {
    //   girl -= 2;
    //   ans[4] += a;
    // }
    // while (fff > 1) {
    //   fff--;
    //   ans[4] += c;
    // }
    // if (fff) girl++, boy++;
    // if (boy <= 2) ans[4] += min(a, b);
    // if (boy == 3) ans[4] += min(2 * a, b);
    // if (boy == 4) ans[4] += min(2 * b, min(2 * a, a + b));
    // if (boy == 5) ans[4] += min(2 * b, min(3 * a, a + b));
    // if (boy == 6) ans[4] += min(2 * b, min(3 * a, 2 * a + b));
    // if (girl <= 2) ans[4] += min(a, b);
    // if (girl == 3) ans[4] += min(2 * a, b);
    // if (girl == 4) ans[4] += min(2 * b, min(2 * a, a + b));
    // if (girl == 5) ans[4] += min(2 * b, min(3 * a, a + b));
    // if (girl == 6) ans[4] += min(2 * b, min(3 * a, 2 * a + b));
    //
    // // 5
    // boy = n;
    // girl = m;
    // fff = k;
    // while (boy - 3 >= 5) {
    //   boy -= 3;
    //   ans[5] += b;
    // }
    // while (girl - 3 >= 5) {
    //   girl -= 3;
    //   ans[5] += b;
    // }
    // while (fff > 1) {
    //   fff--;
    //   ans[5] += c;
    // }
    // if (fff) girl++, boy++;
    // if (boy <= 2) ans[5] += min(a, b);
    // if (boy == 3) ans[5] += min(2 * a, b);
    // if (boy == 4) ans[5] += min(2 * b, min(2 * a, a + b));
    // if (boy == 5) ans[5] += min(2 * b, min(3 * a, a + b));
    // if (boy == 6) ans[5] += min(2 * b, min(3 * a, 2 * a + b));
    // if (girl <= 2) ans[5] += min(a, b);
    // if (girl == 3) ans[5] += min(2 * a, b);
    // if (girl == 4) ans[5] += min(2 * b, min(2 * a, a + b));
    // if (girl == 5) ans[5] += min(2 * b, min(3 * a, a + b));
    // if (girl == 6) ans[5] += min(2 * b, min(3 * a, 2 * a + b));
    //
    // // 6
    // boy = n;
    // girl = m;
    // fff = k;
    // while (boy - 2 >= 5) {
    //   boy -= 2;
    //   ans[4] += a;
    // }
    // while (girl - 2 >= 5) {
    //   girl -= 2;
    //   ans[4] += a;
    // }
    // while (fff > 2) {
    //   fff--;
    //   ans[4] += c;
    // }
    // if (fff) girl += 2, boy += 2;
    // if (boy <= 2) ans[6] += min(a, b);
    // if (boy == 3) ans[6] += min(2 * a, b);
    // if (boy == 4) ans[6] += min(2 * b, min(2 * a, a + b));
    // if (boy == 5) ans[6] += min(2 * b, min(3 * a, a + b));
    // if (boy == 6) ans[6] += min(2 * b, min(3 * a, 2 * a + b));
    // if (boy == 7)
    // if (girl <= 2) ans[6] += min(a, b);
    // if (girl == 3) ans[6] += min(2 * a, b);
    // if (girl == 4) ans[6] += min(2 * b, min(2 * a, a + b));
    // if (girl == 5) ans[6] += min(2 * b, min(3 * a, a + b));
    // if (girl == 6) ans[6] += min(2 * b, min(3 * a, 2 * a + b));
    //
    // // 7
    // boy = n;
    // girl = m;
    // fff = k;
    // while (boy - 3 >= 5) {
    //   boy -= 3;
    //   ans[5] += b;
    // }
    // while (girl - 3 >= 5) {
    //   girl -= 3;
    //   ans[5] += b;
    // }
    // while (fff > 2) {
    //   fff--;
    //   ans[5] += c;
    // }
    // if (fff) girl += 2, boy += 2;
    // if (boy <= 2) ans[5] += min(a, b);
    // if (boy == 3) ans[5] += min(2 * a, b);
    // if (boy == 4) ans[5] += min(2 * b, min(2 * a, a + b));
    // if (boy == 5) ans[5] += min(2 * b, min(3 * a, a + b));
    // if (boy == 6) ans[5] += min(2 * b, min(3 * a, 2 * a + b));
    // if (girl <= 2) ans[5] += min(a, b);
    // if (girl == 3) ans[5] += min(2 * a, b);
    // if (girl == 4) ans[5] += min(2 * b, min(2 * a, a + b));
    // if (girl == 5) ans[5] += min(2 * b, min(3 * a, a + b));
    // if (girl == 6) ans[5] += min(2 * b, min(3 * a, 2 * a + b));
    // ll res = 2e18;
    // for (int i = 0; i < 6; i++) res = min(res, ans[i]);
    // cout << res << endl;
  }
  return 0;
}
