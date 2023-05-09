#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

using i64 = long long;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   auto binpow = [&](int a, int b) {
      int ret = 1;
      while (b > 0) {
         if (b & 1) {
            ret *= a;
         }
         a *= a;
         b >>= 1;
      }
      return ret;
   };
   const int N = (int) 1e8;
   vector<int> spf(N + 1);
   for (int i = 2; i <= N; ++i) {
      if (spf[i]) {
         continue;
      }
      for (int j = i; j <= N; j += i) {
         if (spf[j]) {
            continue;
         }
         spf[j] = i;
      }
   }
   i64 sum = 0;
   for (int n = 2; n <= N; ++n) {
      map<int, int> factors;
      int x = n;
      while (x > 1) {
         factors[spf[x]] += 1;
         x /= spf[x];
      }
      int res = 0;
      for (auto& [key, value] : factors) {
         int power = binpow(key, value);
         // --- BEGIN ---
         // NOTE: can be optimized by caching
         i64 fctrl = key;
         int coeff = key;
         while (fctrl % power != 0) {
            coeff += key;
            fctrl *= coeff;
            fctrl %= power;
         }
         // -- END ---
         res = max(res, coeff);
      }
      sum += res;
   }
   cout << sum << '\n';
}
