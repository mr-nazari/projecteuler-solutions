#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

using i64 = long long;

int ctoi(char c) {
   return c - '0';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   string current = "9876543210";
   int len = (int) current.size();
   do {
      bool found = false;
      for (int split = 1; split < len && !found; ++split) {
         if (current[0] == '0' || current[split] == '0') {
            continue;
         }
         int left = stoi(current.substr(0, split));
         int right = stoi(current.substr(split));
         int shared = gcd(left, right);
         for (int div = 1; div * div <= shared; ++div) {
            if (shared % div == 0) {
               int p = div, q = shared / div;
               auto is_pandigital = [&](string& s) {
                  vector<bool> exists(len);
                  for (char c : s) {
                     exists[ctoi(c)] = true;
                  }
                  return all_of(exists.begin(), exists.end(), [&](bool b) { return b; });
               };
               auto check = [&](int factor) {
                  string concatenate = (
                     to_string(factor) +
                     to_string(left / factor) +
                     to_string(right / factor)
                  );
                  if ((int) concatenate.size() == len &&
                      is_pandigital(concatenate)) {
                     return true;
                  }
                  return false;
               };
               if (check(p) || check(q)) {
                  found = true;
                  break;
               } 
            }
         }
      }
      if (found) {
         cout << current << '\n';
         break;
      }
   } while (prev_permutation(current.begin(), current.end()));
}
