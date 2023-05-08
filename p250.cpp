#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

using i64 = long long;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   auto modpow = [&](i64 a, i64 b, i64 m) {
      a %= m;
      i64 ret = 1;
      while (b > 0) {
         if (b & 1) {
            ret *= a;
            ret %= m;
         }
         a *= a;
         a %= m;
         b >>= 1;
      }
      return ret;
   };
   const int N = 250250, M = 250;
   const i64 MOD = (i64) 1e16;
   vector<int> A(N + 1);
   for (int i = 1; i <= N; ++i) {
      A[i] = modpow(i, i, M);
   }
   vector dp(N + 1, vector<i64>(M));
   dp[0][0] = 1;
   for (int i = 1; i <= N; ++i) {
      for (int j = 0; j < M; ++j) {
         dp[i][j] = dp[i - 1][j] + dp[i - 1][(j - A[i] + M) % M];
         dp[i][j] %= MOD;
      }
   }
   cout << dp[N][0] - 1 << '\n';
}
