#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

using i64 = long long;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   const int N = 9;
   i64 ans = 0, lim = 1;
   for (int n = 1; n <= N; ++n) {
      lim *= 10;
      i64 lim_sq = 1LL * lim * lim;
      for (i64 d = 1; d <= lim; ++d) {
         if (lim_sq % d == 0) {
            i64 shared = gcd(d + lim, lim_sq / d + lim);
            for (i64 p = 1; p * p <= shared; ++p) {
               if (shared % p == 0) {
                  ans += 2;
               }
            }
         }
      }
   }
   cout << ans << '\n';
}
