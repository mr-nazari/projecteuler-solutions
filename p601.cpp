#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

using i64 = long long;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   i64 ans = 0;
   i64 p, q;
   p = q = 1;
   for (int i = 1; i <= 31; ++i) {
      p *= 4, q = lcm(q, i);
      ans += (p - 2) / q - (p - 2) / lcm(q, i + 1);
   }
   cout << ans << '\n';
}
